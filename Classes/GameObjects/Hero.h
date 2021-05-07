#ifndef hero_h
#define hero_h

#include "cocos2d.h"
#include "spine/SkeletonAnimation.h"
#include "AMovableObject.h"

class IState;

//! @class ����� �������� ������� "�����".
class Hero : public AMovableObject, public cocos2d::Node
{
	//! @brief ��������� �����������
	Hero();

public:
	//! @brief ����������� ����������
	~Hero() override = default;
	//! @brief ������� ��������� ������ "�����"
	static Hero* create();
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
	IState* mState;
	//! @brief ��������� ��������
	spine::SkeletonAnimation* mSkeleton;
};

#endif