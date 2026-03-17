#include "Truncate.h"
#include "Greska.h"
#include <fstream>
#include <iostream>

using namespace std;

Truncate::Truncate(string commandLine) :RequiredArgument(commandLine) {
    argument = "__UNSET__";
    controlledLoading();
    process();
    passingInformation();
}

void Truncate::controlledLoading() {
    processArgument(argument);
}

void Truncate::process() {
    std::ifstream file_check(argument);

    if (!file_check.is_open()) {
        throw GNijeMoguceOtvoritiFajl();
    }
    file_check.close();

    std::ofstream file(argument, std::ofstream::out | std::ofstream::trunc);
    if (!file.is_open()) {
        throw GNijeMoguceOtvoritiFajl();
    }
    //Sadrzaj fajla je obrisan
    file.close();
}
