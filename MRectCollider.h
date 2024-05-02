#pragma once


#include "MVector.h"



// 2D 직사삭형 충돌체
class MRectCollider
{
public:
	void Set(const MVector2& inLT, const MVector2& inRT, const MVector2& inLB, const MVector2& inRB)
	{
		LT = inLT;
		RT = inRT;
		LB = inLB;
		RB = inRB;
	}

	MVector2 GetCenterPos() const
	{
		MVector2 t1 = RT - LT;
		MVector2 t2 = LB - LT;

		return LT + ((t1 + t2) * 0.5f);
	}

	MVector2 GetRightVector() const
	{
		return (RT - LT) * 0.5f;
	}

	MVector2 GetUpVector() const
	{
		return (LT - LB) * 0.5f;
	}

public:
	MVector2 LT;
	MVector2 RT;
	MVector2 LB;
	MVector2 RB;
};