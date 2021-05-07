#include "PlayerStates.h"
#include "GameObjects/Hero.h"
#include "StateMachine.h"

void IdleState::exec(Hero* pHero) noexcept
{
	auto skeletonAnimation = pHero->getSkeletonAnimation();
	skeletonAnimation->setAnimation(0, "idle", true);
}

void IdleState::update(Hero* pHero, const float pDeltaTime) noexcept
{
	// Тут можно, допустим, восстанавливать герою очки здоровья, как в CoD.
	return;
}

void MoveState::exec(Hero* pHero) noexcept
{
	auto skeletonAnimation = pHero->getSkeletonAnimation();
	skeletonAnimation->setAnimation(0, "move", true);
}

void MoveState::update(Hero* pHero, const float pDeltaTime) noexcept
{
	auto& heroPosition = pHero->getPosition();
	auto [_x, _y] = pHero->getDirections();

	pHero->setPosition({ heroPosition.x + _x * pHero->getSpeed(), heroPosition.y + _y * pHero->getSpeed() });

	if (pHero->getPosition().distance(pHero->getFinalPoint()) <= 5.f)
	{
		pHero->getState()->getStateMachine()->setState<IdleState>(pHero);
	}
}

void AttackState::exec(Hero* pHero) noexcept
{
	auto skeletonAnimation = pHero->getSkeletonAnimation();
	skeletonAnimation->setAnimation(0, "attack", false);
}

void AttackState::update(Hero* pHero, const float pDeltaTime) noexcept
{
	if (const auto track = pHero->getSkeletonAnimation()->getCurrent(); 
		track->trackTime >= track->animationEnd)
	{
		pHero->getState()->getStateMachine()->setState<IdleState>(pHero);
	}

	return;
}