#ifndef TOUCH_H
#define TOUCH_H
#include <string>
#include "RequiredArgument.h"
using namespace std;
class Touch :public RequiredArgument {
public:
	Touch(string command_line);
	~Touch() = default;
protected:
	void ControlledLoading();
	void process();
private:
	string argument;
};
#endif

