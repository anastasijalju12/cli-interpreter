#ifndef WITHOUTDATA_H
#define WITHOUTDATA_H
#include "PipelineStatus.h"
#include "Greska.h"
#include "Commands.h"
#include <string>
#include <sstream>

using namespace std;
class WithoutData:public Commands {
public:
	WithoutData(string command_line);
	virtual ~WithoutData() = default;
protected:
	string getCommandLine() const;
	virtual void isError() const = 0; 
	virtual void process() = 0;
	void processRedirectionOnlyOutput(string& output);
	void transportInformation(string argument, string output); //prosledjivanje informacije
	void print(string argument, string output); //ispis
	void pStdoutRedirection(string argument, string output);//upisuje iz argumenta informacije u output file

	void processDeterminedRedirectionWithoutData(string& output);
	void helperGetOutputRedirectionName(string& output);
private:
	string command_line;
};
#endif

