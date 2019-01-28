//
//  LFSR.hpp
//  ps2
//
//  Created by Jingxian Shi on 2/5/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#ifndef LFSR_hpp
#define LFSR_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class LFSR
{
public:
    LFSR(string s, int pos);
    ~LFSR();
    int step();
    int generate(int k);
    
    friend ostream& operator<< (ostream& out, LFSR &cLFSR);
private:
    string seed;
    int tap;
};

#endif /* LFSR_hpp */

