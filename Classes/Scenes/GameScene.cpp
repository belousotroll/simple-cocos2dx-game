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
		// ������� "S" ������������� ����� ��������, ��� �� ���� MOBA-�����.
	case EventKeyboard::KeyCode::KEY_S:
		mHero->setStateAndExec(&IState::gIdleState);
		return;
		// ������� "W" ���������� ��������� ���������
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
		// @todo ��������� ���������� ����� AMovableObject � ����� ������������

		// ����������� �������� ��������� ��� ����������� �����������
		mHero->setDirectionToMove(mHero->getPosition(), event->getLocationInView());
		// ������ ��������� �� "� ��������".
		mHero->setStateAndExec(&IState::gMoveState);
	}
}

void GameScene::goToMenuScene(Ref* pSender)
{
	Director::getInstance()->replaceScene(MenuScene::create());
}

void GameScene::initKeyboad()
{
	// ��������� ���������� ������� ������ �������
	auto keyboadListener = EventListenerKeyboard::create();
	keyboadListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboadListener, this);
}

void GameScene::initMouse()
{
	// ��������� ���������� ������� ������ ����
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(GameScene::onMouseDown, this);
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
}

void GameScene::initMenu()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// ������� ������� ����
	auto backToMenuItem = MenuItemImage::create("Buttons/MenuButton.png",
												"Buttons/MenuButton.png",
												CC_CALLBACK_1(GameScene::goToMenuScene, this));

	// ������������� ������� �������� ����
	backToMenuItem->setPosition(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.9F);

	// ������� ���� � ��������� ���� ��������� ����� ��������
	auto menu = Menu::create(backToMenuItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 100);
}

void GameScene::initHero()
{
	// ������� �����
	mHero = Hero::create();
	// ������������� ��� ������� �� ������
	mHero->setPosition({ _contentSize.width * 0.5f, _contentSize.height * 0.5f });
	// ������������� �������� ����������� ���������
	mHero->setSpeed(5.f);
	// ��������� ��� � objectPool
	addChild(mHero);
}
