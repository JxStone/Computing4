//
//  InTouchDeviceStartUp.cpp
//  ps7a
//
//  Created by Jingxian Shi on 4/12/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <string>
#include "InTouchDeviceStartUp.hpp"

InTouch::InTouch(std::string start_line, std::string file_name, int line) {
    _log_file_name = file_name;
    _start_line = line;
    _end_line = 0;
    _end_time = "";
    _boot_time = 0;
    _completed = false;
    boost::smatch sm;
    boost::regex_match(start_line, sm, startRegex);
    _start_time = sm[1];
}
void InTouch::completed(std::string completed, int line) {
    _completed = true;
    _end_line = line;
    boost::smatch sm;
    boost::regex_match(completed, sm, completedRegex);
    _end_time = sm[1];
    _boot_time = elapsedTime();
}
int InTouch::elapsedTime() {
    boost::posix_time::ptime start_time
    (boost::posix_time::time_from_string(_start_time));
    boost::posix_time::ptime end_time
    (boost::posix_time::time_from_string(_end_time));
    boost::posix_time::time_duration elapsedTime = end_time - start_time;
    return elapsedTime.total_milliseconds();
}
std::ostream& operator<<(std::ostream& out, const InTouch& right) {
    out << "=== Device boot ===" << std::endl;
    out << right._start_line << "(" << right._log_file_name << "): "
    << right._start_time << " Boot Start" << std::endl;
    if (right._completed) {
        out << right._end_line << "(" << right._log_file_name << "): "
        << right._end_time << " Boot Completed" << std::endl
        << "\tBoot Time: " << right._boot_time << "ms " << std::endl;
    } else {
        out << "**** Incomplete boot **** " << std::endl;
    }
    return out;
}
