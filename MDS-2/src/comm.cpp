/*
 * comm.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: lizhifeng
 */

#include "comm.hpp"

float timeval_sub(timeval &stop, timeval &start){

	float time_elapsed = (stop.tv_sec - start.tv_sec) + float(stop.tv_usec - start.tv_usec)/1000000.0f;
	return time_elapsed;
}
