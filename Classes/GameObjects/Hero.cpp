#include "GameObjects/Hero.h"

#include "StateMachine/PlayerStates.h"

Hero::Hero()
	: mSkeleton(spine::SkeletonAnimation::createWithJsonFile("hero_2.json", "hero_2.atlas"))
	, mState(nullptr)
{
	addChild(mSkeleton);
}

Hero* Hero::create()
{
	Hero* hero = new (std::nothrow) Hero;
	
	if (hero && hero->init())
	{
		hero->autorelease();
		return hero;
	}
	
	CC_SAFE_DELETE(hero);
	return nullptr;
}

void Hero::setStateAndExec(IState* pState)
{
	pState->exec(this);
	mState = pState;
}

IState* Hero::getState() const
{
	return mState;
}

void Hero::update(float pDeltaTime)
{
	// ≈сли нет состо€ни€, прерываем операцию...
	if (mState == nullptr) return;

	const auto updateScale = [&](bool curScale, bool curDirection)
	{
		if (curScale == curDirection) setScaleX(getScaleX() * -1.f);
	};

	updateScale(getScaleX() > 0.f, mDirectionX > 0.f);

	mState->update(this, pDeltaTime);
}

spine::SkeletonAnimation* Hero::getSkeletonAnimation() const
{
	return mSkeleton;
}