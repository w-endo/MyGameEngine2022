#pragma once
#include "Direct3D.h"
#include "Texture.h"


//コンスタントバッファー
struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
};

//頂点情報
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
};


class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ
	Texture*	pTexture_;

public:
	Quad();
	~Quad();
	HRESULT Initialize();
	void Draw(XMMATRIX& worldMatrix);
	void Release();
};