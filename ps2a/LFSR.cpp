//
//  LFSR.cpp
//  ps2
//
//  Created by Jingxian Shi on 2/5/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include "LFSR.hpp"

LFSR::LFSR(string s, int pos)
{
    seed = s;
    tap = pos;
}

LFSR::~LFSR()
{
    
}

int LFSR::step()
{
    int left_most = seed.at(0) - '0';
    int tap_bit = seed.at(seed.length() - 1 - tap) - '0'; //bug here
    
    int xor_bit = left_most ^ tap_bit;
    
    for(unsigned int i = 0; i < seed.length() - 1; i++)
    {
        seed.at(i) = seed.at(i + 1);
    }
    seed.at(seed.length() - 1) = '0' + xor_bit;

    return xor_bit;
}

int LFSR::generate(int k)
{
    if(k > 31 || k < 0)
    {
        return -1;
    }
    
    int num = 0;
    
    for(int i = 0; i < k; i++)
    {
        int bit = step();
        num *= 2;
        if(bit == 1)
        {
            num += 1;
        }
    }
    
    return num;
}

ostream& operator<< (ostream& out, LFSR& LFSR)
{
    out << LFSR.seed;
    return out;
}
