#if !defined(__CG2_PHYSICS_COLLISION_HPP__)
#define __CG2_PHYSICS_COLLISION_HPP__

#include "../drawable.hpp"
#include "../types.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/physics/collision.hpp
* \date 29.03.22 at 12:29
*************************************************/

namespace cg2::physics
{
	bool collision(cg2::Rect a, cg2::Rect b);
	bool collision(cg2::FRect a, cg2::FRect b);

	bool collision(cg2::Rect a, cg2::Point b);
	bool collision(cg2::FRect a, cg2::FPoint b);

	bool collision(cg2::Point a, cg2::Point b);
	bool collision(cg2::FPoint a, cg2::FPoint b);

	bool collision(cg2::Circle a, cg2::Circle b);
	bool collision(cg2::FCircle a, cg2::FCircle b);

	bool collision(cg2::Circle a, cg2::Point b);
	bool collision(cg2::FCircle a, cg2::FPoint b);

	bool collision(cg2::Rect a, cg2::Circle b);
	bool collision(cg2::FRect a, cg2::FCircle b);
}

#endif