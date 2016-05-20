//
//  particle.h
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

#pragma once

using namespace ci;
using namespace ci::app;
using namespace std;

class particle {
public:
    particle () {}
    particle (vec2 p);
    
    void draw();
    void update();
    
    vec2    pos, forceDir;
    bool    followMouse;
    
};