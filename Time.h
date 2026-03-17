#ifndef TIME_H
#define TIME_H
#include <string>
#include "WithoutData.h"
using namespace std;
class Time : public WithoutData {
public:
	Time(string command_line);
	~Time() = default;
protected:
	void isError() const override;//ne menja stanje objekta
	void process();
	void controlledLoading();
private:
	string time;
	string output;
};
#endif
