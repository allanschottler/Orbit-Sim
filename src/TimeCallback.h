/* 
 * File:   TimeCallback.h
 * Author: allan
 *
 * Created on July 13, 2015, 6:34 PM
 */

#ifndef TIMECALLBACK_H
#define	TIMECALLBACK_H

#include "TimeTransform.h"

/* system */
#include <iostream>

/* osg */
#include <osg/NodeCallback>


class TimeCallback : public osg::NodeCallback
{
public:
    
    TimeCallback() : _time( 0 ){};
    
    virtual void operator()( osg::Node* node, osg::NodeVisitor* nv )
    {        
        TimeTransform* timeTransform = dynamic_cast< TimeTransform* >( node );
    
        if( timeTransform )
            timeTransform->update( _time );
        
        traverse( node, nv );
        
        _time += DELTA_TIME;
    }
    
private:
    
    static const double DELTA_TIME = 0.005f;
    
    double _time;

};

#endif	/* TIMECALLBACK_H */

