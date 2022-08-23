#include "Transform.h"

Transform::Transform():
    matTranslate_(XMMatrixIdentity()),
    matRotate_(XMMatrixIdentity()),
    matScale_(XMMatrixIdentity()),        
    position_(XMFLOAT3(0, 0, 0)),
    rotate_(XMFLOAT3(0, 0, 0)),
    scale_(XMFLOAT3(1, 1, 1))
{
}

Transform::~Transform()
{
}

void Transform::Calclation()
{
    //�ړ��s��쐬
    matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);

    //��]�s��쐬
    XMMATRIX rotateX, rotateY, rotateZ;
    rotateX = XMMatrixRotationX(XMConvertToRadians(rotate_.x));
    rotateY = XMMatrixRotationY(XMConvertToRadians(rotate_.y));
    rotateZ = XMMatrixRotationZ(XMConvertToRadians(rotate_.z));
    matRotate_ = rotateZ * rotateX * rotateY;
                    
    //�g��s��쐬
    matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
    //�e������ꍇ�͐e�̉e�����󂯂�
    if (pParent_)
    {
        return  matScale_ * matRotate_ * matTranslate_ * pParent_->GetWorldMatrix();
    }

    //�e�����Ȃ��ꍇ
    return  matScale_ * matRotate_ * matTranslate_;
}

XMMATRIX Transform::GetNormalMatrix()
{
    return matRotate_ * XMMatrixInverse(nullptr, matScale_);
}
