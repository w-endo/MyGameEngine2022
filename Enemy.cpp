#include "Enemy.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy")
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");

    transform_.position_.z = 20.0f;


    SphereCollider* collision = new SphereCollider(1.0f);
    AddCollider(collision);
}

//�X�V
void Enemy::Update()
{

}

//�`��
void Enemy::Draw()
{
    pFbx->Draw(transform_);
}

//�J��
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
    KillMe();
    pTarget->KillMe();
}
