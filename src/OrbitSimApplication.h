/* 
 * File:   OrbitSimApplication.h
 * Author: allan
 *
 * Created on July 11, 2015, 4:26 PM
 */

#ifndef ORBITSIMAPPLICATION_H
#define	ORBITSIMAPPLICATION_H

/* system */
#include <iostream>

/* osg */
#include <osgViewer/Viewer>
#include <osg/Group>
#include <osg/ref_ptr>


class OrbitSimApplication 
{
public:
    
    OrbitSimApplication();
  
    virtual ~OrbitSimApplication();
    
    void mainLoop();
    
private:
    
    osgViewer::Viewer _viewer;
    
    osg::ref_ptr< osg::Group > _sceneNode;

};

#endif	/* ORBITSIMAPPLICATION_H */

