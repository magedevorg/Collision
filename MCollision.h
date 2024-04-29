#pragma once


#include "MBoxCollider.h"


class MCollision
{
public:
	static MBOOL CheckOBB( MBoxCollider& inBox1,  MBoxCollider& inBox2);

	static MBOOL CheckOBB(MRect& inRect1, MRect& inRect2);

	
	static bool SeperatingPlane(const MVector3& inDistance, const MVector3& inDirection, MBoxCollider& inBox1, MBoxCollider& inBox2);
};

