/* 
 * File:   GeometryFactory.cpp
 * Author: allan
 * 
 * Created on July 12, 2015, 8:59 PM
 */

#include "GeometryFactory.h"
#include "SphereGeometry.h"

GeometryFactory* GeometryFactory::_instance = 0;


GeometryFactory::GeometryFactory() 
{
}


GeometryFactory::~GeometryFactory() 
{
}


GeometryFactory* GeometryFactory::getInstance()
{
    if( !_instance )
        _instance = new GeometryFactory();
    
    return _instance;
}


osg::ref_ptr< osg::Geometry > GeometryFactory::getGeometry( GeometryType type )
{
    if( !_uniqueGeometries.count( type ) )
    {    
        switch( type )
        {
            case SPHERE:
                _uniqueGeometries[ type ] = new SphereGeometry();
                break; 

            default:
                return 0;
        }
    }
    
    return _uniqueGeometries[ type ];
}