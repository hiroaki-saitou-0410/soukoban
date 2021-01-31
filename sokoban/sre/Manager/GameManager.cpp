#include"GameManager.h"

GameManager* GameManager::gameManager = nullptr;

GameManager::GameManager()
{
}

void GameManager::CreateInstance()
{
	if (gameManager == nullptr)
	{
		gameManager = new GameManager();
	}
}

void GameManager::DestroyInstance()
{
	delete gameManager;
	gameManager = nullptr;
}

GameManager* GameManager::GetInstance()
{
	return gameManager;
}

