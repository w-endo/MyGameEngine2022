#include "Quad.h"
#include <DirectXMath.h>

using namespace DirectX;

Quad::Quad()
{
}

Quad::~Quad()
{
}

void Quad::Initialize()
{
	// ���_���
	XMVECTOR vertices[] =
	{
		XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i����j
		XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E��j
		XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E���j
		XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�����j		
	};

	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(vertices);
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices;
	Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);

}

void Quad::Draw()
{
}

void Quad::Release()
{
}