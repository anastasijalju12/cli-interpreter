#include "Wc.h"

Wc::Wc(string command_line) : VariableArgument(command_line) {
	output = "";
	argument = "__UNSET__";
	controlledLoading();
}

void Wc::setResult(int number) {
	this->result = number;
}
void Wc::controlledLoading() {
	processOption(option);
	processArgument(argument);
	processDeterminedRedirectionVariableArgument(argument, output);
	selectOption(option, this);//u okviru ovoga mi je printic
}

void Wc::selectOption(string option, Wc* wc_object) {
	if (option == "-c") {
		WcCharacter* numCha = new WcCharacter(argument, wc_object);
	}
	else if (option == "-w") {
		WcWord* numCha = new WcWord(argument, wc_object);
	}
	//if (wc_object->getResult() != 0) { //ovde je pretpostavka da treba 0 argumenata da se ispise
		passingInformation(to_string(wc_object->getResult()), output);
	//}
}
string Wc::getOption() {
	return this->option;
}
int Wc::getResult() {
	return this->result;
}

string Wc::getArgument() {
	return this->argument;
}

