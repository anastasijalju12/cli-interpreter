#ifndef REQUIREDARGUMENT_H
#define REQUIREDARGUMENT_H
#include <string>
#include "DataProcess.h"
using namespace std;
class RequiredArgument :public DataProcess {
public:
	RequiredArgument(string commandLine);
protected:
	
	virtual void processArgument(string& dataNum) override;

	//void processDeterminedRedirectionRequiredArgument(string& argument);//shodno tome da li je komanda van cevovoda ili unutar nekog dela cevovoda(pocetak, sredina, kraj) pozovi ucitvanje informnacija
	void passingInformation();//prosledjivanje informacije u cevovodu, ili njen ispis
private:

};
#endif

