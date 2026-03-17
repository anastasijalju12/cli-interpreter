#include "Tr.h"
#include <iostream>
using namespace std;
Tr::Tr(string command_line):VariableArgument(command_line){
	output = "";
	argument = "__UNSET__";
	controlledLoading();
	process();
	passingInformation(argument,output);
}
void Tr::controlledLoading() {
	processArgument(argument);
	processWhat();
	processWith();
	correctInput();
	processDeterminedRedirectionVariableArgument(argument, output);
}

void Tr::process() {
	if (withPart != "") {//zamenjujemo what sa with
		size_t startPosition = 0;
		while ((startPosition = argument.find(whatPart, startPosition)) != string::npos) {
			argument.replace(startPosition, whatPart.length(), withPart);
			startPosition += withPart.length();
		}
	}
	else if (withPart == "") {//brise se svuda pojavljivanje what
		size_t startPosition = 0;
		while ((startPosition = argument.find(whatPart, startPosition)) != string::npos) {
			argument.erase(startPosition, whatPart.length());
		}
	}	
}
void Tr::correctInput(){
	if (withPart == "") {
		withPart = whatPart;
		whatPart = argument;
		argument = "__UNSET__";
	}
}
void Tr::processWhat() {
	getStream() >> ws;
	if (getStream().peek() == '"') {
		pSentence(whatPart);
	}
	else {
		whatPart = "";
	}
}
void Tr::processWith() {
	getStream() >> ws;
	if (getStream().peek() == '"') {
		pSentence(withPart);
	}
	else if (getStream().eof()) {
		withPart = "";
	}
	getStream() >> ws;
}


