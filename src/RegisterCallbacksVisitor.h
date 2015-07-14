/* 
 * File:   RegisterCallbacksVisitor.h
 * Author: allan
 *
 * Created on July 13, 2015, 6:51 PM
 */

#ifndef REGISTERCALLBACKSVISITOR_H
#define	REGISTERCALLBACKSVISITOR_H

#include "TimeCallback.h"

/* system */
/* osg */
#include <osg/NodeVisitor>


class RegisterCallbacksVisitor : public osg::NodeVisitor
{
public:
    
    /**
     * Constructor
     */
    RegisterCallbacksVisitor() 
        : osg::NodeVisitor( osg::NodeVisitor::TRAVERSE_ALL_CHILDREN ), 
            _timerCallback( new TimeCallback ) {};
    
    
    void apply( osg::Node& node )
    {
        node.setUpdateCallback( _timerCallback );
        traverse( node );
    }
    
private:
    
    osg::ref_ptr< TimeCallback > _timerCallback;

};

#endif	/* REGISTERCALLBACKSVISITOR_H */

