#include "CommandType.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "WithoutData.h"
#include "DataProcess.h"
#include "Date.h"
#include "Time.h"
#include "Wc.h"
#include "Echo.h"
#include "Touch.h"
#include "Tr.h"
#include "Head.h"
#include "Prompt.h"
#include "Truncate.h"
#include "Rm.h"
#include "Batch.h"
#include "Greska.h"
using namespace std;


CommandType::CommandType(string command_line){
    processCommandLine(command_line);
    this->isError(command_line);  
}

void CommandType::processCommandLine(string command_line) {
    pStream(command_line);
    pCommand();
    pAdditionalInformation();
}

void CommandType::pStream(string command_line) {
    (this->stream).str(command_line);
}

void CommandType::pCommand() {
    this->stream >> first;
}

void CommandType::pAdditionalInformation() {
    stream >> ws;
    if (PipelineStatus::getInstance().getPipePosition() != PipelineStatus::PipePosition::NONE) {
        string line;
        additionalInformation = "";
        while (getline(stream, line)) {
            additionalInformation += line + "\n";
        }
    }
    else {
        getline(stream, additionalInformation);
    }
    
}

int CommandType::objectMaking() {
    try {
        enum Command { date, time, echo, wc, touch, tr, head, prompt, truncate, rm, batch, exit};

        Command selectedCommand;
        if (first == "date") {
            selectedCommand = Command::date;
        }
        else if (first == "time") {
            selectedCommand = Command::time;
        }
        else if (first == "echo") {
            selectedCommand = Command::echo;
        }
        else if (first == "wc") {
            selectedCommand = Command::wc;
        }
        else if (first == "touch") {
            selectedCommand = Command::touch;
        }
        else if (first == "tr") {
            selectedCommand = Command::tr;
        }
        else if (first == "head") {
            selectedCommand = Command::head;
        }
        else if (first == "prompt") {
            selectedCommand = Command::prompt;
        }
        else if (first == "truncate") {
            selectedCommand = Command::truncate;
        }
        else if (first == "rm") {
            selectedCommand = Command::rm;
        }
        else if (first == "batch") {
            selectedCommand = Command::batch;
        }
        else if (first == "exit") {
            selectedCommand = Command::exit;
        }
        else {
            throw std::invalid_argument(first);
        }
        switch (selectedCommand) {
            case Command::exit: {
                return 1;
            }
            case Command::echo: {
                Echo* echo = new Echo(additionalInformation);
                delete echo;
                break;
            }
            case Command::date: {
                Date* current_date = new Date(additionalInformation);
                delete current_date;
                break;
            }
            case Command::time: {
                Time* current_time = new Time(additionalInformation);
            
                delete current_time;
                break;
            }
            case Command::touch: {
                Touch* touch = new Touch(additionalInformation);
                delete touch;
                break;
            }
            case Command::wc: {
                Wc* wc = new Wc(additionalInformation);
                delete wc;
                break;
            }
            case Command::tr: {
                Tr* tr = new Tr(additionalInformation);
                delete tr;
                break;

            }
            case Command::head: {
                Head* head = new Head(additionalInformation);
                delete head;
                break;
            }
            case Command::prompt: {
                Prompt* prompt = new Prompt(additionalInformation);
                delete prompt;
                break;
            }
            case Command::truncate: {
                Truncate* truncate = new Truncate(additionalInformation);
                delete truncate;
                break;
            }
            case Command::rm: {
                Rm* rm = new Rm(additionalInformation);
                delete rm;
                break;
            }
            case Command::batch: {
                Batch* batch = new Batch(additionalInformation);
                delete batch;
                break;
            }
        }
        return 0;

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Unknown command: " << e.what() << "\n";
        PipelineStatus::getInstance().setPipePosition(PipelineStatus::PipePosition::NONE);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        PipelineStatus::getInstance().setPipePosition(PipelineStatus::PipePosition::NONE);
    }
}

bool CommandType::isError(string commandLine) {
    string commandLineTemp = commandLine;
    char pomChar;
    vector<int> niz;
    int indexOfFirstQuotationMark = commandLineTemp.find('"');
    int indexOfSecondQuotationMark = commandLineTemp.find('"', indexOfFirstQuotationMark + 1);
    try {
        if (indexOfFirstQuotationMark != string::npos && indexOfSecondQuotationMark == string::npos) {
            commandLine += "\"";
            throw GPogresniNavodnici();
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Unknown command: " << e.what() << "\n";
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    for (int i = 0; i < commandLineTemp.size(); i++) {
        if (i == indexOfFirstQuotationMark)i = indexOfSecondQuotationMark;
        pomChar = commandLineTemp[i];
        if (pomChar == '&' || pomChar == '*' || pomChar == '+' || pomChar == '?') { 
            niz.push_back(i);
        }
    }
    if (!niz.empty()) {
        std::cout << "Error - unexpected characters :";
        std::cout << '\n' << commandLineTemp << endl;
        for (int i = 0; i < commandLineTemp.size(); i++) {
            auto ch = find(niz.begin(), niz.end(), i);

            if (ch != niz.end()) {
                std::cout << '^';

            }
            else {
                std::cout << " ";
            }
        }
        std::cout << '\n'; 
        return true;
    }
    return false;
}


