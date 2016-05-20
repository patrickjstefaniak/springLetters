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
    forceDir = vec2(0.0);
}

void particle::draw(){
    gl::color(.9,.5,.5);
    gl::drawSolidCircle(pos, 20);
}

void particle::update(){
    //calculate new pos based on velocity and spring force and reset force
    pos += forceDir;
    cout << forceDir << "   ";
    forceDir = vec2(0);
}