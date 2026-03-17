#include <string>
#include <sstream>
#include "PipelineStatus.h"
#include "Greska.h"
#include "Commands.h"
#ifndef DATAPROCESS_H
#define DATAPROCESS_H
using namespace std;
class DataProcess:public Commands{ 
public: 
	DataProcess(string commandLine);
	~DataProcess() = default;

protected:
	
	virtual void processArgument(string& dataNum) = 0;//procesuje sve sem redirekcije
	void pSentence(string& dataNum);//ucitavanje argumenta u formi "recenica" i upisivanje u pr. argument

private:
	

};
#endif
