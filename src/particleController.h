//
//  particleController.h
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

#include "particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#pragma once

class particleController {
public:
    particleController () {}
    
    void initialize();
    void update();
    void draw();
    void mouseClick(vec2 mPos);
    void mouseDrag(vec2 mPos);
    
    list<particle>  mParticles;
    vec2            mousePos;
};