#include "AMovableObject.h"

void AMovableObject::setDirectionToMove(const cocos2d::Vec2& pStartPoint, const cocos2d::Vec2& pFinalPoint)
{
	// Расстояние от пункта назначения до персонажа
	const auto distance = pFinalPoint.distance(pStartPoint);
	// Коэффициент смещения по осям координат
	mDirectionX = (pFinalPoint.x - pStartPoint.x) / distance;
	mDirectionY = (pFinalPoint.y - pStartPoint.y) / distance;

	// Запоминаем конечный пункт назначения
	mFinalPoint = pFinalPoint;
}

std::pair<float, float> AMovableObject::getDirections() const
{
	return { mDirectionX, mDirectionY };
}

const cocos2d::Vec2& AMovableObject::getFinalPoint() const
{
	return mFinalPoint;
}

void AMovableObject::setSpeed(const float pSpeed)
{
	mSpeed = pSpeed;
}

float AMovableObject::getSpeed() const
{
	return mSpeed;
}