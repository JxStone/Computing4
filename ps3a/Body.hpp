//
//  Body.hpp
//  ps3a
//
//  Created by Jingxian Shi on 2/19/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#ifndef Body_hpp
#define Body_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable
{
public:
    Body();
    Body(double xpos, double ypos, double xvel, double yvel, double mass, std::string file_name);
    ~Body();
    void setWindowSize(int window_size) {_window_size = window_size;}
    void setUnivSize(double univ_size) {_univ_size = univ_size;}
    double getUnivSize() {return _univ_size;}
    
    friend std::istream& operator>>(std::istream& in, Body& body);
    
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    double _univ_size;
    int _window_size;
    double _xpos, _ypos, _xvel, _yvel, _mass;
    std::string _image_file;
    sf::Texture _texture;
    sf::Sprite _sprite;
};


#endif /* Body_hpp */
