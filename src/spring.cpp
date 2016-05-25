//
//  spring.cpp
//  springLetters
//
//  Created by Patrick Stefaniak on 5/20/16.
//
//

#include "spring.h"

spring::spring(particle i, particle j){
    rest = distance(i.pos, j.pos);
    k = 0.1f;
    //cout << " in spring constructer " << p1->pos << "   " ;
}

vec2 spring::calculate(vec2 i, vec2 j){
    
    //find direction and distance, compare to rest length
    vec2 curParts = i - j ;
    float curDis = length(curParts);
    float displace = curDis - rest;
    //normalize direction, calculate force
    if(curParts != vec2(0)){
        curParts = normalize(curParts);
    }
    float f = -1 * k * displace;
    //apply forces to particles
    return curParts * f;
    
    //cout << " calculate " << p1->pos << "    " ;
    
}