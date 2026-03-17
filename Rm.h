#ifndef RM_H
#define RM_H
#include "RequiredArgument.h"
#include <string>
using namespace std;
class Rm : public RequiredArgument {
public:
	Rm(string commandLine);
	~Rm() = default;
protected:
	void controlledLoading();
	void process();
private:
	string argument;
};
#endif

