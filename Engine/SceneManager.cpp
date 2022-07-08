#include "SceneManager.h"
#include "Model.h"
#include "../PlayScene.h"
#include "../TestScene.h"

SceneManager::SceneManager(GameObject* parent)
	: GameObject(parent, "SceneManager")
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
    //�ŏ��̃V�[��������
    currentSceneID_ = SCENE_ID_PLAY;
    nextSceneID_ = currentSceneID_;
	Instantiate<PlayScene>(this);
}

void SceneManager::Update()
{
    //���̃V�[�������݂̃V�[���ƈႤ �� �V�[����؂�ւ��Ȃ���΂Ȃ�Ȃ�
    if (currentSceneID_ != nextSceneID_)
    {
        //���̃V�[���̃I�u�W�F�N�g��S�폜
        auto scene = childList_.begin();
        (*scene)->ReleaseSub();
        SAFE_DELETE(*scene);
        childList_.clear();

        //���[�h�����f�[�^��S�폜
        Model::Release();

        //���̃V�[�����쐬
        switch (nextSceneID_)
        {
        case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
        }

        currentSceneID_ = nextSceneID_;
    }
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}

void SceneManager::ChangeScene(SCENE_ID next)
{
    nextSceneID_ = next;
}
