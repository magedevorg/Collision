#pragma once


#include "MBoxCollider.h"


class MCollision
{
public:
	static bool CheckOBB( MBoxCollider& inBox1,  MBoxCollider& inBox2);

	
	static bool SeperatingPlane(const MVector3& inDistance, const MVector3& inDirection, MBoxCollider& inBox1, MBoxCollider& inBox2);
};

