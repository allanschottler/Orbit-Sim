/* 
 * File:   ObjectNode.cpp
 * Author: allan
 * 
 * Created on July 11, 2015, 4:41 PM
 */

#include "ObjectNode.h"


ObjectNode::ObjectNode() 
{
    _diameter = 1.0f;
    _rotationPeriod = 1.0f;
    _objectGeode = new osg::Geode;
   
    addChild( _objectGeode );
}


ObjectNode::~ObjectNode() 
{
}


void ObjectNode::setDiameter( float diameter )
{
    _diameter = diameter;
}


void ObjectNode::setRotationPeriod( float rotationPeriod )
{
    _rotationPeriod = rotationPeriod;
}
