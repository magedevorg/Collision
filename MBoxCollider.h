#pragma once


#include "MVector.h"


class MBoxCollider
{
public:
	MBoxCollider();
	MBoxCollider(const MVector3& inPosition, const MVector3& inSize);

public:
	// ����
	void Set(const MVector3& inPosition, const MVector3& inSize);

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
		return Position;
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
};