#ifndef HEAD_H
#define HEAD_H
#include "VariableArgument.h"
#include <string>

using namespace std;
class Head :public VariableArgument {
public:
	Head(string command_line);
protected:
	void controlledLoading();
	void process();
	void processNCount();

private:
	int nCount;
	string argument, output;

};
#endif

