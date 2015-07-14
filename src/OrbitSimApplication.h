/* 
 * File:   OrbitSimApplication.h
 * Author: allan
 *
 * Created on July 11, 2015, 4:26 PM
 */

#ifndef ORBITSIMAPPLICATION_H
#define	ORBITSIMAPPLICATION_H

#include "PlanetNode.h"

/* system */
#include <iostream>

/* osg */
#include <osgViewer/Viewer>
#include <osg/Group>
#include <osg/ref_ptr>


class OrbitSimApplication 
{
public:
    
    /**
     * Returns unique instance
     * @return 
     */
    static OrbitSimApplication* getInstance();
  
    /**
     * Destructor
     */
    virtual ~OrbitSimApplication();
    
    /**
     * Application loop
     */
    void mainLoop();
    
private:
    
    /**
     * Private constructor
     */
    OrbitSimApplication();
    
    osg::ref_ptr< PlanetNode > createEarth();
    
    /* Unique instance */
    static OrbitSimApplication* _instance;
    
    osgViewer::Viewer _viewer;
    
    osg::ref_ptr< osg::Group > _sceneNode;

};

#endif	/* ORBITSIMAPPLICATION_H */

