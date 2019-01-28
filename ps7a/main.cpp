//
//  main.cpp
//  ps7a
//
//  Created by Jingxian Shi on 4/12/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//
#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "InTouchDeviceStartUp.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Wrong number of arguments arguments." << std::endl;
        return -1;
    }
    std::ifstream fin;
    fin.open(argv[1]);
    if (fin.fail()) {
        std::cerr << "Fail to open file: " << argv[1] << std::endl;
        return -1;
    }
    std::string output_name(argv[1]);
    output_name += ".rpt";
    std::ofstream fout;
    fout.open(output_name.c_str());
    if (fout.fail()) {
        std::cerr << "Fail to output file: " << output_name << std::endl;
        return -1;
    }
    int lines_scanned = 0;
    int boot_started = 0;
    int boot_completed = 0;
    std::string line;
    std::vector<InTouch> boots;
    while (std::getline(fin, line)) {
        lines_scanned++;
        if (regex_match(line, startRegex)) {
            boot_started++;
            InTouch its(line, argv[1], lines_scanned);
            boots.push_back(its);
        } else if (regex_match(line, completedRegex)) {
            boot_completed++;
            boots.back().completed(line, lines_scanned);
        }
    }
    for (int i = 0; i < boots.size() - 1; ++i) {
        fout << boots[i] << std::endl;
    }
    fout << boots[boots.size() - 1];
    fin.close();
    fout.close();

    return 0;
}
