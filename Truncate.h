#ifndef TRUNCATE_H
#define TRUNCATE_H
#include "RequiredArgument.h"
#include <string>
using namespace std;
class Truncate : public RequiredArgument {
public:
	Truncate(string commandLine);
	~Truncate() = default;
protected:
	void controlledLoading();
	void process();
	
private:
	string argument;
};
#endif

