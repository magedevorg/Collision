#pragma once


#include "MVector.h"
#include "MTransform.h"

#include "MAxis.h"


class MBoxCollider
{
public:
	MBoxCollider() {
		SetSize(MVector3(100.0f,100.0f,100.0f));
	}

	MBoxCollider(const MTransform& inTransform, const MVector3& inSize) 
	{
		Set(inTransform, inSize);
	}

public:
	// ����
	void Set(const MTransform& inTransform, const MVector3& inSize) 
	{
		SetTransform(inTransform);
		SetSize(inSize);
	}

	void SetSize(const MVector3& inSize) {
		HalfSize = inSize * 0.5f;
	}

	void SetTransform(const MTransform& inTransform);

	const MVector3& GetHalfSize() const {
		return HalfSize;
	}

	const MTransform& GetTransform() {
		return Transform;
	}

	const MAxis3& GetAxis() const {
		return Axis;
	}


	// ����Ʈ ����Ʈ�� ��´�
	void GetPointList(std::vector<MVector3>& inPointList)
	{
		MMatrix4 transformMatrix = Transform.GetMatrix();

		auto AddPointListFunc = [&](float inX, float inY, float inZ)
			{
				inPointList.push_back(transformMatrix * MVector3(inX, inY, inZ));
			};

		// �߰�
		AddPointListFunc(-HalfSize.X, -HalfSize.Y, -HalfSize.Z);	// 0
		AddPointListFunc(HalfSize.X, -HalfSize.Y, -HalfSize.Z);		// 1
		AddPointListFunc(HalfSize.X, -HalfSize.Y, HalfSize.Z);		// 2
		AddPointListFunc(-HalfSize.X, -HalfSize.Y, HalfSize.Z);		// 3

		AddPointListFunc(-HalfSize.X, HalfSize.Y, -HalfSize.Z);		// 0
		AddPointListFunc(HalfSize.X, HalfSize.Y, -HalfSize.Z);		// 1
		AddPointListFunc(HalfSize.X, HalfSize.Y, HalfSize.Z);		// 2
		AddPointListFunc(-HalfSize.X, HalfSize.Y, HalfSize.Z);		// 3
	}




protected:
	// ��ȯ(��ġ/ȸ��/������) ����
	MTransform Transform;

	// ũ�� ����
	MVector3 HalfSize;

	// �� ����
	MAxis3 Axis;
};



// �簢��(�ӽ� ���߿� �Űܾ���)
class MRect
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