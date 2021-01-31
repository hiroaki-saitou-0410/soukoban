#ifndef SCENE_BASE_H
#define SCENE_BASE_H

class SceneBase
{
public:
	SceneBase();
	virtual~SceneBase();

	//�������e�͔h���N���X���ɈႤ�̂ŏ������z�֐��Ƃ��Đ錾
	virtual void Exec() = 0;//����
	virtual void Draw() = 0;//�`��

	virtual bool IsEnd() const = 0;//�V�[�����I���������ǂ�����Ԃ�

protected:
	int m_Step;//�����g�p���Ǘ�����ϐ�
};

#endif // !SCENE_BASE_H

