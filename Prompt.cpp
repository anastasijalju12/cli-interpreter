#include "prompt.h"
#include <iostream>
extern string sign;
using namespace std;
Prompt::Prompt(string commandLine) :RequiredArgument(commandLine) {
	argument = "__UNSET__";
	controlledLoading();
	process();
	passingInformation();
}

void Prompt::controlledLoading() {
	processArgument(argument);
}

void Prompt::process() {
	sign = argument;
}

void Prompt::processArgument(string& dataNum) {
	if (this->getStream().peek() == '"') {
		pSentence(dataNum);
	}
	else if (this->getStream().peek() != EOF && this->getStream().peek() != '<' && this->getStream().peek() != '>') {
		throw GPromptFajl();
	}
	else if(getStream().peek()==EOF){
		throw GRequiredArgumentDontHaveArgument();
	}
	else {
		throw GRequiredArgumentRedirection();
	}
}

