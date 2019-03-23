#ifndef  _Scene_
#define _Scene_

#include "d3d9.h"
#include "d3dx9.h"

class Scene
{
protected:
	D3DCOLOR _backColor;						// Màu nền
	Scene();									// Constructor khởi tạo cho abstract factory

public:
	virtual void LoadResources() {};			// Tải resources trước khi tạo Scene
	virtual void Update(int dt) {};			// Update các thông số sau khoảng delta-time
	virtual void Render() {};					// Render các UI Components lên Scene
	D3DCOLOR GetBackColor();					// Lấy màu nền
};

#endif // ! _Scene_