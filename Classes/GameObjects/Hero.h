#ifndef hero_h
#define hero_h

#include "cocos2d.h"
#include "spine/SkeletonAnimation.h"
#include "AMovableObject.h"

class IState;

//! @class Класс игрового объекта "Герой".
class Hero : public cocos2d::Node, public AMovableObject
{
	//! @brief Приватный конструктор
	Hero();
public:
	//! @brief Создает экземпляр класса "Герой"
	static Hero* create();
	//! @brief Обновляет поворот персонажа
	void updateFlipping();
	//! @brief Устанавливает состояние персонажа и выполняет его
	void setStateAndExec(IState* pState);
	//! @brief Возвращает текущее состояние персонажа
	IState* getState() const;
	//! @brief Обновление
	void update(float pDeltaTime) override;
	//! @brief Возвращает текущую скелетную анимацию
	spine::SkeletonAnimation* getSkeletonAnimation() const;

private:
	//! @brief Текущее состояние персонажа
	IState* mCurrentState;
	//! @brief Скелетная анимация
	spine::SkeletonAnimation* mSkeleton;
};

#endif