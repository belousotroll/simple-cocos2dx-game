#ifndef a_movable_object_h
#define a_movable_object_h

#include "cocos2d.h"

class AMovableObject
{
public:
	//! @brief Стандартный конструктор
	AMovableObject() = default;
	//! @brief Виртуальный деструктор
	virtual ~AMovableObject() = default;
	//! @brief Устанавливает скорость передвижения
	void setSpeed(const float pSpeed);
	//! @brief Возвращает скорость передвижения
	float getSpeed() const;
	//! @brief Устанавливает коэффициенты смещения по Ox & Oy и задает пункт назначения
	void setDirectionToMove(const cocos2d::Vec2& pStartPoint, const cocos2d::Vec2& pFinalPoint);
	//! @brief Возвращает коэффициенты смещения по осям x и y
	std::pair<float, float> getDirections() const;
	//! @brief Возвращает пункт назначения
	const cocos2d::Vec2& getFinalPoint() const;

protected:
	//! @brief Смещение по оси X
	float mDirectionX;
	//! @brief Смещение по оси Y
	float mDirectionY;
	//! @brief Скорость смещения
	float mSpeed;
	//! @brief Пункт назначения
	cocos2d::Vec2 mFinalPoint;
};

#endif