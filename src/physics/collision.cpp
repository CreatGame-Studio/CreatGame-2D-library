#include <cmath>

#include "collision.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/physics/collision.cpp
* \date 29.03.22 at 12:41
*************************************************/



bool cg2::physics::collision(cg2::Rect a, cg2::Rect b)
{
	if (a.x > b.x + b.w || a.y > b.y + b.h || a.x + a.w < b.x || a.y + a.h < b.y)
		return false;

	return true;
}



bool cg2::physics::collision(cg2::FRect a, cg2::FRect b)
{
	if (a.x > b.x + b.w || a.y > b.y + b.h || a.x + a.w < b.x || a.y + a.h < b.y)
		return false;

	return true;
}



bool cg2::physics::collision(cg2::Rect a, cg2::Point b)
{
	if (a.x > b.x || a.y > b.y || a.x + a.w < b.x || a.y + a.h < b.y)
		return false;

	return true;
}



bool cg2::physics::collision(cg2::FRect a, cg2::FPoint b)
{
	if (a.x > b.x || a.y > b.y || a.x + a.w < b.x || a.y + a.h < b.y)
		return false;

	return true;
}



bool cg2::physics::collision(cg2::Point a, cg2::Point b)
{
	if (a.x == b.x && a.y == b.y)
		return true;

	return false;
}



bool cg2::physics::collision(cg2::FPoint a, cg2::FPoint b)
{
	if (a.x == b.x && a.y == b.y)
		return true;

	return false;
}



bool cg2::physics::collision(cg2::Circle a, cg2::Circle b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float d = (float)sqrt((double)(dx * dx + dy * dy));

	if ((int)d > a.r + b.r)
		return false;

	return true;
}



bool cg2::physics::collision(cg2::FCircle a, cg2::FCircle b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float d = (float)sqrt((double)(dx * dx + dy * dy));

	if (d > a.r + b.r)
		return false;

	return true;
}



bool cg2::physics::collision(cg2::Circle a, cg2::Point b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float d = (float)sqrt((double)(dx * dx + dy * dy));

	if ((int)d > a.r)
		return false;

	return true;
}



bool cg2::physics::collision(cg2::FCircle a, cg2::FPoint b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float d = (float)sqrt((double)(dx * dx + dy * dy));

	if (d > a.r)
		return false;

	return true;
}



bool cg2::physics::collision(cg2::Rect a, cg2::Circle b)
{
	cg2::Point closest = {b.x, b.y};

	if (b.x  <= a.x)
		closest.x = a.x;

	else if (b.x >= a.x + a.w)
		closest.x = a.x + a.w;

	if (b.y  <= a.y)
		closest.y = a.y;

	else if (b.y >= a.y + a.h)
		closest.y = a.y + a.h;

	int dx = b.x - closest.x;
	int dy = b.y - closest.y;
	int d = (int)sqrt((double)(dx * dx + dy * dy));

	if (d > b.r)
		return false;

	return true;
}



bool cg2::physics::collision(cg2::FRect a, cg2::FCircle b)
{
	cg2::FPoint closest = {b.x, b.y};

	if (b.x  <= a.x)
		closest.x = a.x;

	else if (b.x >= a.x + a.w)
		closest.x = a.x + a.w;

	if (b.y  <= a.y)
		closest.y = a.y;

	else if (b.y >= a.y + a.h)
		closest.y = a.y + a.h;

	float dx = b.x - closest.x;
	float dy = b.y - closest.y;
	float d = (float)sqrt((double)(dx * dx + dy * dy));

	if (d > b.r)
		return false;

	return true;
}


