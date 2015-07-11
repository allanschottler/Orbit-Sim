/* 
 * File:   PlanetNode.cpp
 * Author: allan
 * 
 * Created on July 11, 2015, 5:54 PM
 */

#include "PlanetNode.h"

PlanetNode::PlanetNode()
{
    _sphereGeometry = new SphereGeometry(); 
    
    _objectGeode->addDrawable( _sphereGeometry );
}


PlanetNode::~PlanetNode() 
{
}


void PlanetNode::buildNode()
{    
}
