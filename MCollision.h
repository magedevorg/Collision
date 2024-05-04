#pragma once

#include "MVector.h"

class MCollision
{
public:
	static MBOOL CheckOBB( const class MBoxCollider& inBox1, const class MBoxCollider& inBox2);

	static MBOOL CheckOBB(const class MRectCollider& inRect1, const class MRectCollider& inRect2);

	
	static bool SeperatingPlane(const MVector3& inDistance, const MVector3& inDirection, const class MBoxCollider& inBox1, const class MBoxCollider& inBox2);
};


// test