#ifndef BATCH_H
#define BATCH_H
#include "VariableArgument.h"
#include "CommandType.h"
class Batch :public VariableArgument {
public:
	Batch(string commandLine);
	~Batch() = default;
protected:
	void controlledLoading();
	void process();
	void processDeterminedRedirectionVariableArgument(string& argument, string& output) override;
private:
	string argument, output;

};
#endif

