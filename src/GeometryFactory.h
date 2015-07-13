/* 
 * File:   GeometryFactory.h
 * Author: allan
 *
 * Created on July 12, 2015, 8:59 PM
 */

#ifndef GEOMETRYFACTORY_H
#define	GEOMETRYFACTORY_H

/* system */
#include <map>

/* osg */
#include <osg/Geometry>


class GeometryFactory 
{
public:
    
    enum GeometryType
    {
        SPHERE = 0
    };
    
    
    /**
     * Returns unique instance
     * @return 
     */
    static GeometryFactory* getInstance();
       
    /**
     * Destructor
     */
    virtual ~GeometryFactory();
    
    /**
     * Returns a unique geometry
     * @param type
     * @return 
     */
    osg::ref_ptr< osg::Geometry > getGeometry( GeometryType type );
    
private:
    
    /**
     * Private constructor
     */
    GeometryFactory();
     
    /* Unique instance */
    static GeometryFactory* _instance;
    
    /* Unique geometry instances */
    std::map< GeometryType, osg::ref_ptr< osg::Geometry > > _uniqueGeometries;
};

#endif	/* GEOMETRYFACTORY_H */

