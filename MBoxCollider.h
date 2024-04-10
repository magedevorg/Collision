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
	const std::array<MVector3, 4>& GetVertices() const {
		return Vertices;
	}

protected:
	void Update();

protected:
	// ��ġ
	MVector3 Position;

	// ũ��
	MVector3 Size;

	// ���� ����Ʈ
	std::array<MVector3, 4> Vertices;
};