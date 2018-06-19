#include "stdafx.h"
#include "selectScene.h"


selectScene::selectScene()
{
}


selectScene::~selectScene()
{
}

HRESULT selectScene::init()
{
	return S_OK;
}

void selectScene::release()
{
}

void selectScene::update()
{
}

void selectScene::render()
{
	char str[128];
	sprintf_s(str, "ºø∑∫∆Æ ææ¿Ã¿Ã¿Ã¿Ã¿Œ");
	TextOut(getMemDC(), WINSIZEX / 2 + 150, WINSIZEY / 2 - 200, str, strlen(str));

}
