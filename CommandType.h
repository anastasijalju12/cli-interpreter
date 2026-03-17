#ifndef COMMANDTYPE_H
#define COMMANDTYPE_H
#include <string>
#include <sstream>

using namespace std;
class CommandType {
public:
	CommandType(string command_line);
	bool isError(string command_line);
	void processCommandLine(string command_line);
	int objectMaking();
protected:
	void pStream(string command_line);
	void pCommand();
	void pAdditionalInformation();
private:
	stringstream stream;
	string first; //tip komande
	string additionalInformation; //dodatne informacije koje se nalaze da desne strane od naziva komande
};
#endif
