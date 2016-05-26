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
    
    vector<list<particle>>      mPartShapes;
    list<particle>              mParticles;
    vec2                        mousePos;
    list<spring>                mSprings;
    Shape2d                     mShape;
    PolyLine2f                  mLine;
    bool                        isClicked;
    list<particle>::iterator    curClicked;
    vector<vec2>                points;
    Path2d                      path;
};