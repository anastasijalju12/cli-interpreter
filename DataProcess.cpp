#include "DataProcess.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

void DataProcess::pSentence(string& dataNum) {
    this->getStream().get();
    std::getline(this->getStream(), dataNum, '"');
    getStream() >> ws;
}


DataProcess::DataProcess(string commandLine):Commands(commandLine){
    
}


