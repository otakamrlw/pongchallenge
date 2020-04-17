//
//  bat.h
//  pongBasic
//
//  Created by Takayuki Ota on 17.04.20.
//  Copyright © 2020 Takayuki Ota. All rights reserved.
//

//#ifndef bat_h
//#define bat_h
//
//
//#endif /* bat_h */

#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Bat
{
private:
    Vector2f position;
 
    // A RectangleShape object
    RectangleShape batShape;
 
    float batSpeed = .5f;
 
public:
    Bat(float startX, float startY);
 
    FloatRect getPosition();
 
    RectangleShape getShape();
 
    void moveLeft();
 
    void moveRight();
 
    void update();
 
};
