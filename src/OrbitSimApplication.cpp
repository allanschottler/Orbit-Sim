/* 
 * File:   OrbitSimApplication.cpp
 * Author: allan
 * 
 * Created on July 11, 2015, 4:26 PM
 */

#include "OrbitSimApplication.h"
#include "PlanetNode.h"

/* system */
/* osg */
#include <osgGA/TrackballManipulator>
#include <osgGA/UFOManipulator>

OrbitSimApplication::OrbitSimApplication() 
{
    _viewer.setUpViewInWindow( 0, 0, 800, 800 );
        
    //osg::ref_ptr< osgGA::UFOManipulator > manipulator = new osgGA::UFOManipulator();
    osg::ref_ptr< osgGA::TrackballManipulator > manipulator = new osgGA::TrackballManipulator();
    _viewer.setCameraManipulator( manipulator );
    _viewer.getCamera()->setClearColor( osg::Vec4( 0.0f, 0.0f, 0.0f, 1.0f ) );
	
    _sceneNode = new osg::Group;
    _sceneNode->addChild( new PlanetNode() );
	
    _viewer.setSceneData( _sceneNode );    
}


OrbitSimApplication::~OrbitSimApplication()
{
}


void OrbitSimApplication::mainLoop()
{
    _viewer.realize();
    
    while( !_viewer.done() )
    {        
        _viewer.frame();
    }
}

