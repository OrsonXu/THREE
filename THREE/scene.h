/*
------------------------------------------------------------
		�������ģ��
		����������д�ӡ������װΪһ����
		ͷ�ļ�
------------------------------------------------------------
*/
#ifndef _SCENE_H_
#define _SCENE_H_
#include "user.h"
class scene
{
public:
	scene(){};
	~scene(){};
	void printline();													//��ӡ��������Ϊ�����Ű��������
	void printvoid();												//��ӡ���У������߽߱磬Ϊ�����Ű��������
	void BeginInterface();										//��ӡ��ӭ����
	void FirstInterface();										//��ӡ�ʼ��ѡ�����
	void RuleInterface();										//��ӡ��Ϸ����
	void Rankinginterface();								//��ӡexcel��������е����ǰ5����������5���ʹ�ӡ���У�
	void MoreInfointerface();								//��ӡ���ߵĸ�����Ϣ
	void VIPInterface();											//��VIP�û�������vipuser��
	void nVIPInterface();										//�Է�VIP�û�������user��
	void PlayerInterface(user* PLAYER);			//�����Ƿ���VIP�û���ͳһ����ʵ�ֶ�̬
	int GameInterface(user* PLAYER);				//��Ϸ���У�����ֵΪ���յ÷֣��˳�ǰ�����������֣����������
	void whole();														//�����еĺ������е���
};

#endif