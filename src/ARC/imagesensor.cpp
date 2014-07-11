/*
 * =====================================================================================
 *
 *       Filename:  imagesensor.cpp
 *
 *    Description:  ImageSensor class implementation. Retrieves latest body
 *    frame data from a file and stores matched features in a vector.
 *
 *        Version:  1.0
 *        Created:  06/24/2014 11:39:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Martin Miller (MHM), miller7@illinois.edu
 *   Organization:  Aerospace Robotics and Controls Lab (ARC)
 *
 * =====================================================================================
 */
#include "imagesensor.hpp"




/*
 *--------------------------------------------------------------------------------------
 *       Class:  ImageSensor
 *      Method:  ImageSensor :: get_projections
 * Description:  Writes latest data to vector of matches.
 *--------------------------------------------------------------------------------------
 */
    void
ImageSensor::get_projections ( )
{
    matches.clear();
    projection pj;
    char str[20];
    strcpy( str, (isHex) ? "%d,%lx,%lx,%lx,%lx" : "%d,%lf,%lf,%lf,%lf" );
    while( get_val( fp, "image", str, &pj.id,&pj.source.x, &pj.source.y, 
                &pj.reflection.x, &pj.reflection.y )!=-1 )
    {
        matches.push_back(pj);
    }
    return ;
}		/* -----  end of method imageSensor::get_projections  ----- */

