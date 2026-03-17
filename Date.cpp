#include <ctime>
#include <string>
#include <iostream>
#include "Greska.h"
#include "Date.h"
using namespace std;

Date::Date(string command_line):WithoutData(command_line) {
    output = "";
    controlledLoading();
    process();
    transportInformation(this->date, output);
}

void Date::isError() const {
        throw GDateImaArgument();
}

void Date::process() {
    time_t current_time = std::time(0);
    tm curr_time;
    errno_t err = localtime_s(&curr_time, &current_time);
    this->date = to_string(curr_time.tm_year + 1900) + "-" + to_string(curr_time.tm_mon + 1) + "-" + to_string(curr_time.tm_mday);
}

void Date::controlledLoading(){
    processDeterminedRedirectionWithoutData(output);
}


