#include "MiniOden.h"

//�R���X�g���N�^
MiniOden::MiniOden(GameObject* parent)
    :GameObject(parent, "MiniOden")
{
}

//�f�X�g���N�^
MiniOden::~MiniOden()
{
}

//������
void MiniOden::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");

    transform_.position_.x = 2.0f;

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;
}

//�X�V
void MiniOden::Update()
{
  
}

//�`��
void MiniOden::Draw()
{
    pFbx->Draw(transform_);
}

//�J��
void MiniOden::Release()
{
}