//
//  particleController.h
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

#include "particle.h"
#include "spring.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#pragma once

class particleController {
public:
    particleController ();
    particleController (Shape2d shape);
    
    void update();
    void draw();
    void mouseClick(vec2 mPos);
    void mouseDrag(vec2 mPos);
    
    vector<list<particle>>      mParticleShapes;
    list<particle>             mParticles;
    vector<Path2d>              mPaths;
    
    list<spring>                mSprings;
    Shape2d                     mShape;

    bool                        isClicked;
    vec2                        mousePos;
    particle                  * curMoving;
};