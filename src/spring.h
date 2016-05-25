//
//  spring.h
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

#include "particle.h"

#pragma once

using namespace ci;
using namespace ci::app;
using namespace std;

class spring {
public:
    spring () {}
    spring (particle a, particle b);
    
    vec2 calculate(vec2 i, vec2 j);
    
    float rest, k;
};