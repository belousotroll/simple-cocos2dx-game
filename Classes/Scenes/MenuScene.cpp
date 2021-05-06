#include "Scenes/MenuScene.h"

#include "Scenes/GameScene.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

bool MenuScene::init()
{
    if (false == Scene::init())
    {
        return false;
    }

    initMenu();
    initLabel();
    initKeyboad();

    return true;
}

void MenuScene::exit(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
}

void MenuScene::initKeyboad()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin      = Director::getInstance()->getVisibleOrigin();

    // Добавляем обработчик событий
    auto keyboadListener = EventListenerKeyboard::create();
    keyboadListener->onKeyPressed = CC_CALLBACK_2(MenuScene::onKeyPressed, this);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboadListener, this);
}

void MenuScene::initMenu()
{
    const auto visibleSize = Director::getInstance()->getVisibleSize();
    const auto origin      = Director::getInstance()->getVisibleOrigin();

    // Создаем элемент меню "Играть". При нажатии перенаправляет на игровую сцену.
    auto playItem = MenuItemImage::create("Buttons/PlayButton.png",
                                          "Buttons/PlayButton.png",
                                          CC_CALLBACK_1(MenuScene::goToGameScene, this));
    // Устанавливаем позицию элемента меню "Играть".
    playItem->setPosition(origin.x + (visibleSize.width * 0.5f),
                          origin.y + (visibleSize.height * 0.5f));

    // Создаем меню и добавляем туда созданные ранее элементы.
    auto menu = Menu::create(playItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
}

void MenuScene::initLabel()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin      = Director::getInstance()->getVisibleOrigin();

    // Создаем лейбл
    auto label = Label::createWithTTF("Press ESC to exit", "fonts/arial.ttf", 24);
    label->setPosition({ visibleSize.width * 0.5f, visibleSize.height * 0.2f });
    label->setTextColor(cocos2d::Color4B::WHITE);
    addChild(label);
}

void MenuScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode pKeyCode, cocos2d::Event* pEvent)
{
    switch (pKeyCode)
    {
        // При нажатии на клавишу ESC выходит из игры (нет классной иконки для кнопки выхода)
    case EventKeyboard::KeyCode::KEY_ESCAPE:
        Director::getInstance()->end();
        break;
    }
}

void MenuScene::goToGameScene(cocos2d::Ref* pSender)
{
    // Заменяем сцену ...
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, GameScene::createScene()));
}
