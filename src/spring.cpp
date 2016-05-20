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
    p1 = &i;
    p2 = &j;
    cout << " in spring constructer " << p1->pos << "   " ;
}

void spring::calculate(){
    /*
    //find direction and distance, compare to rest length
    vec2 curParts = a->pos - b->pos ;
    float curDis = length(curParts);
    float displace = curDis - rest;
    //normalize direction, calculate force
    if(curParts != vec2(0)){
        curParts = normalize(curParts);
    }
    float f = -1 * k * displace;
    //apply forces to particles
    a->forceDir += curParts * f;
    b->forceDir -= curParts * f;
    */
    cout << " calculate " << p1->pos << "    " ;
    p1->forceDir += vec2(1,0);
    p2->forceDir -= vec2(1,3);
}