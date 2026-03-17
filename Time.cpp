#include "Time.h"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Time::Time(string command_line) :WithoutData(command_line) {
    output = "";
    controlledLoading();
    process();
    transportInformation(this->time,output);
}
void Time::controlledLoading() {
    processDeterminedRedirectionWithoutData(output);
}
void Time::isError() const {
    throw GTimeImaArgument();
}
void Time::process() {
    time_t current_time = std::time(0);
    tm curr_time;
    errno_t err = localtime_s(&curr_time, &current_time);
    this->time = to_string(curr_time.tm_hour) + ":" + to_string(curr_time.tm_min) + ":" + to_string(curr_time.tm_sec);
}
