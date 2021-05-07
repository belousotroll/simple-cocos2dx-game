#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"

#include "StateMachine/StateMachine.h"

class Hero;

class GameScene : public cocos2d::Scene
{
public /*methods*/:
    //! @brief ������� � ���������� �����
    static cocos2d::Scene* createScene();
    //! @brief ��������������� ����� (�����-�����)
    virtual bool init();
    //! @brief ���������� ����� (������ ����)
    void update(const float pDeltaTime) final;

    CREATE_FUNC(GameScene);

private /*methods*/:

    //! @brief ������������ ������� ������
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode pKeyCode, cocos2d::Event* pEvent);
    //! @brief ������������ ����� ����
    void onMouseDown(cocos2d::EventMouse* event);
    //! @brief �������� ������� ������� ����� �� MenuScene.
    void goToMenuScene(cocos2d::Ref* pSender);
    //! @brief ����������� ����������� ������� ��� ����������
    void initKeyboad();
    //! @brief ����������� ����������� ������� ��� ����
    void initMouse();
    //! @brief ����������� ui-��������
    void initMenu();
    //! @brief ����������� ���������
    void initHero();

private /*attributes*/:

    //! @brief ����������� ������� ��������
    Hero* mHero = nullptr;
    //! @brief ...
    StateMachine mStateMachine;
};

#endif // __GAMESCENE_SCENE_H__
