#include "RequiredArgument.h"
#include <iostream>
#include "Greska.h"
using namespace std;

RequiredArgument::RequiredArgument(string commandLine) :DataProcess(commandLine) {

}

void RequiredArgument::passingInformation() {
    string whatForwardsRequiredArgument = "";
    if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::NONE) {
        //nista se ne izvrsava
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::START) {
        PipelineStatus::getInstance().setPipeTempInformation(whatForwardsRequiredArgument);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::MIDDLE) {
        PipelineStatus::getInstance().setPipeTempInformation(whatForwardsRequiredArgument);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::END) {
        PipelineStatus::getInstance().setPipePosition(PipelineStatus::PipePosition::NONE);
    }
}
/*void RequiredArgument::processDeterminedRedirectionRequiredArgument(string& argument) {
    if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::NONE) {
        processRedirectionOnlyInput(argument);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::START) {
        processRedirectionOnlyInput(argument);
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::MIDDLE) {
        if (this->getStream().peek() != EOF) { 
            throw GNeispravanUnosRequiredArgument();
        }
    }
    else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::END) {
        if (this->getStream().peek() != EOF) {
            cout << getStream().peek();
            throw GNeispravanUnosRequiredArgument();
        }
    }
}*/
void RequiredArgument::processArgument(string& dataNum) {//jedino prompt ne odgovara ovome, shodno tome on ima svoju implementaciju
    if (this->getStream().peek() == '"') {
        throw GNazivFajlSaNavodnicima();
    }
    else {
        this->getStream() >> dataNum;   
        if (dataNum == "__UNSET__")throw GRequiredArgumentDontHaveArgument();
    }
    getStream() >> ws;
}
