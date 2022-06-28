#include "RootJob.h"
#include "../PlayScene.h"

RootJob::RootJob()
{
}

RootJob::~RootJob()
{
}

void RootJob::Initialize()
{
	PlayScene* pPlayScene;
	pPlayScene = new PlayScene(this);

	pPlayScene->Initialize();
	childList_.push_back(pPlayScene);
}

void RootJob::Update()
{
}

void RootJob::Draw()
{
}

void RootJob::Release()
{
}
