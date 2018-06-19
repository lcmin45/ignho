#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
	// �Ҹ��� �׽�Ʈ
}

HRESULT playGround::init(void)	
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("���", "����.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
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
	
	//�����ȭ�� �� �� ��Ƶд�
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============== �� ���δ� �ǵ帮�� ���� ==============
	
	IMAGEMANAGER->render("���", getMemDC(), 0, 0);

	_currentScene->render();
	

	TIMEMANAGER->render(getMemDC());
	//================�� �����ε� �ǵ帮�� ���� =============
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

