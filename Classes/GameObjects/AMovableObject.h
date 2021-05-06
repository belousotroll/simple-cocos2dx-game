#ifndef a_movable_object_h
#define a_movable_object_h

#include "cocos2d.h"

class AMovableObject
{
public:
	AMovableObject() = default;
	virtual ~AMovableObject() = default;

	void setSpeed(const float pSpeed);
	float getSpeed() const;

	void setDirectionToMove(const cocos2d::Vec2& pStartPoint, const cocos2d::Vec2& pFinalPoint);

	std::pair<float, float> getDirections() const;

	const cocos2d::Vec2& getFinalPoint() const;

protected:

	float mDirectionX;
	float mDirectionY;
	float mSpeed;

	cocos2d::Vec2 mFinalPoint;
};

#endif