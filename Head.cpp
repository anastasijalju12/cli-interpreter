#include "head.h"
#include <sstream>
#include <iostream>
using namespace std;
Head::Head(string command_line) : VariableArgument(command_line) {
	argument = "__UNSET__";
	controlledLoading();
	process();
	if (this->argument != "__UNSET__")passingInformation(argument, output);
}

void Head::controlledLoading() {
	processNCount();
	processArgument(argument);
	processDeterminedRedirectionVariableArgument(argument, output);
}


void Head::process() {
	stringstream streamTemp;
	(streamTemp).str(this->argument);
	string newArgument;
	string line;
	int i;
	for (i = 0; i < this->nCount; i++) {
		if (!(getline(streamTemp, line))) {
			break;
		}
		newArgument = newArgument + line + "\n";
	}
	argument = newArgument;
	if (i!=0)argument.pop_back();
}

void Head::processNCount() {
	string nCountTemp;
	getStream() >> nCountTemp;
	if (nCountTemp.substr(0, 2) != "-n")throw GHead();
	nCountTemp = nCountTemp.substr(2);
	nCount = atoi(nCountTemp.c_str());
	if (nCount >= 100000)throw GHead();
	getStream() >> ws;
}
