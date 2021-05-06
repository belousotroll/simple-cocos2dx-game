#ifndef __MENUSCENE_SCENE_H__
#define __MENUSCENE_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene
{
public:
    //! @brief Создает и возвращает сцену
    static cocos2d::Scene* createScene();
    //! @brief Инициализиирует сцену (супер-метод)
    virtual bool init();

    CREATE_FUNC(MenuScene);

private /*methods*/:
    //! @brief Настраивает обработчики событий для клавиатуры
    void initKeyboad();
    //! @brief Настраивает ui-элементы (меню)
    void initMenu();
    //! @brief Настраивает ui-элементы (надписи)
    void initLabel();
    //! @brief Обработывает нажатия клавиш
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode pKeyCode, cocos2d::Event* pEvent);
    //! @brief Запускает игровую сцену
    void goToGameScene(cocos2d::Ref* pSender);
    //! @brief Закрывает приложение
    void exit(cocos2d::Ref* pSender);
};

#endif // __GAMESCENE_SCENE_H__
