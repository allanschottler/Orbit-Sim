/* 
 * File:   TextureFactory.h
 * Author: allan
 *
 * Created on July 12, 2015, 9:18 PM
 */

#ifndef TEXTUREFACTORY_H
#define	TEXTUREFACTORY_H

/* system */
#include <map>
#include <string>

/* osg */
#include <osg/Texture2D>


class TextureFactory 
{
public:
    
    /**
     * Returns unique instance
     * @return 
     */
    static TextureFactory* getInstance();
    
    /**
     * Destructor
     */
    virtual ~TextureFactory();
    
    /**
     * Returns a unique 2d texture
     * @param imagePath
     * @return 
     */
    osg::ref_ptr< osg::Texture2D > getTexture2D( std::string imagePath );
    
private:
    
    /**
     * Private constructor
     */
    TextureFactory();
    
    /* Unique instance */
    static TextureFactory* _instance;    
    
    /* Unique geometry instances */
    std::map< std::string, osg::ref_ptr< osg::Texture2D > > _uniqueTextures2D;
};

#endif	/* TEXTUREFACTORY_H */

