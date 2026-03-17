#ifndef VARIABLEARGUMENT_H
#define VARIABLEARGUMENT_H
#include <string>
#include <iostream>
#include "DataProcess.h"

using namespace std;
class VariableArgument :public DataProcess {
public:
	VariableArgument(string commandLine);
protected:
	void processOption(string& dataNum);
	void processRedirection(string& dataNum, string& output);//procesuje redirekciju kod tipa objekta variable argument
	void pFile(string& dataNum);//ucitavanje fajla pod nazivom procitanim iz streama i upisivanje njegovog sadrzaja u argument prosledjen funkcijom.
	void pFileReadingInformation(string& dataNum);
	void outputPrint(const string& argument, string& output);//na osnovu argumenata zna sta i gde da ispise
	void processRedirectionOnlyInput(string& dataNum);//trazi naziv redirekcije ulaznog toga i upisuje informacije iz redirekcije ili sa standarnog ulaza u prosledjeni argument. Dozvoljena je samo redirekcija za input.
	void pStdinRedirection(string& dataNum);//ucitavanje naziva ulazne redirekcije i upisivanje teksta iz nje u prosledjen argument funkcije
	void pStdin(string& dataNum);//ucitavanje informacija iz vise redova sa standarnog ulaza i upisivanje u prosledjeni argument
	void pStdoutRedirection(string argument, string output);//upisivanje sadrzaja iz argumenta argument u file pod nazivom prosledjenim argumentom output
	void helperOutputRedirection(string& output);//omogucava nam pravilno ucitavanje nacina izlazne redirekcije i naziva fajla, >> output.txt ili >output.txt
	void processRedirectionOnlyOutput(string& output);//ucitavanje naziva fajla koji predstavlja izlaznu redirekciju.
	virtual void processArgument(string& dataNum) override;
	virtual void processDeterminedRedirectionVariableArgument(string& argument, string& output);
	void passingInformation(string argument, string output);//prosledjivanje ili ispis informacije shodno tome da li je komanda u cevovodu i kom delu istog ili ne
private:

};
#endif

