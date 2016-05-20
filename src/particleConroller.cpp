//
//  particleConroller.cpp
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

#include "particleController.h"

particleController::particleController(){
    particle p = particle(vec2(250, 300));
    mParticles.push_back(p);
    p = particle(vec2(550, 300));
    mParticles.push_back(p);
    for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end();){
        list<particle>::iterator j = i;
        for(++j; j != mParticles.end(); ++j){
            //create springs between each particle
            spring s = spring(*i, *j);
            mSprings.push_back(s);
        }
        ++i;
    }
    cout << " in initialize " << mSprings.front().p1->pos << "   ";
}



void particleController::draw(){
    for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end();){
        list<particle>::iterator j = i;
        for(++j; j != mParticles.end(); ++j){
            //draw lines between each particle
            gl::drawVector(vec3(i->pos.x, i->pos.y, 0), vec3(j->pos.x, j->pos.y, 0));
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
    
    //calculate spring forces
    //iterate through list of springs, they will update forces of particles
    
    for(spring &s: mSprings){
        s.calculate();
    }
    
    //see if particle is following the mouse, and then update
    
    for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end(); ++i){
        if(i->followMouse){
            i->pos = mousePos;
        }
        //i->update();
    }
}


void particleController::mouseDrag(vec2 mPos){
    mousePos = mPos;
}

