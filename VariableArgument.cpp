#include "VariableArgument.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <fstream>
#include "Greska.h"
using namespace std;
VariableArgument::VariableArgument(string commandLine) : DataProcess(commandLine) {

}
void VariableArgument::pStdoutRedirection(string argument, string output) {
    if (output[0] == '>') {
        output.erase(0, 1);
        ofstream file(output, std::ios::out | std::ios::app);  // Otvaramo fajl za dodavanje na kraj
        if (file) {
            file << argument;  // Dodajemo tekst na kraj fajla
            file.close();
        }
        else {
            throw GNijeMoguceOtvoritiFajlDodavanjeTeksta();
        }
    }
    else {
        ofstream file(output, ios::out | ios::trunc);
        if (file) {
            file << argument;
            file.close();
        }
        else {
            throw GNijeMoguceOtvoritiFajlPisanjeTeksta();
        }
    }
}

void VariableArgument::helperOutputRedirection(string& output) {
    getStream().get();
    if (getStream().peek() == '>') {
        getStream() >> output;
        getStream() >> ws;
        string temp = "";
        getStream() >> temp;
        output += temp;
    }
    getStream() >> ws;
    if (getStream().peek() == '>')throw GRazmakIzmedjuDvostrukogZnakaVece();
    getStream() >> output;
}



void VariableArgument::pFile(string& dataNum) {
    this->getStream() >> dataNum;
    pFileReadingInformation(dataNum);
    getStream() >> ws;
}

void VariableArgument::pFileReadingInformation(string& dataNum) {
    ifstream file(dataNum);
    if (file) {
        string line, nextLine;
        dataNum = "";
        if (getline(file, line)) {
            while (getline(file, nextLine)) {
                dataNum += line + "\n";
                line = nextLine;
            }
            dataNum += line;
        }
        file.close();
    }
    else {
        throw GFajlNijePronadjen();
    }
}

void VariableArgument::outputPrint(const string& argument, string& output) {
    if (output != "") {
        pStdoutRedirection(argument, output);
    }
    else if (output == "") {
        //ispis je na standardom izlazu
        cout << argument << endl;
    }
    else {
        throw GNeispravanUnosArgumenta();//komandna linije nije ispravno zadata
    }
}


void VariableArgument::processRedirectionOnlyInput(string& dataNum) {
    getStream() >> ws;
    if (dataNum == "__UNSET__") {
        if (this->getStream().peek() == '<') {
            pStdinRedirection(dataNum);//ucitavanje naziva ulazne redirekcije i upisivanje teksta iz nje u prosledjen argument funkcije
            getStream() >> ws;
            if (getStream().peek() == '>') {
                throw GRedirekcijaIzlaznogToka();
            }
        }
        else if (this->getStream().peek() == '>') {
            throw GRedirekcijaIzlaznogToka();
        }
        else {
            pStdin(dataNum);
        }
    }
    else {//ukoliko postoji argument, ne moze postojati i ulazna redirekcija
        getStream() >> ws;
        if (!getStream().eof() && getStream().peek() == '<')throw GArgumentIUlaznaRedirekcija();
        else if (!getStream().eof() && getStream().peek() != '>')throw GNeispravanUnosArgumenta();
        if (getStream().peek() == '>') {
            throw GRedirekcijaIzlaznogToka();
        }
    }
}
void VariableArgument::pStdin(string& dataNum) {
    // Ako nema argumenata, unos se ocekuje sa tastature
    string unos;
    dataNum = "";
    while (true) {
        if (!getline(cin, unos)) {
            if (cin.eof()) {
                cin.clear();
                break;
            }
            else {
                cout << "Greska!" << endl;
                break;
            }
        }
        dataNum += unos + "\n";
    }
}

void VariableArgument::pStdinRedirection(string& dataNum) {
    getStream() >> ws;
    getStream().get();
    getStream() >> ws;
    this->getStream() >> dataNum;
    getStream() >> ws;
    if (!getStream().eof() && getStream().peek() != '>') {//ovde moze tajni test da pravi problem
        dataNum = "__UNSET__";
        throw GNeispravanUnosRedirekcije();
    }
    pFileReadingInformation(dataNum);
}

void VariableArgument::processArgument(string& dataNum) {
    if (this->getStream().peek() == '"') {
        pSentence(dataNum);
    }
    else if (this->getStream().peek() != EOF && this->getStream().peek() != '<' && this->getStream().peek() != '>') {
        pFile(dataNum);
    }
    else {
        dataNum = "__UNSET__";
    }
}
void VariableArgument::processOption(string& dataNum) {
    if (this->getStream().peek() == '"') {
        dataNum = "";
        throw GOpcijaSaNavodnicima();
    }
    else {
        this->getStream() >> dataNum;
    }
    getStream() >> ws;
}

void VariableArgument::processDeterminedRedirectionVariableArgument(string& argument, string& output){
    if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::NONE) {
        processRedirection(argument, output);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::START) {
        processRedirectionOnlyInput(argument);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::MIDDLE) {
        if (this->getStream().peek() != EOF) {
            cout << getStream().peek();
            throw GNeispravanUnosVariableArgument();
        }
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::END) {
        processRedirectionOnlyOutput(output); 
    }
}
void VariableArgument::passingInformation(string argument, string output) {
    if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::NONE) {
        if (argument!="__UNSET__") {
            outputPrint(argument, output);
        }   
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::START) {
        PipelineStatus::getInstance().setPipeTempInformation(argument);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::MIDDLE) {
        PipelineStatus::getInstance().setPipeTempInformation(argument);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::END) {
        PipelineStatus::getInstance().setPipePosition(PipelineStatus::PipePosition::NONE);
        if (argument != "__UNSET__") {
            outputPrint(argument, output);
        }
    }
}
void VariableArgument::processRedirection(string& dataNum, string& output) {
    if (dataNum == "__UNSET__") {
        if (this->getStream().peek() == '<') {
            pStdinRedirection(dataNum);
            getStream() >> ws;
            if (getStream().peek() == '>') {
                helperOutputRedirection(output);
            }
        }
        else if (this->getStream().peek() == '>') {
            helperOutputRedirection(output);
            if (getStream().peek() == '<') {
                pStdinRedirection(dataNum);
            }
            else {
                pStdin(dataNum);
            }

        }
        else {
            pStdin(dataNum);
        }


    }
    else {
        getStream() >> ws;
        if (!getStream().eof() && getStream().peek() == '<')throw GArgumentIUlaznaRedirekcija();
        else if(!getStream().eof()&& getStream().peek()!='>')throw GNeispravanUnosArgumenta();
        if (getStream().peek() == '>') {
            helperOutputRedirection(output);
            
        }
    }
}

void VariableArgument::processRedirectionOnlyOutput(string& output){
    getStream() >> ws;
    if (this->getStream().peek() == '>') {
        helperOutputRedirection(output);
        if (getStream().peek() == '<') {
            throw GRedirekcijaUlaznogToka();
        }
    }
    else if (this->getStream().peek() == '<') {
        throw GRedirekcijaUlaznogToka();
    }
    else if (getStream().eof())return;
    else {
        throw GNeispravanUnosArgumenta();
    }
}

