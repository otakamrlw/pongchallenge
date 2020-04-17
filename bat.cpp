//
//  bat.cpp
//  pongBasic
//
//  Created by Takayuki Ota on 17.04.20.
//  Copyright © 2020 Takayuki Ota. All rights reserved.
//

#include <stdio.h>
#include "bat.h"

Bat::Bat(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
 
    batShape.setSize(sf::Vector2f(50, 5));
    batShape.setPosition(position);
}

FloatRect Bat::getPosition()
{
    return batShape.getGlobalBounds();
}
 
RectangleShape Bat::getShape()
{
    return batShape;
}
 
void Bat::moveLeft()
{
    position.x -= batSpeed;
}
 
void Bat::moveRight()
{
    position.x += batSpeed;
}
 
void Bat::update()
{
    batShape.setPosition(position);
}
