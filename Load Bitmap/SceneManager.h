
#include "Scene.h"
#include "PlayScene.h"
#include <vector>

class SceneManager
{
private:
	PlayScene* _curScene;							// Scene hiện tại mà Manager đang giữ
	static SceneManager* _instance;				// Instance (Singleton Pattern)

public:
	SceneManager();
	void ReplaceScene(PlayScene* scene);			// Thay thế Scene hiện có bằng Scene khác (dùng cho chuyển cảnh)
	PlayScene* GetCurScene();						// Get Scene hiện tại
	static SceneManager* GetInstance();			// Get Instance (Singleton Pattern)
};