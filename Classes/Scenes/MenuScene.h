#ifndef __MENUSCENE_SCENE_H__
#define __MENUSCENE_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene
{
public:
    //! @brief ������� � ���������� �����
    static cocos2d::Scene* createScene();
    //! @brief ��������������� ����� (�����-�����)
    virtual bool init();

    CREATE_FUNC(MenuScene);

private /*methods*/:
    //! @brief ����������� ����������� ������� ��� ����������
    void initKeyboad();
    //! @brief ����������� ui-�������� (����)
    void initMenu();
    //! @brief ����������� ui-�������� (�������)
    void initLabel();
    //! @brief ������������ ������� ������
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode pKeyCode, cocos2d::Event* pEvent);
    //! @brief ��������� ������� �����
    void goToGameScene(cocos2d::Ref* pSender);
    //! @brief ��������� ����������
    void exit(cocos2d::Ref* pSender);
};

#endif // __GAMESCENE_SCENE_H__
