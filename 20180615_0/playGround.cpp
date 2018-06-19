#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
	// 소멸자 테스트
}

HRESULT playGround::init(void)	
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("배경", "우주.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("battle", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));

	_star = new starScene;
	_star->init();

	_select = new selectScene;
	_select->init();

	_currentScene = _select;

	return S_OK;
}

void playGround::release(void)	
{
	gameNode::release();

	
}

void playGround::update(void)	
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_currentScene = _star;
		_currentScene->init();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_currentScene = _select;
		_currentScene->init();
	}
	
	_currentScene->update();

}

void playGround::render(void)
{
	
	//흰색도화지 한 장 깔아둔다
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============== 이 위로는 건드리지 말자 ==============
	
	IMAGEMANAGER->render("배경", getMemDC(), 0, 0);

	_currentScene->render();
	

	TIMEMANAGER->render(getMemDC());
	//================이 밑으로도 건드리지 말자 =============
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

