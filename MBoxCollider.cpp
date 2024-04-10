#include "MBoxCollider.h"



MBoxCollider::MBoxCollider()
	: Position(MVector3::Zero)
	, Size(MVector3::Zero)
{
}


MBoxCollider::MBoxCollider(const MVector3& inPosition, const MVector3& inSize)
{
	Set(inPosition, inSize);
}



void MBoxCollider::Set(const MVector3& inPosition, const MVector3& inSize)
{
	Position = inPosition;
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
	Vertices[0] = Position - Size;
	
	// 
	{
		Vertices[1] = Vertices[0];
		Vertices[1].X += (Size.X * 2);

		Axis[0] = Vertices[1] - Vertices[0];
		Axis[0].Normalize();
	}

	// 
	{
		Vertices[2] = Vertices[0];
		Vertices[2].Y += (Size.Y * 2);

		Axis[1] = Vertices[2] - Vertices[0];
		Axis[1].Normalize();
	}
	

	{
		Vertices[3] = Vertices[0];
		Vertices[3].Z += (Size.Z * 2);

		Axis[2] = Vertices[3] - Vertices[0];
		Axis[2].Normalize();
	}
	
}