#include "Player.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");
}

//�X�V
void Player::Update()
{
    transform_.rotate_.y++;
}

//�`��
void Player::Draw()
{
    pFbx->Draw(transform_);
}

//�J��
void Player::Release()
{
}