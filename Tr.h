#ifndef TR_H
#define TR_H
#include <string>
#include "VariableArgument.h"
using namespace std;
class Tr : public VariableArgument {
public:
	Tr(string command_line);
	~Tr() = default;
protected:
	void controlledLoading();
	void process();
	void correctInput();
	void processWhat();
	void processWith();
	
private:
	string argument, output, whatPart, withPart;
};
#endif

