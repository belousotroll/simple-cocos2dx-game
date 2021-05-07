#ifndef a_movable_object_h
#define a_movable_object_h

#include "cocos2d.h"

class AMovableObject
{
public:
	//! @brief ����������� �����������
	AMovableObject() = default;
	//! @brief ����������� ����������
	virtual ~AMovableObject() = default;
	//! @brief ������������� �������� ������������
	void setSpeed(const float pSpeed);
	//! @brief ���������� �������� ������������
	float getSpeed() const;
	//! @brief ������������� ������������ �������� �� Ox & Oy � ������ ����� ����������
	void setDirectionToMove(const cocos2d::Vec2& pStartPoint, const cocos2d::Vec2& pFinalPoint);
	//! @brief ���������� ������������ �������� �� ���� x � y
	std::pair<float, float> getDirections() const;
	//! @brief ���������� ����� ����������
	const cocos2d::Vec2& getFinalPoint() const;

protected:
	//! @brief �������� �� ��� X
	float mDirectionX;
	//! @brief �������� �� ��� Y
	float mDirectionY;
	//! @brief �������� ��������
	float mSpeed;
	//! @brief ����� ����������
	cocos2d::Vec2 mFinalPoint;
};

#endif