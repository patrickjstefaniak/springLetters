//
//  particle.h
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

using namespace ci;
using namespace ci::app;
using namespace std;

#pragma once

class particle {
public:
    particle () {}
    particle (vec2 p);
    
    void draw();
    
    
    vec2    pos;
    bool    followMouse;
    
};