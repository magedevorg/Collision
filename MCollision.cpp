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

MBOOL MCollision::CheckOBB(MRect& inRect1, MRect& inRect2)
{
	// 사용할 벡터 정보
	std::array<MVector2, 4> valueList;		// 벡터 정보
	std::array<MVector2, 4> axisList;		// 축 정보(정규화)

	// 추가 함수
	auto AddFunc = [&axisList, &valueList](MINT32 inIndex, const MVector2& inVector)
		{
			valueList[inIndex] = inVector;
			axisList[inIndex] = inVector.GetNormal();
		};

	// 박스1의 위 / 오른쪽 벡터 추가
	AddFunc(0, inRect1.GetUpVector());
	AddFunc(1, inRect1.GetRightVector());

	// 박스2의 위 / 오른쪽 벡터 추가
	AddFunc(2, inRect2.GetUpVector());
	AddFunc(3, inRect2.GetRightVector());


	// 중앙 위치의 거리 벡터
	MVector2 distVector = inRect2.GetCenterPos() - inRect1.GetCenterPos();


	// 각 축 벡터에 정보를 투영하여 
	for (MINT32 i = 0; i < 4; ++i)
	{
		MFLOAT sum = 0;

		// 사용할 축을 얻는다
		const MVector2& axis = axisList[i];

		// 벡터를 축에 투영
		for (MINT32 c = 0; c < 4; ++c)
		{
			MFLOAT temp = MVector2::DotProduct(axis, valueList[c]);
			sum += abs(temp);
		}

		// 거리를 투영
		MFLOAT distance = MVector2::DotProduct(axis, distVector);
		distance = abs(distance);

		// 한 축이라도 
		// 합이 거리보다 작다면 충돌
		if (sum < distance) {
			return MFALSE;
		}
	}

	return MTRUE;
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


