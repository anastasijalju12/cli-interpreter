#include <iostream>
#include <sstream> 
#include <string>
#include "WcCharacter.h"
#include "Wc.h"

WcCharacter::WcCharacter(string argument, Wc* wc_object) {
	setArgument(argument);
	process(wc_object);

}

void WcCharacter::setArgument(string argument) {
	this->argument = argument;
}

string WcCharacter::getArgument() {
	return this->argument;
}

void WcCharacter::process(Wc* wc_object) {
	stringstream streamC;
	streamC.str(this->getArgument());
	int counter = 0;
	int c;
	while ((c = streamC.get()) != -1) { //==true
		if (c != 34 ) { //ako je belina (c!=32) ili '"'(34) ili \n(10)  ili tabulator (c!=9) ne treba da pove?a counter. 
			counter++;
		}
	}
	wc_object->setResult(counter);


}




