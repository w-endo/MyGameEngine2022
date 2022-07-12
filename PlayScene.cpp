#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	
}

//�X�V
void PlayScene::Update()
{
	GameObject* test = FindObject("SceneManager");
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
