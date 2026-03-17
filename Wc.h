#ifndef WC_H
#define WC_H
#include <string>
#include "VariableArgument.h"
#include "WcCharacter.h"
#include "WcWord.h"
using namespace std;
class Wc : public VariableArgument { //ISPRAVI TAKO DA WC.C I WC.W budu tipa wc pa da se samo poziva process shodno kog je tipa objekat(to u pozadini kompjuter sam odradi)
public:
	Wc(string command_line);
	~Wc() = default;
	void selectOption(string option, Wc* wc_object);//prepravi tako da se print odradi samostalno van ovec f-je
	string getOption();
	void setResult(int number);
	void controlledLoading();
	int getResult();
	string getArgument();
	friend class WcCharacter;
private:
	string argument, option, output;
	int result;
};
#endif

