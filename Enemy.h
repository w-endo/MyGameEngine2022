#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"

//�v���C���[���Ǘ�����N���X
class Enemy : public GameObject
{
    Fbx* pFbx;
public:
    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;
};