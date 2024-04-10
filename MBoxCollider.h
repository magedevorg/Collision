#pragma once


#include "MVector.h"


class MBoxCollider
{
public:
	MBoxCollider();
	MBoxCollider(const MVector3& inPosition, const MVector3& inSize);

public:
	// 설정
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

	// 하프 사이즈
	const MVector3& GetHalfSize() const {
		return HalfSize;
	}

protected:
	void Update();

protected:
	// 위치
	MVector3 Position;

	// 크기
	MVector3 Size;

	// 
	MVector3 HalfSize;

	// 라인 리스트
	std::array<MVector3, 4> Vertices;


	// 축 정보
	std::array<MVector3, 3> Axis;
};