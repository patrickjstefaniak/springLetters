//
//  particleConroller.cpp
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

#include "particleController.h"
#include "cinder/ConvexHull.h"

particleController::particleController(){
    particle p = particle(vec2(250, 300));
    mParticles.push_back(p);
    p = particle(vec2(550, 300));
    mParticles.push_back(p);
    p = particle(vec2(700, 400));
    mParticles.push_back(p);
    p = particle(vec2(200, 200));
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
    //here particles in spring are still pointing to the particles in the particle controller
    //cout << " in initialize " << mSprings.front().p1->pos << "   ";
}


particleController::particleController(Shape2d shape){
    isClicked = false;
    mShape = shape;
    mLine = calcConvexHull(mShape);
    for(auto pt = mLine.begin(); pt != mLine.end(); ++pt){
        vec2 adjusted = *pt + vec2(getWindowWidth()/2, getWindowHeight()/2);
        particle p = particle(adjusted);
        mParticles.push_back(p);
    }
    curClicked = mParticles.begin();
    for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end();){
        list<particle>::iterator j = i;
        for(++j; j != mParticles.end(); ++j){
            //create springs between each particle
            spring s = spring(*i, *j);
            mSprings.push_back(s);
        }
        ++i;
    }
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
    /*for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end(); ++i){
        if(distance(m, i->pos) < 20){
            i->followMouse = ! i->followMouse;
        }
    }*/
    
    //if inside shape, find nearest point particle to mouse to mark as 'clicked'
    if(!isClicked){
        PolyLine2f cur;
        for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end(); ++i){
            cur.push_back(i->pos);
        }
        if(cur.contains(m)){
            cout << " in ";
            list<particle>::iterator i = mParticles.begin();
            list<particle>::iterator closest = i;
            for(++i; i != mParticles.end(); ++i){
                if(distance(i->pos, m) < distance(closest->pos, m)){
                    closest = i;
                }
            }
            closest->followMouse = true;
            curClicked = closest;
            isClicked = true;
        }else{
            cout << " out " << mLine.getPosition(1);
        }
    }else{
        isClicked = false;
        curClicked->followMouse = false;
    }
}


void particleController::update(){
    
    //calculate spring forces
    //iterate through list of springs, they will update forces of particles
    
    //see if particle is following the mouse, and then update
    
    list<spring>::iterator s = mSprings.begin();
    
    for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end(); ++i){
        if(i->followMouse){
            i->pos = mousePos;
                    }
        list<particle>::iterator j = i;
        for(++j; j != mParticles.end(); ++j){
            vec2 force = s->calculate(i->pos, j->pos);
            i->forceDir += force;
            j->forceDir += -force;
            ++s;
        }
        i->update();
    }
}


void particleController::mouseDrag(vec2 mPos){
    mousePos = mPos;
}

