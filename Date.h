#ifndef DATE_H
#define DATE_H
#include <string>
#include "WithoutData.h"
using namespace std;
class Date : public WithoutData {
public:
	Date(string command_line);
	~Date() = default;
protected:
	void isError() const override;
	void process();
	void controlledLoading();
private:
	string date;
	string output;

};
#endif
