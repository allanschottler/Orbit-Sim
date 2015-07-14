/* 
 * File:   TimeTransform.h
 * Author: allan
 *
 * Created on July 13, 2015, 6:39 PM
 */

#ifndef TIMETRANSFORM_H
#define	TIMETRANSFORM_H

/* system */
/* osg */
#include <osg/MatrixTransform>


class TimeTransform : public osg::MatrixTransform
{
public:

    TimeTransform() {};
    
    virtual ~TimeTransform() {};
    
    virtual void update( double dt ) = 0;
    
private:

};

#endif	/* TIMETRANSFORM_H */

