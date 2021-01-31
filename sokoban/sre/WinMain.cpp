#include"DxLib.h"
#include"Manager/SceneManager.h"
#include"Manager/GameManager.h"
#include"Manager/InputManager.h"

const int WINDOW_W = 640;
const int WINDOW_H = 480;
const int COLOR_BIT = 32;

int WINAPI WinMain(_In_ HINSTANCE hIstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_W, WINDOW_H, COLOR_BIT);
	SetBackgroundColor(125, 125, 125);
	SetMainWindowText("�����炯�̑q�ɔ�");
	if (DxLib_Init() == -1){return - 1;}//�G���[���������I��

	//�`���𗠂̉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);
	
	//�Ǘ��N���X�̍쐬
	InputManager::CreateInstance();
	SceneManager::CreateInstance();
	GameManager::CreateInstance();

	//�����C���X�^���X�����Ȃ��悤�ɂ�����
	//Singleton singleton1;
	//Singleton singleton2;
	

	while (true)
	{
		if (ProcessMessage() != 0) { break; }//Windows�̃��b�Z�[�W�������A����ꂽ��

		//DxLib�̂��񑩁F��ʃN���A
		ClearDrawScreen();
		clsDx();

		//����
		InputManager::GetInstance()->Update();
		SceneManager::GetInstance()->Exec();
		//�`��
		SceneManager::GetInstance()->Draw();

		ScreenFlip();	//DxLib�̂��񑩁F��ʍX�V
	}

	
	//�Ǘ��N���X�̌�n��
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();

	DxLib_End();//DX���C�u�����g�p�̏I��

	return 0;
}