#ifndef hero_h
#define hero_h

#include "cocos2d.h"
#include "spine/SkeletonAnimation.h"
#include "AMovableObject.h"

class IState;

//! @class ����� �������� ������� "�����".
class Hero : public cocos2d::Node, public AMovableObject
{
	//! @brief ��������� �����������
	Hero();
public:
	//! @brief ������� ��������� ������ "�����"
	static Hero* create();
	//! @brief ��������� ������� ���������
	void updateFlipping();
	//! @brief ������������� ��������� ��������� � ��������� ���
	void setStateAndExec(IState* pState);
	//! @brief ���������� ������� ��������� ���������
	IState* getState() const;
	//! @brief ����������
	void update(float pDeltaTime) override;
	//! @brief ���������� ������� ��������� ��������
	spine::SkeletonAnimation* getSkeletonAnimation() const;

private:
	//! @brief ������� ��������� ���������
	IState* mCurrentState;
	//! @brief ��������� ��������
	spine::SkeletonAnimation* mSkeleton;
};

#endif