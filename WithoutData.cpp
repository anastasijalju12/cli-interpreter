#include "WithoutData.h"
#include <iostream>
#include <fstream>
using namespace std;
WithoutData::WithoutData(string command_line):Commands(command_line){
    this->command_line = command_line;
}
void WithoutData::processRedirectionOnlyOutput(string& output) {
    getStream() >> ws;
    if (this->getStream().peek() == '>') {
        helperGetOutputRedirectionName(output);
        if (getStream().peek() == '<') {
            throw GRedirekcijaUlaznogToka();
        }
    }
    else if (this->getStream().peek() == '<') {
        throw GRedirekcijaUlaznogToka();
    }
}
string WithoutData::getCommandLine() const
{
    return this->command_line;
}
void WithoutData::pStdoutRedirection(string argument, string output) {
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
void WithoutData::processDeterminedRedirectionWithoutData(string& output){
    {
        if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::NONE) {
            processRedirectionOnlyOutput(output);
            if (this->getStream().peek() != EOF) {
                isError();
            }
        }
        else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::START) {
            if (this->getStream().peek() != EOF and this->getStream().peek() != '>') {
                cout << getStream().peek();
                isError();
            }
        }
        else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::MIDDLE) {
            throw GNeispravanUnosPipeWithoutDataObjects();
            //isError();
        }
        else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::END) {
            //processRedirectionOnlyOutput(output); //sme samo redirekciju za output da ima
            throw GNeispravanUnosPipeWithoutDataObjects();
        }
    }
}

void WithoutData::helperGetOutputRedirectionName(string& output){
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


void WithoutData::print(string argument, string output) {
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
void WithoutData::transportInformation(string argument, string output) {//prekopirano
    if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::NONE) {
        print(argument, output);
    }

    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::START) {
        PipelineStatus::getInstance().setPipeTempInformation(argument);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::MIDDLE) {
        PipelineStatus::getInstance().setPipeTempInformation(argument);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::END) {
        print(argument, output);
    }
}