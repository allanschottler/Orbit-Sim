/* 
 * File:   RotationTransform.h
 * Author: allan
 *
 * Created on July 13, 2015, 7:13 PM
 */

#ifndef ROTATIONTRANSFORM_H
#define	ROTATIONTRANSFORM_H

#include "TimeTransform.h"

/* system */
/* osg */

class RotationTransform : public TimeTransform
{
public:
    
    /**
     * Constructor
     */
    RotationTransform();    

    /**
     * Sets the rotation period in hours
     * @param rotationPeriod
     */
    void setRotationPeriod( double rotationPeriod );
    
    /**
     * Sets the axial tilt in degrees
     * @param axialTilt
     */
    void setAxialTilt( double axialTilt );

    /**
     * Update callback
     * @param dt
     */
    void update( double dt );
    
private:
    
    double _rotationPeriod;
    
    double _axialTilt;

};

#endif	/* ROTATIONTRANSFORM_H */

