#include "PlayerStates.h"
#include "GameObjects/Hero.h"

IdleState IState::gIdleState;
MoveState IState::gMoveState;
AttackState IState::gAttackState;

void IdleState::exec(Hero* pHero) noexcept
{
	auto skeletonAnimation = pHero->getSkeletonAnimation();
	skeletonAnimation->setAnimation(0, "idle", true);
}

void IdleState::update(Hero* pHero, const float pDeltaTime) noexcept
{
	// ��� �����, ��������, ��������������� ����� ���� ��������, ��� � CoD.
	return;
}

void MoveState::exec(Hero* pHero) noexcept
{
	// ����� �������� �� �����������.
	if (pHero->getState() == &IState::gMoveState)
	{
		return;
	}

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
		pHero->setStateAndExec(&IState::gIdleState);
	}
}

void AttackState::exec(Hero* pHero) noexcept
{
	auto skeletonAnimation = pHero->getSkeletonAnimation();
	skeletonAnimation->setAnimation(0, "attack", false);
}

void AttackState::update(Hero* pHero, const float pDeltaTime) noexcept
{
	// ��� �����, ��������, ��������� ������ "�������" ��� ���-�� ���.
	return;
}