/* 
 * File:   OrbitSimApplication.cpp
 * Author: allan
 * 
 * Created on July 11, 2015, 4:26 PM
 */

#include "OrbitSimApplication.h"
#include "PlanetNode.h"
#include "TextureFactory.h"
#include "RotationTransform.h"
#include "RegisterCallbacksVisitor.h"
#include "CircularOrbitTransform.h"

/* system */
/* osg */
#include <osgGA/TrackballManipulator>
#include <osgGA/UFOManipulator>
#include <osgDB/ReadFile>

OrbitSimApplication* OrbitSimApplication::_instance = 0;


OrbitSimApplication::OrbitSimApplication() 
{
    _viewer.setUpViewInWindow( 0, 0, 800, 800 );
        
    //osg::ref_ptr< osgGA::UFOManipulator > manipulator = new osgGA::UFOManipulator();
    osg::ref_ptr< osgGA::TrackballManipulator > manipulator = new osgGA::TrackballManipulator();
    _viewer.setCameraManipulator( manipulator );
    _viewer.getCamera()->setClearColor( osg::Vec4( 0.0f, 0.0f, 0.0f, 1.0f ) );
    
    _sceneNode = new osg::Group;
    _sceneNode->addChild( createEarth() );    
    
    RegisterCallbacksVisitor registerCallbacks;
    _sceneNode->accept( registerCallbacks );
	
    _viewer.setSceneData( _sceneNode );    
}


OrbitSimApplication::~OrbitSimApplication()
{
}


OrbitSimApplication* OrbitSimApplication::getInstance()
{
    if( !_instance )
        _instance = new OrbitSimApplication();
    
    return _instance;
}

    
void OrbitSimApplication::mainLoop()
{
    _viewer.realize();
    
    while( !_viewer.done() )
    {        
        _viewer.frame();
    }
}


osg::ref_ptr< PlanetNode > OrbitSimApplication::createEarth()
{
    osg::ref_ptr< PlanetNode > earth = new PlanetNode();
    //earth->setDiameter( 12756 );
    earth->setRotationPeriod( 23.9 );
    earth->setGeometryTexture( TextureFactory::getInstance()->getTexture2D( "data/planets/earthmap1k.jpg" ) );    
    
    osg::ref_ptr< PlanetNode > moon = new PlanetNode();
    moon->setDiameter( 0.5 );/// 12756 );
    moon->setRotationPeriod( 655.7 );
    moon->setGeometryTexture( TextureFactory::getInstance()->getTexture2D( "data/planets/moonmap1k.jpg" ) );     
    
    osg::ref_ptr< CircularOrbitTransform > orbitTransform = new CircularOrbitTransform();
    orbitTransform->setRadius( 3.84 );
    //orbitTransform->setOrbitalPeriod( 27.3 );
    orbitTransform->setOrbitalPeriod( 27.3 );
    orbitTransform->addChild( moon );
    
    earth->addChild( orbitTransform );
    
    return earth;
}

