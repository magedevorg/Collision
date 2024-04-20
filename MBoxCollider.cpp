#include "MBoxCollider.h"




void MBoxCollider::SetTransform(const MTransform& inTransform)
{
	// 회전값이 변경되었다면 축 갱신
	if (inTransform.Rotation != Transform.Rotation)
	{
		Axis.Reset();
		Axis.Rotation(inTransform.Rotation);
	}

	Transform = inTransform;
}
