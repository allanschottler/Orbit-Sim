/* 
 * File:   ObjectNode.cpp
 * Author: allan
 * 
 * Created on July 11, 2015, 4:41 PM
 */

#include "ObjectNode.h"
#include "osg/Geometry"


ObjectNode::ObjectNode() 
{
    _diameter = 1.0f;
    _rotationPeriod = 1.0f;
    _geode = new osg::Geode;
   
    addChild( _geode );    
}


ObjectNode::~ObjectNode()  
{
}


void ObjectNode::setGeometryTexture( osg::ref_ptr< osg::Texture2D > geometryTexture )
{
    //_geometryTexture = geometryTexture;
    
    _geode->getOrCreateStateSet()->setTextureAttributeAndModes( 0, geometryTexture );
}


void ObjectNode::setDiameter( float diameter )
{
    _diameter = diameter;
}


void ObjectNode::setRotationPeriod( float rotationPeriod )
{
    _rotationPeriod = rotationPeriod;
}
