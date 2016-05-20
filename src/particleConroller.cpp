//
//  particleConroller.cpp
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

#include "particleController.h"

void particleController::initialize(){
    particle p = particle(vec2(250, 300));
    mParticles.push_back(p);
    p = particle(vec2(550, 300));
    mParticles.push_back(p);
}

void particleController::draw(){
    for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end();){
        list<particle>::iterator j = i;
        for(++j; j != mParticles.end(); ++j){
            gl::drawVector(vec3(i->pos.x,i->pos.y, 0.0f), vec3(j->pos.x, j->pos.y, 0.0f));
        }
        i->draw();
        ++i;
    }
}

void particleController::mouseClick(vec2 m){
    for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end(); ++i){
        if(distance(m, i->pos) < 20){
            i->followMouse = ! i->followMouse;
        }
    }
}

void particleController::update(){
    for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end(); ++i){
        if(i->followMouse){
            i->pos = mousePos;
        }
    }
}

void particleController::mouseDrag(vec2 mPos){
    mousePos = mPos;
}