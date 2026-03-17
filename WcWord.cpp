#include "WcWord.h"
#include <iostream>
#include <sstream> 
#include <string>
#include "Wc.h"
using namespace std;
WcWord::WcWord(string argument, Wc* wc_object) {
    setArgument(argument);
    process(wc_object);

}

void WcWord::setArgument(string argument) {
    this->argument = argument;
}

string WcWord::getArgument() {
    return this->argument;
}
void WcWord::process(Wc* wc_object) {
    stringstream streamW;

    streamW.str(this->getArgument());
    char c;
    int wordCount = 0;
    if (getArgument() != "") {
        bool inWord = false;
        while (streamW.get(c)) {
            if (isspace(c)) {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            }
            else {
                inWord = true;
            }
        }

        if (inWord) {
            wordCount++;
        }
    }

    wc_object->setResult(wordCount);

}


