#ifndef PROMPT_H
#define PROMPT_H
#include "RequiredArgument.h";
#include <string>
using namespace std;
class Prompt :public RequiredArgument {
public:
	Prompt(string commandLine);
	~Prompt() = default;

protected:
	void controlledLoading();
	void process();
	virtual void processArgument(string& dataNum) override;
	
private:
	string argument;//sign
};
#endif

