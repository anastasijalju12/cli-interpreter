#include "Touch.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include "Greska.h"
using namespace std;
Touch::Touch(string command_line) :RequiredArgument(command_line) {
    argument = "__UNSET__";
    ControlledLoading();
    process();
    passingInformation();
}
void Touch::ControlledLoading() {
    processArgument(argument);
}

void Touch::process() {
    string file_name = this->argument;
    ifstream file_check(file_name);
    if (file_check) {
        throw GFajlVecPostoji();
    }
    std::ofstream file(file_name, std::ios::app);
    if (!file)throw GNeDozvoljenNazivFajla();
    file.close();
}



