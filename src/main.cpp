#include <iostream>
#include <osgViewer/Viewer>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osgGA/TrackballManipulator>


int main(void)
{
    osgViewer::Viewer viewer;
    viewer.setUpViewInWindow( 0, 0, 800, 800 );
	
    osg::ref_ptr<osgGA::TrackballManipulator> manipulator = new osgGA::TrackballManipulator();
    viewer.setCameraManipulator( manipulator );
	
    osg::ref_ptr<osg::Geode> scene = new osg::Geode;
	
    viewer.setSceneData( scene );	
    viewer.realize();
    
    // Render loop
    while( !viewer.done() )
    {        
        viewer.frame();
    }
}
  