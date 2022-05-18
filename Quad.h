#pragma once
#include "Direct3D.h"

#include <DirectXMath.h>

using namespace DirectX;

//コンスタントバッファー
struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
};


class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ

public:
	Quad();
	~Quad();
	HRESULT Initialize();
	void Draw();
	void Release();
};