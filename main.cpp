#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "CommandType.h"
#include "Greska.h"
#include "PipelineStatus.h"
#define pipeFile "pipeFile.txt"
using namespace std;
string sign = "&";
PipelineStatus& cmd = PipelineStatus::getInstance();

string makingPipeInput(string pipeInformation) {
    string command;
    string helper1,helper2;
    string additionalInformation;
    stringstream stream;
    (stream).str(pipeInformation);
    stream >> ws;
    stream >> command;
    stream >> ws;
    if (command == "wc"||command=="head") {
        stream>>helper1; 
        stream >> ws;
        getline(stream, additionalInformation);
        PipelineStatus::changingFileWithPipeTempInformation(pipeFile);
        return string(command) + " " + helper1 + " "+ pipeFile + " " + additionalInformation;
    }
    else if (command == "tr") {
        stream >> helper1;
        stream >> ws;
        stream >> helper2;
        stream >> ws;
        getline(stream, additionalInformation);
        PipelineStatus::changingFileWithPipeTempInformation(pipeFile);
        return string(command)  + " " + pipeFile + " " + helper1 + " " + helper2 + " " + additionalInformation;
    }
    getline(stream, additionalInformation); 
    PipelineStatus::changingFileWithPipeTempInformation(pipeFile);
    return string(command) + " "  + pipeFile + " " + additionalInformation;


}

int main() {
    std::string commandLine;
    while (true) {
        vector <string> commands;//ukoliko imamo cevovod, commands predstavlja niz tih komandi
        stringstream streamCommandLine;
        string command;//pojedinacna komanda koju upisujemo u commands
        
        cout << sign << " ";
        getline(cin, commandLine);
        if (commandLine.size() > 512) {
            commandLine = commandLine.substr(0, 512);
        }

        (streamCommandLine).str(commandLine);
        while (getline(streamCommandLine, command, '|')) {
            commands.push_back(command);
        }
        
        if (commands.size() == 1) { //zahtev je bez cevovoda
            cmd.setPipePosition(PipelineStatus::PipePosition::NONE);
            CommandType* commandType = new CommandType(commandLine);
            if (commandType->objectMaking()) {
                cmd.setPipePosition(PipelineStatus::PipePosition::NONE);
                break;
            }
        }
        else {
            for (int i = 0; i < commands.size(); i++) {
                if (i == 0) {
                    cmd.setPipePosition(PipelineStatus::PipePosition::START);
                    CommandType* commandType = new CommandType(commands[i]);
                    if (commandType->objectMaking()) {
                        cmd.setPipePosition(PipelineStatus::PipePosition::NONE);
                        break;
                    }
                }
                else if (i == commands.size() - 1) {
                    if (cmd.getPipePosition() == PipelineStatus::PipePosition::NONE)break;
                    cmd.setPipePosition(PipelineStatus::PipePosition::END);
                    commands[i]= makingPipeInput(commands[i]);
                    CommandType* commandType = new CommandType(commands[i]);
                    if (commandType->objectMaking()) {
                        cmd.setPipePosition(PipelineStatus::PipePosition::NONE);
                        break;
                    }
                }
                else {
                    if (cmd.getPipePosition() == PipelineStatus::PipePosition::NONE)break;
                    cmd.setPipePosition(PipelineStatus::PipePosition::MIDDLE);
                    commands[i] = makingPipeInput(commands[i]);
                    CommandType* commandType = new CommandType(commands[i]);
                    if (commandType->objectMaking()) {
                        cmd.setPipePosition(PipelineStatus::PipePosition::NONE);
                        break;
                    }
                }
            }
        }
    }
}
