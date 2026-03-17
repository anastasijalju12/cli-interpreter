#include <string>
#include <sstream>
#ifndef COMMANDS_H
#define COMMANDS_H
using namespace std;
class Commands{ //klasa od koje su izvedene klase data process i withoutdata process
public:
	Commands(string commandLine);//kao argument prima sve informacije koje su ostale nakon sto se izdvoji naziv komande
protected:
	void setCommandLine(string commandLine1);
	stringstream& getStream() { return stream; }
private:
	stringstream stream;
};
#endif
