#pragma once
#include "Direct3D.h"

class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
public:
	Quad();
	~Quad();
	void Initialize();
	void Draw();
	void Release();
};