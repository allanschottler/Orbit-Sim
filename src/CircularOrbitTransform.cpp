/* 
 * File:   OrbitTransform.cpp
 * Author: allan
 * 
 * Created on July 13, 2015, 8:13 PM
 */

#include "CircularOrbitTransform.h"


CircularOrbitTransform::CircularOrbitTransform() 
    : _radius( 0 ),
      _orbitalPeriod( 1 )
{
}


void CircularOrbitTransform::setRadius( double radius )
{
    _radius = radius;
}


void CircularOrbitTransform::setOrbitalPeriod( double orbitalPeriod )
{
    _orbitalPeriod = orbitalPeriod;
}


void CircularOrbitTransform::update( double dt )
{
    osg::Matrix translateRadius = osg::Matrix::translate( osg::Vec3( _radius, 0.0f, 0.0f ) );
    osg::Matrix rotateOrbitalPlane = osg::Matrix::rotate( dt / ( _orbitalPeriod * 24 ), osg::Vec3( 0.0f, 1.0f, 0.0f ) );
    
    setMatrix( translateRadius * rotateOrbitalPlane );    
}
