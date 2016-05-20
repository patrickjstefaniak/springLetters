//
//  particle.cpp
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

#include "particle.h"

particle::particle(vec2 p){
    pos = p;
    followMouse = false;
}

void particle::draw(){
    gl::color(.9,.5,.5);
    gl::drawSolidCircle(pos, 20);
}