#include "GameObjects/Hero.h"

#include "StateMachine/PlayerStates.h"

Hero::Hero()
{
	mSkeleton = spine::SkeletonAnimation::createWithJsonFile("hero_2.json", "hero_2.atlas");
	setStateAndExec(&IState::gIdleState);
	addChild(mSkeleton);
}

Hero* Hero::create()
{
	Hero* hero = new (std::nothrow) Hero;
	
	if (hero && hero->init())
	{
		hero->autorelease();
		hero->setStateAndExec(new IdleState);
		return hero;
	}
	
	CC_SAFE_DELETE(hero);
	return nullptr;
}

void Hero::updateFlipping()
{
	setScaleX(getScaleX() * (mDirectionX > 0.f) ? -1.f : 1.f);
}

void Hero::setStateAndExec(IState* pState)
{
	pState->exec(this);
	mCurrentState = pState;
}

IState* Hero::getState() const
{
	return mCurrentState;
}

void Hero::update(float pDeltaTime)
{
	updateFlipping();
	mCurrentState->update(this, pDeltaTime);
}

spine::SkeletonAnimation* Hero::getSkeletonAnimation() const
{
	return mSkeleton;
}
