#ifndef player_states_h
#define player_states_h

#include <string_view>

class Hero;
class StateMachine;

//! @interface ...
class IState
{
public:
    virtual ~IState() = default;
    //! @brief �������� �������������. ����� ��� ��������� � �����������, �� ��� ���� ... 
    virtual void exec(Hero*) noexcept  = 0;
    //! @brief ����������
    virtual void update(Hero*, const float) noexcept = 0;
    //! @brief ���������� ��� ���������
    virtual std::string_view getName() const noexcept = 0;

    //! @brief ���������� ������ ���������
    StateMachine * const getStateMachine() noexcept { return mStateMachine; }
    //! @brief ������������� ������ ���������
    void setStateMachine(StateMachine* pStateMachine) noexcept { mStateMachine = pStateMachine; }
    
protected:
    IState() = default;
    StateMachine* mStateMachine = nullptr;
};

class IdleState : public IState
{
public:
    IdleState() = default;
    ~IdleState() override = default;
    void exec(Hero* pHero) noexcept override;
    void update(Hero*, const float) noexcept override;
    std::string_view getName() const noexcept override { return "IdleState"; }
};

class MoveState : public IState
{
public:
    MoveState() = default;
    ~MoveState() override = default;
    void exec(Hero* pHero) noexcept override;
    void update(Hero*, const float) noexcept override;
    std::string_view getName() const noexcept override { return "MoveState"; }
};

class AttackState : public IState
{
public:
    AttackState() = default;
    ~AttackState() override = default;
    void exec(Hero* pHero)  noexcept override;
    void update(Hero*, const float) noexcept override;
    std::string_view getName() const noexcept override { return "AttackState"; }
};

#endif