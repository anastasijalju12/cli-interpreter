#ifndef WCWORD_H
#define WCWORD_H
#include <iostream>
#include <string>
class Wc;

using namespace std;
class WcWord {
public:
	WcWord(string argument, Wc* wc_object);
	~WcWord() = default;
	void setArgument(string argument);
	string getArgument();
	void process(Wc* wc_object);
private:
	string argument;
};
#endif

