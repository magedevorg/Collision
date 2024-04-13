#include "MCollision.h"



bool MCollision::CheckOBB(MBoxCollider& inBox1, MBoxCollider& inBox2)
{
	MVector3 distance = inBox2.GetPosition() - inBox1.GetPosition();

	if (true == SeperatingPlane(distance, inBox1.GetAxis()[0], inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, inBox1.GetAxis()[1], inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, inBox1.GetAxis()[2], inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, inBox2.GetAxis()[0], inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, inBox2.GetAxis()[1], inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, inBox2.GetAxis()[2], inBox1, inBox2)) {
		return false;
	}

	// cross(x)
	if (true == SeperatingPlane(distance, MVector3::CrossProduct(inBox1.GetAxis()[0], inBox2.GetAxis()[0]), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(inBox1.GetAxis()[0], inBox2.GetAxis()[1]), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(inBox1.GetAxis()[0], inBox2.GetAxis()[2]), inBox1, inBox2)) {
		return false;
	}

	// cross(y)
	if (true == SeperatingPlane(distance, MVector3::CrossProduct(inBox1.GetAxis()[1], inBox2.GetAxis()[0]), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(inBox1.GetAxis()[1], inBox2.GetAxis()[1]), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(inBox1.GetAxis()[1], inBox2.GetAxis()[2]), inBox1, inBox2)) {
		return false;
	}

	// cross(z)
	if (true == SeperatingPlane(distance, MVector3::CrossProduct(inBox1.GetAxis()[2], inBox2.GetAxis()[0]), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(inBox1.GetAxis()[2], inBox2.GetAxis()[1]), inBox1, inBox2)) {
		return false;
	}

	if (true == SeperatingPlane(distance, MVector3::CrossProduct(inBox1.GetAxis()[2], inBox2.GetAxis()[2]), inBox1, inBox2)) {
		return false;
	}

	return true;
}




bool MCollision::SeperatingPlane(const MVector3& inDistance, const MVector3& inBaseAxis, const MBoxCollider& inBox1, const MBoxCollider& inBox2)
{
	float val = fabsf(MVector3::DotProduct(inBaseAxis, inDistance));
	
	float val2 = 0;
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, inBox1.GetAxis()[0] * inBox1.GetHalfSize().X));
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, inBox1.GetAxis()[1] * inBox1.GetHalfSize().Y));
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, inBox1.GetAxis()[2] * inBox1.GetHalfSize().Z));

	val2 += fabsf(MVector3::DotProduct(inBaseAxis, inBox2.GetAxis()[0] * inBox2.GetHalfSize().X));
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, inBox2.GetAxis()[1] * inBox2.GetHalfSize().Y));
	val2 += fabsf(MVector3::DotProduct(inBaseAxis, inBox2.GetAxis()[2] * inBox2.GetHalfSize().Z));

	return val > val2;
}