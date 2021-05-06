#ifndef player_states_h
#define player_states_h

class Hero;

class IdleState;
class MoveState;
class AttackState;

//! @interface ...
class IState
{
public:
    static IdleState gIdleState;
    static MoveState gMoveState;
    static AttackState gAttackState;

    virtual ~IState() = default;
    virtual void exec(Hero*) noexcept  = 0;
    virtual void update(Hero*, const float) noexcept = 0;
    
protected:
    IState() = default;
};

class IdleState : public IState
{
public:
    IdleState() = default;
    virtual ~IdleState() override = default;
    virtual void exec(Hero* pHero) noexcept override;
    virtual void update(Hero*, const float) noexcept override;
};

class MoveState : public IState
{
public:
    MoveState() = default;
    virtual ~MoveState() override = default;
    virtual void exec(Hero* pHero) noexcept override;
    virtual void update(Hero*, const float) noexcept override;
};

class AttackState : public IState
{
public:
    AttackState() = default;
    virtual ~AttackState() override = default;
    virtual void exec(Hero* pHero)  noexcept override;
    virtual void update(Hero*, const float) noexcept override;
};

#endif