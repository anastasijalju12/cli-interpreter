#include "Commands.h"
void Commands::setCommandLine(string commandLine1) {
    (this->stream).str(commandLine1);
}

Commands::Commands(string commandLine) {
    this->setCommandLine(commandLine);
}