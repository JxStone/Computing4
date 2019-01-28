//
//  ED.cpp
//  ps4
//
//  Created by Jingxian Shi on 3/8/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include "ED.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

ED::ED(std::string seq1, std::string seq2)
{
    _seq1 = seq1;
    _seq2 = seq2;
    
    matrix.resize(_seq1.length() + 1);
    for(int i = 0; i < matrix.size(); i++)
    {
        matrix[i].resize(_seq2.length() + 1);
    }
}

ED::~ED()
{
    
}

int ED::penalty(char a, char b)
{
    return a != b;
}

int ED::min(int a, int b, int c)
{
    int min = a;
    if(b < min)
    {
        min = b;
    }
    if(c < min)
    {
        min = c;
    }
    return min;
}

int ED::OptDistance()
{
    for(int i = _seq1.length(); i >= 0; i--)
    {
        matrix[i][_seq2.length()] = 2 * (_seq1.length() - i);
    }
    for(int j = _seq2.length(); j >= 0; j--)
    {
        matrix[_seq1.length()][j] = 2 * (_seq2.length() - j);
    }
    
    for(int i = _seq1.length() - 1; i >= 0; i--)
    {
        for(int j = _seq2.length() - 1; j >= 0 ; j--)
        {
            matrix[i][j] = min(2 + matrix[i + 1][j],
                               2 + matrix[i][j + 1],
                               matrix[i + 1][j + 1] + penalty(_seq1[i], _seq2[j]));
        }
    }
    
    return matrix[0][0];
}

std::string ED::Alignment()
{
    int current = matrix[0][0];
    int i = 0, j = 0;
    std::string alignment = "";
    
    while(!(i == _seq1.length() && j == _seq2.length()))
    {
        if (i == _seq1.length())
        {
            while (j < _seq2.length())
            {
                alignment.push_back('-');
                alignment.push_back(' ');
                alignment.push_back(_seq2[j]);
                alignment.push_back(' ');
                alignment.push_back('2');
                alignment.push_back('\n');
                j++;
            }
            break;
        }
        if (j == _seq2.length())
        {
            while (i < _seq1.length())
            {
                alignment.push_back(_seq1[i]);
                alignment.push_back(' ');
                alignment.push_back('-');
                alignment.push_back(' ');
                alignment.push_back('2');
                alignment.push_back('\n');
                i++;
            }
            break;
        }
        
        if(current == (matrix[i+1][j] + 2)) //below
        {
            alignment.push_back(_seq1[i]);
            alignment.push_back(' ');
            alignment.push_back('-');
            alignment.push_back(' ');
            alignment.push_back('2');
            alignment.push_back('\n');
            i++;
            current = matrix[i][j];
        }
        else if(current == (matrix[i][j+1] + 2)) //right
        {
            alignment.push_back('-');
            alignment.push_back(' ');
            alignment.push_back(_seq2[j]);
            alignment.push_back(' ');
            alignment.push_back('2');
            alignment.push_back('\n');
            j++;
            current = matrix[i][j];
        }
        else if(current == (matrix[i+1][j+1] + penalty(_seq1[i], _seq2[j]))) //diagonal
        {
            alignment.push_back(_seq1[i]);
            alignment.push_back(' ');
            alignment.push_back(_seq2[j]);
            alignment.push_back(' ');
            alignment.push_back(penalty(_seq1[i], _seq2[j]) + '0');
            alignment.push_back('\n');
            i++;
            j++;
            current = matrix[i][j];
        }
    }
    
    return alignment;
}
