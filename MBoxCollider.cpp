#include "MBoxCollider.h"



MBoxCollider::MBoxCollider()
	: Position(MVector3::Zero)
	, Size(MVector3::Zero)
{
}


MBoxCollider::MBoxCollider(const MVector3& inPosition, const MVector3& inSize)
{
	//Set(inPosition, inSize);
}



void MBoxCollider::Set(const MTransform& inTransform, const MVector3& inSize)
{
	Transform = inTransform;
	Size = inSize;
	HalfSize = Size;	// 임시

	Update();
}

void MBoxCollider::SetPosition(const MVector3& inPosition)
{
	Position = inPosition;
	Update();
}

void MBoxCollider::SetSize(const MVector3& inSize)
{
	Size = inSize;
	Update();
}


void MBoxCollider::Update()
{
	// 기본 위치
	MVector3 basePos = -Size;
	Vertices[0] = Transform.TransformPosition(basePos);

	// 
	{
		MVector3 tempPos = basePos;
		tempPos.X += (Size.X * 2);
	

		Vertices[1] = Transform.TransformPosition(tempPos);

		Axis[0] = Vertices[1] - Vertices[0];
		Axis[0].Normalize();
	}

	// 
	{
		MVector3 tempPos = basePos;
		tempPos.Y += (Size.Y * 2);
	
		Vertices[2] = Transform.TransformPosition(tempPos);

		Axis[1] = Vertices[2] - Vertices[0];
		Axis[1].Normalize();
	}


	{
		MVector3 tempPos = basePos;
		tempPos.Z += (Size.Z * 2);
		Vertices[3] = Transform.TransformPosition(tempPos);

		Axis[2] = Vertices[3] - Vertices[0];
		Axis[2].Normalize();
	}

}