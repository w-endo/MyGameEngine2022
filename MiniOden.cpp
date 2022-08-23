#include "MiniOden.h"

//コンストラクタ
MiniOden::MiniOden(GameObject* parent)
    :GameObject(parent, "MiniOden")
{
}

//デストラクタ
MiniOden::~MiniOden()
{
}

//初期化
void MiniOden::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");

    transform_.position_.x = 2.0f;

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;
}

//更新
void MiniOden::Update()
{
  
}

//描画
void MiniOden::Draw()
{
    pFbx->Draw(transform_);
}

//開放
void MiniOden::Release()
{
}