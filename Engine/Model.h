#include <string>
#include "Transform.h"


namespace Model
{


	int Load(std::string fileName);
	void SetTransform(int hModel, Transform transform);
	void Draw(int hModel);
	void Release();
};