#pragma once


#include "MVector.h"

#include "MTransform.h"


class MBoxCollider
{
public:
	MBoxCollider();
	MBoxCollider(const MVector3& inPosition, const MVector3& inSize);

public:
	// ����
	void Set(const MTransform& inTransform, const MVector3& inSize);


	

	void SetPosition(const MVector3& inPosition);
	void SetSize(const MVector3& inSize);

	// 
	const std::array<MVector3, 4>& GetVertices() {
		return Vertices;
	}

	const std::array<MVector3, 3>& GetAxis() const {
		return Axis;
	}

	const MVector3& GetPosition() {
		return Transform.GetLocation();
	}

	// ���� ������
	const MVector3& GetHalfSize() const {
		return HalfSize;
	}

protected:
	void Update();

protected:
	// ��ġ
	MVector3 Position;

	// ũ��
	MVector3 Size;

	// 
	MVector3 HalfSize;

	// ���� ����Ʈ
	std::array<MVector3, 4> Vertices;


	// �� ����
	std::array<MVector3, 3> Axis;


	MTransform Transform;
};