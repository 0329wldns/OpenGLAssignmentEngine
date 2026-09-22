#include "pch.h"
#include "Scene_Assignment3.h"
#include "KeyManager.h"
#include "EventFunc.h"
#include "Rect.h"

random_device rd{};
mt19937 gen(rd());
uniform_int_distribution<int> intDist(1, 10000);
uniform_real_distribution<float> realDist(0.0f, 1.0f);

static const int g_sizeLimit{ 100 };
static int g_rectCnt{};

void Scene_Assignment3::update()
{
	if (KeyManager::getInstance().getKeyState(KEY::ESC) == KEY_STATE::TAP)
		changeScene(SCENE_TYPE::START);
	if (KeyManager::getInstance().getKeyState(KEY::A) == KEY_STATE::TAP)
	{
		system("cls");
		if (g_rectCnt < 10)
		{
			Vector2 pos{ intDist(gen) % SCREEN_WIDTH, intDist(gen) % SCREEN_HEIGHT };
			Vector2 scale{ 10 + intDist(gen) % g_sizeLimit, 10 + intDist(gen) % g_sizeLimit };
			Color col{ realDist(gen), realDist(gen), realDist(gen) };

			Rect* rect = new Rect();
			rect->setPos(pos);
			rect->setScale(scale);
			rect->setColor(col);

			createObject(rect, OBJECT_GROUP::RECT);
			++g_rectCnt;
		}
		else cout << "사각형이 너무 많음!" << endl;
		cout << "사각형 개수: " << g_rectCnt << endl;
	}
	if (KeyManager::getInstance().getKeyState(KEY::R) == KEY_STATE::TAP) reset();

	Scene::update();
}

void Scene_Assignment3::enter()
{
	cout << "과제3" << endl;
}

void Scene_Assignment3::exit()
{
	reset();
}
