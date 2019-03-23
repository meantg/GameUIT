#include "PlayScene.h"
#include "GameGlobal.h"
Player *player;

PlayScene::PlayScene()
{
	_backColor = D3DCOLOR_XRGB(0, 255, 255);
	_timeCounter = 0;
	LoadResources();
}

PlayScene::~PlayScene()
{
	delete animations;
}

// Load các thông số các đối tượng trong Scene
void PlayScene::LoadResources()
{
	CTexture * textures = CTexture::GetInstance();

	textures->Add(1, "Ninja.png", D3DCOLOR_XRGB(255, 163, 177));

	CSpritesManager * sprites = CSpritesManager::GetInstance();
	animations = Animations::GetInstance();
	LPDIRECT3DTEXTURE9 texPeople = textures->GetTexture(1);
		
	//Idle
	sprites->Add(00000, 2, 4, 21, 37, texPeople);
	//Attack-Standing
	sprites->Add(00001, 41, 4, 60, 37, texPeople);
	sprites->Add(00002, 66, 4, 101, 37, texPeople);
	sprites->Add(00003, 111, 4, 141, 37, texPeople);

	//Throwing
	sprites->Add(10001, 164, 4, 182, 37, texPeople);
	sprites->Add(10002, 189, 4, 215, 37, texPeople);
	sprites->Add(10003, 227, 4, 253, 37, texPeople);
	
	//Climbing
	sprites->Add(20001, 266, 4, 284, 37, texPeople);
	sprites->Add(20002, 288, 4, 306, 37, texPeople);

	//Run
	sprites->Add(30001, 339, 4, 361, 37, texPeople);
	sprites->Add(30002, 368, 4, 390, 37, texPeople);
	sprites->Add(30003, 400, 4, 421, 37, texPeople);

	//Sitting
	sprites->Add(40000, 3, 45, 21, 77, texPeople);
	
	//Attack-Sitting
	sprites->Add(40001, 35, 45, 53, 77, texPeople);
	sprites->Add(40002, 58, 45, 99, 77, texPeople);
	sprites->Add(40003, 99, 45, 130, 77, texPeople);

	//Jump
	sprites->Add(50001, 142, 45, 158, 77, texPeople);
	sprites->Add(50002, 166, 45, 189, 77, texPeople);
	sprites->Add(50003, 193, 45, 210, 77, texPeople);
	sprites->Add(50004, 216, 45, 240, 77, texPeople);

	//Jump-Attack
	sprites->Add(60001, 262, 45, 288, 77, texPeople);
	sprites->Add(60002, 293, 45, 321, 77, texPeople);
	sprites->Add(60003, 325, 45, 353, 77, texPeople);
	sprites->Add(60004, 357, 45, 385, 77, texPeople);


	LPANIMATION ani;
	// Anim-Idle [0]
	ani = new Animation(100);
	ani->Add(00000);
	animations->Add(101, ani);

	// Anim-Attack-Standing [1]
	ani = new Animation(100);
	ani->Add(00001);
	ani->Add(00002);
	ani->Add(00003);
	animations->Add(102, ani);

	// Anim-Throwing [2]
	ani = new Animation(100);
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	animations->Add(103, ani);

	//Anim-Climbing [3]
	ani = new Animation(100);
	ani->Add(20001);
	ani->Add(20002);
	animations->Add(104, ani);

	//Anim-Running [4]
	ani = new Animation(100);
	ani->Add(30001);
	ani->Add(30002);
	ani->Add(30003);
	animations->Add(105, ani);

	//Anim-Sit [5]
	ani = new Animation(100);
	ani->Add(40000);
	animations->Add(106, ani);

	//Anim-Attack-Sitting [6]
	ani = new Animation(100);
	ani->Add(40001);
	ani->Add(40002);
	ani->Add(40003);
	animations->Add(107, ani);

	//Anim-Jumping [7]
	ani = new Animation(100);
	ani->Add(50001);
	ani->Add(50002);
	ani->Add(50003);
	ani->Add(50004);
	animations->Add(108, ani);

	//Anim-Jumping-Attack [8]
	ani = new Animation(100);
	ani->Add(60001);
	ani->Add(60002);
	ani->Add(60003);
	ani->Add(60004);
	animations->Add(109, ani);
	
	player = new Player();
	player->AddAnimation(101);
	player->AddAnimation(102);
	player->AddAnimation(103);
	player->AddAnimation(104);
	player->AddAnimation(105);
	player->AddAnimation(106);
	player->AddAnimation(107);
	player->AddAnimation(108);
	player->AddAnimation(109);


	player ->SetPosition(10.0f, 100.0f);
}

// Update các thông số các đối tượng trong Scene
void PlayScene::Update(float dt)
{
	player->Update(dt);
}

// Tải Scene lên màn hình bằng cách vẽ các Sprite trong Scene
void PlayScene::Render()
{
	player->Render();
}
void SampleKeyHander::OnKeyDown(int KeyCode)
{

}

void SampleKeyHander::OnKeyUp(int KeyCode)
{
	//player->SetState(NINJA_IDLE);
}

void SampleKeyHander::KeyState(BYTE *states)
{
	/*if (Game::GetInstance()->IsKeyDown(DIK_RIGHT))
		player->SetState(NINJA_RUN_RIGHT);
	else if (Game::GetInstance()->IsKeyDown(DIK_LEFT))
		player->SetState(NINJA_RUN_LEFT);
	else if (Game::GetInstance()->IsKeyDown(DIK_DOWN))
		player->SetState(NINJA_SITTING);
	else if (Game::GetInstance()->IsKeyDown(DIK_SPACE))
		player->SetState(NINJA_JUMP);
	else if (Game::GetInstance()->IsKeyDown(DIK_A))
		player->SetState(NINJA_ATK_STANDING);
	else 
		player->SetState(NINJA_IDLE);*/
}