#include "Scenes/GameScene.h"
#include "Scenes/MenuScene.h"

#include "SimpleAudioEngine.h"

#include "GameObjects/Hero.h"
#include "StateMachine/PlayerStates.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	return GameScene::create();
}

bool GameScene::init()
{
	if (false == Scene::init())
	{
		return false;
	}

	initHero();
	initMenu();
	initKeyboad();
	initMouse();
	scheduleUpdate();

	return true;
}

void GameScene::update(const float pDeltaTime)
{
	mHero->update(pDeltaTime);
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode pKeyCode, Event* pEvent)
{
	switch (pKeyCode)
	{
		// Клавиша "S" останавливает любое действие, как во всех MOBA-играх.
	case EventKeyboard::KeyCode::KEY_S:
		mHero->setStateAndExec(&IState::gIdleState);
		return;
		// Клавиша "W" заставляет персонажа атаковать
	case EventKeyboard::KeyCode::KEY_W:
		mHero->setStateAndExec(&IState::gAttackState);
		return;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		goToMenuScene(this);
		break;
	}
}

void GameScene::onMouseDown(EventMouse* event)
{
	if (event->getMouseButton() == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)
	{
		// @todo Разделить обязаности между AMovableObject и самим перемещением

		// Настраиваем атрибуты персонажа для корректного перемещения
		mHero->setDirectionToMove(mHero->getPosition(), event->getLocationInView());
		// Меняем состояние на "В движении".
		mHero->setStateAndExec(&IState::gMoveState);
	}
}

void GameScene::goToMenuScene(Ref* pSender)
{
	Director::getInstance()->replaceScene(MenuScene::create());
}

void GameScene::initKeyboad()
{
	// Добавляем обработчик нажатий кнопок клавиши
	auto keyboadListener = EventListenerKeyboard::create();
	keyboadListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboadListener, this);
}

void GameScene::initMouse()
{
	// Добавляем обработчик нажатий кнопок мыши
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(GameScene::onMouseDown, this);
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
}

void GameScene::initMenu()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// Создаем элемент меню
	auto backToMenuItem = MenuItemImage::create("Buttons/MenuButton.png",
												"Buttons/MenuButton.png",
												CC_CALLBACK_1(GameScene::goToMenuScene, this));

	// Устанавливаем позицию элемента меню
	backToMenuItem->setPosition(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.9F);

	// Создаем меню и добавляем туда созданные ранее элементы
	auto menu = Menu::create(backToMenuItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 100);
}

void GameScene::initHero()
{
	// Создаем героя
	mHero = Hero::create();
	// Устанавливаем его позицию на экране
	mHero->setPosition({ _contentSize.width * 0.5f, _contentSize.height * 0.5f });
	// Устанавливаем скорость перемещения персонажа
	mHero->setSpeed(5.f);
	// Добавляем его в objectPool
	addChild(mHero);
}
