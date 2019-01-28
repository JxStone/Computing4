//
//  InTouchDeviceStartUp.hpp
//  ps7a
//
//  Created by Jingxian Shi on 4/12/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#ifndef InTouchDeviceStartUp_hpp
#define InTouchDeviceStartUp_hpp

#include <boost/regex.hpp>
#include <stdio.h>
#include <string>

const std::string start =
"(\\d{4}\\-(\\d{2})\\-(\\d{2}) "
"(\\d{2}):(\\d{2}):(\\d{2})): "
"\\(log.c.166\\) server started\\s*";
const std::string completed =
"(\\d{4}\\-(\\d{2})\\-(\\d{2}) "
"(\\d{2}):(\\d{2}):(\\d{2}))\\.(\\d{3})"
".*oejs\\.AbstractConnector:Started\\s+"
"SelectChannelConnector@0.0.0.0:9080\\s*";
const boost::regex startRegex(start);
const boost::regex completedRegex(completed);

class InTouch {
 public:
    InTouch(std::string start_line, std::string file_name, int line);
    void completed(std::string completed, int line);
    int elapsedTime();
    friend std::ostream& operator<<(std::ostream& out, const InTouch& right);
 private:
    int _start_line;
    int _end_line;
    int _boot_time;
    std::string _log_file_name;
    std::string _start_time;
    std::string _end_time;
    bool _completed;
};

#endif /* InTouchDeviceStartUp_hpp */
