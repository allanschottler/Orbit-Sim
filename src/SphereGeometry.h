/* 
 * File:   SphereGeometry.h
 * Author: allan
 *
 * Created on July 11, 2015, 5:30 PM
 */

#ifndef SPHEREGEOMETRY_H
#define	SPHEREGEOMETRY_H

/* system */
/* osg */
#include <osg/Geometry>


class SphereGeometry : public osg::Geometry
{
public:
    
    /**
     * Constructor
     */
    SphereGeometry();
    
    /**
     * Destructor
     */
    virtual ~SphereGeometry();
    
private:
    
    /**
     * Builds vertex, normal and index arrays
     */
    void buildGeometry( float radius, unsigned int rings, unsigned int sectors );

};

#endif	/* SPHEREGEOMETRY_H */

