//
//  ED.hpp
//  ps4
//
//  Created by Jingxian Shi on 3/8/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#ifndef ED_hpp
#define ED_hpp

#include <stdio.h>
#include <string>
#include <vector>

class ED
{
public:
    ED(std::string seq1, std::string seq2);
    ~ED();
    int penalty(char a, char b);
    int min(int a, int b, int c);
    int OptDistance();
    std::string Alignment();
    
private:
    std::string _seq1, _seq2;
    std::vector<std::vector<int> > matrix;
    
};

#endif /* ED_hpp */
