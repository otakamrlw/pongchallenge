//
//  main.cpp
//  pongBasic
//
//  Created by Takayuki Ota on 17.04.20.
//  Copyright © 2020 Takayuki Ota. All rights reserved.
//

#include "bat.h"
#include "ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;
    // Make a window that is 1024 by 768 pixels
    // And has the title "Pong"
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
 
    int score = 0;
    int lives = 3;
 
    // create a bat
    Bat bat (windowWidth / 2, windowHeight - 20);
 
    // create a ball
    Ball ball(windowWidth / 2, 1);
 
 // Create a "Text" object called "message". Weird but we will learn about objects soon
    Text hud;
     
     // We need to choose a font
     Font font;
     // http://www.dafont.com/theme.php?cat=302
     font.loadFromFile("/Users/takayuki/Document/TUBOT/pong/pongBasic/pongBasic/ds_digital/DS-DIGIT.TTF");
     
     // Set the font to our message
     hud.setFont(font);
     
     // Make it really big
     hud.setCharacterSize(75);
     
     // Choose a color
     hud.setFillColor(sf::Color::White);
        
    while (window.isOpen())
    {
        /*
            Handle the player input
            *********************************************************************
            *********************************************************************
            *********************************************************************
        */
     
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                // Someone closed the window- bye
                window.close();
        }
     
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            // move left...
            bat.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            // move right...
            bat.moveRight();
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            // quit...
            // Someone closed the window- bye
            window.close();
        }

        if(ball.getPosition().top > windowHeight){
            ball.hitBottom();
            lives --;
            if(lives < 1){
                score = 0;
                lives = 3;
            }
        }
        
        if(ball.getPosition().top < 0){
            ball.reboundBatOrTop();
            score++;
        }
        
        if(ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth){
            ball.reboundSides();
        }
        if(ball.getPosition().intersects(bat.getPosition())){
            ball.reboundBatOrTop();
        }
        
        ball.update();
        bat.update();
        
        std::stringstream ss;
        ss << "Score:" << score << "    Lives:" << lives;
        hud.setString(ss.str());
        
        window.clear(Color(26, 128, 182, 255));
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        
        window.draw(hud);
        window.display();
}
    return 0;

    
}
