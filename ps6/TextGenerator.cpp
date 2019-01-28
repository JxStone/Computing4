//
//  main.cpp
//  ps6
//
//  Created by Jingxian Shi on 3/30/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "MarkovModel.hpp"

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        std::cout << "Wrong number of arguments" << std::endl;
        return -1;
    }
    int k = atoi(argv[1]);
    int T = atoi(argv[2]);
    std::string text = "";
    std::string current;
    while ((std::cin >> current)) {
        text += " " + current;
        current = "";
    }
    MarkovModel mm(text, k);
    std::cout << mm.gen(text.substr(0, k), T) << std::endl;
    std::cout << mm << std::endl;
    return 0;
}
