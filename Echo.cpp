#include "Echo.h"
#include <iostream>
using namespace std;

Echo::Echo(string command_line) :VariableArgument(command_line) {
	output = "";
	argument = "__UNSET__";
	controlledLoading();
	//process();
	passingInformation(argument,output);
}


void Echo::process() {
	//nema sta da  procesuje
}

void Echo::controlledLoading() {
	processArgument(argument);
	processDeterminedRedirectionVariableArgument(argument, output);
}



