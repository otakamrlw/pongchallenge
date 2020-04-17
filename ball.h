//
//  ball.h
//  pongBasic
//
//  Created by Takayuki Ota on 17.04.20.
//  Copyright © 2020 Takayuki Ota. All rights reserved.
//

//#ifndef ball_h
//#define ball_h
//
//
//#endif /* ball_h */

#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Ball
{
private:
    Vector2f position;
 
    // A RectangleShape object called ref
    RectangleShape ballShape;
 
    float xVelocity = .2f;
    float yVelocity = .2f;
 
public:
    Ball(float startX, float startY);
 
    FloatRect getPosition();
 
    RectangleShape getShape();
 
    float getXVelocity();
 
    void reboundSides();
 
    void reboundBatOrTop();
 
    void hitBottom();
 
    void update();
 
};
