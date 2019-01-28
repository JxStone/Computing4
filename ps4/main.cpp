//
//  main.cpp
//  ps4
//
//  Created by Jingxian Shi on 3/2/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include <iostream>
#include <SFML/System.hpp>
#include "ED.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    string a, b;
    cin >> a >> b;
    
    sf::Clock clock;
    sf::Time t;
    int edit_distance;
    
    ED Matrix(a, b);
    edit_distance = Matrix.OptDistance();
    cout << "Edit distance = " << edit_distance << endl << Matrix.Alignment() << endl;
    
    t = clock.getElapsedTime();
    cout << "Execution time is " << t.asSeconds() << " seconds \n" << endl;
    
    return 0;
}
