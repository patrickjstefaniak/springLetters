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

}


particleController::particleController(Shape2d shape){
    float springConst = 0;
    
    //get all paths from glyph shape and get points from their paths
    
    isClicked = false;
    mShape = shape;
    mPaths = mShape.getContours();
    vector<vector<vec2>>  mPoints;
    for(Path2d &pth: mPaths){
        mPoints.push_back(pth.getPoints());
        springConst += pth.getPoints().size();
    }
    
    //adjust spring constant based on number of points
    
    if (springConst < 7){
        springConst = .06;
    }else if(springConst > 20){
        springConst = .005;
    }else{
        springConst = .02;
    }
    
    //create particles from the points
    for(vector<vec2> &vecV: mPoints){
        list<particle> parts;
        for(vec2 &vec: vecV){
            vec2 adjusted = vec + vec2(getWindowWidth()/2, getWindowHeight() /2);
            particle p = particle(adjusted);
            parts.push_back(p);
            mParticles.push_back(p);
        }
        mParticleShapes.push_back(parts);
    }
    
    
    //create springs between each particle
    
    
    
    for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end();){
        list<particle>::iterator j = i;
        for(++j; j != mParticles.end(); ++j){
            spring s = spring(*i, *j);
            s.k = springConst;
            mSprings.push_back(s);
        }
        ++i;
    }
}


void particleController::draw(){
    float r = 0 ;
    float g = 0;
    for(Path2d &pth: mPaths){
        gl::color(r,g,1);
        r += .25;
        g += .3;
        gl::drawSolid(pth);
    }
}


void particleController::mouseClick(vec2 m){
    
    //if inside shape, find nearest point particle to mouse to mark as 'clicked'
    if(!isClicked){
        //check if click is inside shape
        //if so, find the point closest to the click and mark as closest, and isclicked as true
        bool check = false;
        for(Path2d &pth: mPaths){
            if(pth.contains(m)){
                check = true;
            }
        }
        if(check){
            list<particle>::iterator closest = mParticles.begin();
            for(list<particle>::iterator i = closest ++; i != mParticles.end(); i++){
                if(distance(i->pos, mousePos) < distance(closest->pos, mousePos)){
                    closest = i;
                }
            }
            closest->followMouse = true;
        isClicked = true;
        }
    }else{
        isClicked = false;
        for(list<particle>::iterator i = mParticles.begin(); i != mParticles.end(); ++i){
            i->followMouse = false;
        }
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
    
    //update single list of particles into vector of lists
    
    list<particle>::iterator singleP = mParticles.begin();
    for(list<particle> &plis: mParticleShapes){
        for(particle &part: plis){
            part.pos = singleP->pos;
            singleP ++;
        }
    }
    
    //update original glyph shape to the particle points
    vector<list<particle>>::iterator pVecLis = mParticleShapes.begin();
    for(Path2d &pth: mPaths){
        int i = 0;
        for(particle &part: *pVecLis){
            pth.setPoint(i, part.pos);
            i++;
        }
        pVecLis ++;
    }
}


void particleController::mouseDrag(vec2 mPos){
    mousePos = mPos;
}

