#include "MBoxCollider.h"




void MBoxCollider::SetTransform(const MTransform& inTransform)
{
	// ȸ������ ����Ǿ��ٸ� �� ����
	if (inTransform.Rotation != Transform.Rotation)
	{
		Axis.Reset();
		Axis.Rotation(inTransform.Rotation);
	}

	Transform = inTransform;
}
