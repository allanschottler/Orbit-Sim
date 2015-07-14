/* 
 * File:   CircularOrbitTransform.h
 * Author: allan
 *
 * Created on July 13, 2015, 8:13 PM
 */

#ifndef CIRCULARORBITTRANSFORM_H
#define	CIRCULARORBITTRANSFORM_H

#include "TimeTransform.h"

/* system */
/* osg */

class CircularOrbitTransform : public TimeTransform
{
public:
    
    /**
     * Constructor
     */
    CircularOrbitTransform();    

    /**
     * Sets the radius in 10**6 km
     * @param radius
     */
    void setRadius( double radius );
    
    /**
     * Sets the orbital period in Earth days
     * @param orbitalPeriod
     */
    void setOrbitalPeriod( double orbitalPeriod );
    
    /**
     * Update callback
     * @param dt
     */
    virtual void update( double dt );

private:
    
    double _radius;
    
    double _orbitalPeriod;

};

#endif	/* CIRCULARORBITTRANSFORM_H */

