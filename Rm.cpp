#include "Rm.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include "Greska.h"
using namespace std;

Rm::Rm(string commandLine) :RequiredArgument(commandLine) {
    argument = "__UNSET__";
    controlledLoading();
    process();
    passingInformation();
}

void Rm::controlledLoading() {
    processArgument(argument);
}

void Rm::process() {
    if (remove(argument.c_str()) == 0) {
        //Fajl je obrisan
    }
    else {
        throw GNijeMoguceObrisatiFajl();
    }
}
