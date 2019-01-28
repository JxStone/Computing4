//
//  MarkovModel.cpp
//  ps6
//
//  Created by Jingxian Shi on 4/2/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//
#include "MarkovModel.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <exception>
#include <stdexcept>


MarkovModel::MarkovModel(std::string text, int k) {
    _order = k;
    _alphabet = "";
    _length = text.size();
    std::string temp = "";
    temp = text + text.substr(0, k);
    for (int i = 0; i < temp.size() - k; i++) {
        std::string kgram = temp.substr(i, k);
        _kgrams[kgram] += 1;
    }
    temp = text + text.substr(0, k+1);
    for (int i = 0; i < temp.size() - k - 1; i++) {
        std::string kp1gram = temp.substr(i, k+1);
        _kgrams[kp1gram] += 1;
        if (static_cast<int>(_alphabet.find(temp[i])) == -1)
            _alphabet += temp[i];
    }
}

MarkovModel::~MarkovModel() {
}

int MarkovModel::order() {
    return _order;
}

int MarkovModel::freq(std::string kgram) {
    if (kgram.size() != _order) {
        throw std::runtime_error("kgram is not of length k");
    }
    if (_order == 0) {
        return _length;
    }
    return _kgrams[kgram];
}

int MarkovModel::freq(std::string kgram, char c) {
    if (kgram.size() != _order) {
        throw std::runtime_error("kgram is not of length k");
    }
    std::string temp = kgram;
    temp += c;
    if (_kgrams.count(temp) == 0) {
        return 0;
    }
    return _kgrams[temp];
}

char MarkovModel::randk(std::string kgram) {
    if (kgram.size() != _order) {
        throw std::runtime_error("kgram is not of length k");
    }
    if (_kgrams.count(kgram) == 0) {
        throw std::runtime_error("no such kgram");
    }
    std::map<std::string, int> kgrams1;
    for (int i = 0; i < _alphabet.size(); i++) {
        std::string kgram1 = kgram + _alphabet[i];
        kgrams1[kgram1] = freq(kgram, _alphabet[i]);
    }
    int freq_sum = 0;
    std::map <std::string, int> sum;
    std::map <std::string, int>::iterator p;
    for (p = kgrams1.begin(); p != kgrams1.end(); p++) {
        freq_sum += p->second;
        sum[p->first] = freq_sum;
    }
    std::map <int, std::string> sort;
    for (p = sum.begin(); p != sum.end(); p++)
        sort[p->second] = p->first;
    char c;
    unsigned int seed = 1;
    int rand_num = rand_r(&seed) % freq(kgram);
    std::string temp;
    std::map <int, std::string>::iterator p1;
    for (p1 = sort.begin(); p1 != sort.end(); p1++) {
        if (p1->first > rand_num) {
            temp = p1->second;
            break;
        }
    }
    c = temp[_order];
    return c;
}

std::string MarkovModel::gen(std::string kgram, int T) {
    if (kgram.size() != _order) {
        throw std::runtime_error("kgram is not of length k");
    }
    std::string temp = kgram;
    std::string current = kgram;
    for (int i = 0; i < T; i++) {
        char c = randk(current);
        temp += c;
        current.erase(0, 1);
        current += c;
    }
    return temp;
}

std::ostream& operator<< (std::ostream &out, MarkovModel &mm) {
    out << "kgram order: " << mm._order << std::endl;
    out << "Alphabet: " << mm._alphabet << std::endl;
    out << "K-gram | Frequency" << std::endl;
    std::map<std::string, int>::iterator p;
    for (p = mm._kgrams.begin(); p != mm._kgrams.end(); p++)
    std::cout << p->first << " | " << p->second << std::endl;
    return out;
}
