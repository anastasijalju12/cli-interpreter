#ifndef WCCHARACTER_H
#define WCCHARACTER_H
#include <string>
#include "DataProcess.h"
using namespace std;
class Wc;
class WcCharacter {
public:
	WcCharacter(string argument, Wc* wc_object);
	~WcCharacter() = default;
	void setArgument(string argument);
	string getArgument();
	void process(Wc* wc_object);

private:
	string argument;
};
#endif
