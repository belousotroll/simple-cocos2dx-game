#ifndef state_machine_h
#define state_machine_h

#include "PlayerStates.h"
#include "GameObjects/Hero.h"

#include <unordered_map>
#include <memory>

class StateMachine
{

public:

	StateMachine() noexcept = default;
	~StateMachine() noexcept { clearAll(); }

	//! @brief ������� ���������
	void clearAll() noexcept
	{
		for (auto& element : mHeroToState)
		{
			delete element.second;
		}
	}

	//! @brief ���� ��������� @a State � ������� @param pHero
	template <class State>
	void setState(Hero* pHero)
	{
		// ���� ��� ������� ������ ���������, ��������� �������� ...
		if (pHero == nullptr) return;

		auto state = findState<State>(pHero);
		// ���� �� ���� ������� ������ ���������, ������� ��� �
		// ��������� � ���������.
		if (state == nullptr)
		{
			state = new State;
			state->setStateMachine(this);
			mHeroToState.insert({ pHero, state });
		}
		// ���� ������ ��� �������� ���� ����������, ��������� ��������.
		else if (state == pHero->getState()) return;

		// ��������� ���������� ���������
		pHero->setStateAndExec(state);
	}
private /*methods*/:

	//! @brief ����� ��������� � ������� @a pHero 
	template <class State>
	State* findState(Hero* pHero)
	{
		const auto range = mHeroToState.equal_range(pHero);
		for (auto iter = range.first; iter != range.second; iter++)
		{
			State temp;
			// todo: *
			if (iter->second->getName() == temp.getName())
			{
				return static_cast<State*>(iter->second);
			}
		}

		return nullptr;
	}

private /*attributes*/:
	std::unordered_multimap<Hero*, IState*> mHeroToState;
};

#endif