#ifndef ECHO_H
#define ECHO_H
#include <string>
#include "VariableArgument.h"
using namespace std;
class Echo : public VariableArgument {
public:
	Echo(string command_line);
	~Echo() = default;
	void process(); //ispisuje prosledjeni argument na standardni izlaz
	void controlledLoading();//ucitava podatke

private:
	string argument;
	string output;
};
#endif

