/* 
 * File:   SphereGeometry.cpp
 * Author: allan
 * 
 * Created on July 11, 2015, 5:30 PM
 */

#include "SphereGeometry.h"

/* system */
/* osg */

SphereGeometry::SphereGeometry() 
{    
    buildGeometry( 0.5f, 32, 32 );
}


SphereGeometry::~SphereGeometry() 
{
}


void SphereGeometry::buildGeometry( float radius, unsigned int rings, unsigned int sectors ) 
{
    osg::ref_ptr< osg::Vec3Array > sphereVertices = new osg::Vec3Array;
    osg::ref_ptr< osg::Vec3Array > sphereNormals = new osg::Vec3Array;
    osg::ref_ptr< osg::Vec2Array > sphereTexCoords = new osg::Vec2Array;    
    
    float const R = 1./( float )( rings-1 );
    float const S = 1./( float )( sectors-1 );
    unsigned int r, s;

    // Establish texture coordinates, vertex list, and normals
    for( r = 0; r < rings; r++ )
    {
        for( s = 0; s < sectors; s++ )
        {
            float const y = sin( -M_PI_2 + M_PI * r * R );
            float const x = cos( 2*M_PI * s * S ) * sin( M_PI * r * R );
            float const z = sin( 2*M_PI * s * S ) * sin( M_PI * r * R );

            sphereTexCoords->push_back( osg::Vec2( s*R, r*R ) );
            sphereVertices->push_back( osg::Vec3( x * radius, y * radius, z * radius ) );
            sphereNormals->push_back( osg::Vec3( x, y, z ) );
        }
    }

    setVertexArray( sphereVertices );
    
    setNormalBinding( osg::Geometry::BIND_PER_VERTEX );
    setNormalArray( sphereNormals );
            
    setTexCoordArray( 0, sphereTexCoords );

    // Generate quads for each face.  
    for( r = 0; r < rings-1; r++ )
    {
        for( s = 0; s < sectors-1; s++ )
        {
            osg::ref_ptr< osg::DrawElementsUInt > spherePrimitiveSet = new osg::DrawElementsUInt( osg::PrimitiveSet::QUADS, 0 );

            // Corners of quads should be in CCW order.
            spherePrimitiveSet->push_back( (r + 0) * sectors + (s + 0) );
            spherePrimitiveSet->push_back( (r + 0) * sectors + (s + 1) );
            spherePrimitiveSet->push_back( (r + 1) * sectors + (s + 1) );
            spherePrimitiveSet->push_back( (r + 1) * sectors + (s + 0) );

            addPrimitiveSet( spherePrimitiveSet );
        }
    }
    
    osg::ref_ptr< osg::Vec4Array > colors = new osg::Vec4Array;
    colors->push_back( osg::Vec4( 1.0f, 0.0f, 0.0f, 1.0f ) );
    //setColorArray( colors );
    //setColorBinding( osg::Geometry::BIND_OVERALL );
}
