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
    _scaleTransform = new osg::MatrixTransform();
    _rotationTransform = new RotationTransform();    
    _geode = new osg::Geode;
    
    _scaleTransform->addChild( _geode );
    _rotationTransform->addChild( _scaleTransform );   
    addChild( _rotationTransform );    
}


ObjectNode::~ObjectNode()  
{
}


void ObjectNode::setGeometryTexture( osg::ref_ptr< osg::Texture2D > geometryTexture )
{
    _geode->getOrCreateStateSet()->setTextureAttributeAndModes( 0, geometryTexture );
}


void ObjectNode::setDiameter( float diameter )
{
    _scaleTransform->setMatrix( osg::Matrix::scale( diameter/2, diameter/2, diameter/2 ) );
}


void ObjectNode::setRotationPeriod( double rotationPeriod )
{
    _rotationTransform->setRotationPeriod( rotationPeriod );
}
