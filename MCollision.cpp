#include "MCollision.h"



bool MCollision::CheckOBB(MBoxCollider& inBox1, MBoxCollider& inBox2)
{
	MVector3 distance = inBox2.GetTransform().Position - inBox1.GetTransform().Position;

	const MAxis3& box1Axis = inBox1.GetAxis();
	const MAxis3& box2Axis = inBox2.GetAxis();

	if (true == SeperatingPlane(distance, box1Axis.GetX(), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, box1Axis.GetY(), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, box1Axis.GetZ(), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, box2Axis.GetX(), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, box2Axis.GetY(), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, box2Axis.GetZ(), inBox1, inBox2)) {
		return false;
	}

	// cross(x)
	if (true == SeperatingPlane(distance, MVector3::CrossProduct(box1Axis.GetX(), box2Axis.GetX()), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(box1Axis.GetX(), box2Axis.GetY()), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(box1Axis.GetX(), box2Axis.GetZ()), inBox1, inBox2)) {
		return false;
	}

	// cross(y)
	if (true == SeperatingPlane(distance, MVector3::CrossProduct(box1Axis.GetY(), box2Axis.GetX()), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(box1Axis.GetY(), box2Axis.GetY()), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(box1Axis.GetY(), box2Axis.GetZ()), inBox1, inBox2)) {
		return false;
	}

	// cross(z)
	if (true == SeperatingPlane(distance, MVector3::CrossProduct(box1Axis.GetZ(), box2Axis.GetX()), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(box1Axis.GetZ(), box2Axis.GetY()), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(box1Axis.GetZ(), box2Axis.GetZ()), inBox1, inBox2)) {
		return false;
	}

	return true;
}




bool MCollision::SeperatingPlane(const MVector3& inDistance, const MVector3& inBaseAxis, MBoxCollider& inBox1, MBoxCollider& inBox2)
{
	float val = fabsf(MVector3::DotProduct(inBaseAxis, inDistance));

	const MAxis3& box1Axis = inBox1.GetAxis();
	const MAxis3& box2Axis = inBox2.GetAxis();
	
	float val2 = 0;
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, box1Axis.GetX() * inBox1.GetHalfSize().X));
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, box1Axis.GetY() * inBox1.GetHalfSize().Y));
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, box1Axis.GetZ() * inBox1.GetHalfSize().Z));

	val2 += fabsf(MVector3::DotProduct(inBaseAxis, box2Axis.GetX() * inBox2.GetHalfSize().X));
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, box2Axis.GetY() * inBox2.GetHalfSize().Y));
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, box2Axis.GetZ() * inBox2.GetHalfSize().Z));

	return val > val2;
}