//
//  MarkovModel.hpp
//  ps6
//
//  Created by Jingxian Shi on 4/2/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#ifndef MarkovModel_hpp
#define MarkovModel_hpp

#include <stdio.h>
#include <string>
#include <map>

class MarkovModel {
 public:
    MarkovModel(std::string text, int k);
    ~MarkovModel();
    int order();
    int freq(std::string kgram);
    int freq(std::string kgram, char c);
    char randk(std::string kgram);
    std::string gen(std::string kgram, int T);
    friend std::ostream& operator<< (std::ostream &out, MarkovModel &mm);
 private:
    int _order;
    int _length;
    std::map <std::string, int> _kgrams;
    std::string _alphabet;
};
#endif /* MarkovModel_hpp */
