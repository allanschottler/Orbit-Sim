/* 
 * File:   TextureFactory.cpp
 * Author: allan
 * 
 * Created on July 12, 2015, 9:18 PM
 */

#include "TextureFactory.h"

/* osg */
#include <osgDB/ReadFile>

TextureFactory* TextureFactory::_instance = 0;


TextureFactory* TextureFactory::getInstance()
{
    if( !_instance )
        _instance = new TextureFactory();
    
    return _instance;
}


osg::ref_ptr< osg::Texture2D > TextureFactory::getTexture2D( std::string imagePath )
{
    osg::ref_ptr< osg::Image > image = osgDB::readImageFile( imagePath );   
    
    if( !_uniqueTextures2D.count( image->getFileName() ) )
    {          
        image->flipHorizontal(); 
        osg::ref_ptr< osg::Texture2D > texture = new osg::Texture2D;
        
        texture->setImage( image );
        texture->setFilter( osg::Texture::MIN_FILTER, osg::Texture::LINEAR );
        texture->setFilter( osg::Texture::MAG_FILTER, osg::Texture::LINEAR );
        texture->setWrap( osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_BORDER );
        texture->setWrap( osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_BORDER );        
        
        _uniqueTextures2D[ image->getFileName() ] = texture;
    }
    
    return _uniqueTextures2D[ image->getFileName() ];
}
