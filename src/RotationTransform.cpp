/* 
 * File:   RotationTransform.h
 * Author: allan
 *
 * Created on July 13, 2015, 7:13 PM
 */

#include "RotationTransform.h"

/* system */
/* osg */

RotationTransform::RotationTransform()
    : _rotationPeriod( 0 ),
      _axialTilt( 0 )
{
}


void RotationTransform::setRotationPeriod( double rotationPeriod ) 
{ 
    _rotationPeriod = rotationPeriod;
}


void RotationTransform::setAxialTilt( double axialTilt )
{
    _axialTilt = axialTilt;
}


void RotationTransform::update( double dt )
{
    osg::Matrix axisRotation = osg::Matrix::rotate( dt / _rotationPeriod, osg::Vec3( 0.0f, 1.0f, 0.0f ) );
    //osg::Matrix axialTiltRotation = :Matrix::rotate;
    
    setMatrix( axisRotation ); 
}

