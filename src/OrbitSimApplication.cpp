/* 
 * File:   OrbitSimApplication.cpp
 * Author: allan
 * 
 * Created on July 11, 2015, 4:26 PM
 */

#include "OrbitSimApplication.h"
#include "PlanetNode.h"
#include "TextureFactory.h"

/* system */
/* osg */
#include <osgGA/TrackballManipulator>
#include <osgGA/UFOManipulator>
#include <osgDB/ReadFile>

OrbitSimApplication::OrbitSimApplication() 
{
    _viewer.setUpViewInWindow( 0, 0, 800, 800 );
        
    //osg::ref_ptr< osgGA::UFOManipulator > manipulator = new osgGA::UFOManipulator();
    osg::ref_ptr< osgGA::TrackballManipulator > manipulator = new osgGA::TrackballManipulator();
    _viewer.setCameraManipulator( manipulator );
    _viewer.getCamera()->setClearColor( osg::Vec4( 0.0f, 0.0f, 0.0f, 1.0f ) );

    osg::ref_ptr< PlanetNode > earth = new PlanetNode();
    earth->setGeometryTexture( TextureFactory::getInstance()->getTexture2D( "data/planets/earthmap1k.jpg" ) );
    
    _sceneNode = new osg::Group;
    _sceneNode->addChild( earth );
	
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

