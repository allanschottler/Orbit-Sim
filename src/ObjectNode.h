/* 
 * File:   ObjectNode.h
 * Author: allan
 *
 * Created on July 11, 2015, 4:41 PM
 */

#ifndef OBJECTNODE_H
#define	OBJECTNODE_H

/* system */
/* osg */
#include <osg/Group>
#include <osg/Geode>
#include <osg/Texture2D>

#include "RotationTransform.h"

class ObjectNode : public osg::Group
{
public:
    
    /**
     * Constructor
     */
    ObjectNode();
        
    /**
     * Destructor
     */
    virtual ~ObjectNode();
    
    /**
     * Builds transforms and geometries
     */
    virtual void buildNode() = 0;
    
    /**
     * Set geometry's texture
     * @param geometryTexture
     */
    void setGeometryTexture( osg::ref_ptr< osg::Texture2D > geometryTexture );
    
    /**
     * Set diameter in km
     * @param diameter
     */
    void setDiameter( float diameter );
    
    /**
     * Set rotation period in Earth hours
     * @param rotationPeriod
     */
    void setRotationPeriod( double rotationPeriod );
    
protected:
    
    /* Scale transform */
    osg::ref_ptr< osg::MatrixTransform > _scaleTransform;
    
    /* Rotation transform */
    osg::ref_ptr< RotationTransform > _rotationTransform;
    
    /* Geometry node */
    osg::ref_ptr< osg::Geode > _geode;    
};

#endif	/* OBJECTNODE_H */

