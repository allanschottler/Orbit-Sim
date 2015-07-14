/* 
 * File:   PlanetNode.cpp
 * Author: allan
 * 
 * Created on July 11, 2015, 5:54 PM
 */

#include "PlanetNode.h"
#include "GeometryFactory.h"
#include "CircularOrbitTransform.h"

PlanetNode::PlanetNode()
{
    _geode->addDrawable( GeometryFactory::getInstance()->getGeometry( GeometryFactory::SPHERE ) );
}


PlanetNode::~PlanetNode() 
{
}


void PlanetNode::buildNode()
{    
}

