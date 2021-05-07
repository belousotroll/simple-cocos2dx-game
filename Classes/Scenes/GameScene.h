#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"

#include "StateMachine/StateMachine.h"

class Hero;

class GameScene : public cocos2d::Scene
{
public /*methods*/:
    //! @brief Создает и возвращает сцену
    static cocos2d::Scene* createScene();
    //! @brief Инициализиирует сцену (супер-метод)
    virtual bool init();
    //! @brief Обновление сцены (каждый кадр)
    void update(const float pDeltaTime) final;

    CREATE_FUNC(GameScene);

private /*methods*/:

    //! @brief Обработывает нажатия клавиш
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode pKeyCode, cocos2d::Event* pEvent);
    //! @brief Обрабатывает клики мыши
    void onMouseDown(cocos2d::EventMouse* event);
    //! @brief Заменяет текущую игровую сцену на MenuScene.
    void goToMenuScene(cocos2d::Ref* pSender);
    //! @brief Настраивает обработчики событий для клавиатуры
    void initKeyboad();
    //! @brief Настраивает обработчики событий для мыши
    void initMouse();
    //! @brief Настраивает ui-элементы
    void initMenu();
    //! @brief Настраивает персонажа
    void initHero();

private /*attributes*/:

    //! @brief Управляемый игровой персонаж
    Hero* mHero = nullptr;
    //! @brief ...
    StateMachine mStateMachine;
};

#endif // __GAMESCENE_SCENE_H__
