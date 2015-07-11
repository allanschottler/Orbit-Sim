/* 
 * File:   PlanetNode.h
 * Author: allan
 *
 * Created on July 11, 2015, 5:54 PM
 */

#ifndef PLANETNODE_H
#define	PLANETNODE_H

#include "ObjectNode.h"
#include "SphereGeometry.h"

/* system */
/* osg */

class PlanetNode : public ObjectNode
{
public:
    
    /**
     * Constructor
     */
    PlanetNode();
   
    /**
     * Destructor
     */
    virtual ~PlanetNode();
    
    /**
     * Builds transforms and geometries
     */
    void buildNode();
    
private:

    /* Object's geometry */
    osg::ref_ptr< SphereGeometry > _sphereGeometry;
};

#endif	/* PLANETNODE_H */

