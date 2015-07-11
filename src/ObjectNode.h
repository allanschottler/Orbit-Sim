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
     * Set diameter in km
     * @param diameter
     */
    void setDiameter( float diameter );
    
    /**
     * Set rotation period in Earth hours
     * @param rotationPeriod
     */
    void setRotationPeriod( float rotationPeriod );
    
protected:
    
    /* Diameter in km */
    float _diameter; 
    
    /* Rotation period in Earth hours */
    float _rotationPeriod;
    
    /* Object's geometry node */
    osg::ref_ptr< osg::Geode > _objectGeode;
};

#endif	/* OBJECTNODE_H */

