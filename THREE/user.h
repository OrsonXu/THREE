/*
------------------------------------------------------------
		�û�ģ��
		���û�����Ϣ�����û���Ϣ�Ĳ����Ͷ�Excel�е���Ϣ�Ĵ����װΪһ����
		ͷ�ļ�
------------------------------------------------------------
*/
#ifndef _USER_H_
#define _USER_H_
#include <string>
#include "libxl.h"

class user
{
private:
	std::wstring username;										//��¼��ǰ��ҵ�����
	std::wstring* oldusers;										//��¼��ͬ���û������������׵�ַ
	int* olduserNO;														//��Ӧ��ͬ���û���Ӧ��������׵�ַ
	int score;																	//��¼��ҵ÷�
public:
	//���зǾ�̬���ݳ�Ա
	bool vipflag;															//�ֶ�����ID�����ڼ�¼�Ƿ���vip�û��������ж�
	//���о�̬���ݳ�Ա
	static int usercount;												//��¼���в�ͬ�û�������Ŀ
	static int allusercount;										//��¼�������е�excel��������Ŀ������������ͬ��
	
	//���зǾ�̬������Ա
	user(std::wstring name=L"defaultuser");	//���캯����Ĭ���û�����ͬʱȷ�����ID��user����Ϊ��VIP�û�
	virtual ~user(void);												//�����������ͷŶ�̬�ڴ�
	virtual void initialization();								//��ʼ����Ϣ���ѱ���е���Ϣ����������Ŀ������
																						//��ͬ���û�����¼��*olduserΪ�׵�ַ�Ķ�̬�����У�
																						//ͬʱΪ����ţ���ż�¼�� *olduserNOΪ�׵�ַ�Ķ�̬�����С�
	virtual void olduser();											//��ӡ�����е������û����û������������û�����ѡ���û���
	virtual void newuser();										//���û��Լ���������
	virtual void setscore(const int score);			//��¼������ҵĵ÷�
	virtual void record();											//��������Ϸ�ĳɼ���¼��Excel��
	virtual void settle();												//�Գ����û���֮������ݽ�������
	//���о�̬������Ա
	static void ranking();											//��ӡ��Excel�е�ǰ�������а�������������ȫ��ӡ
};

class vipuser : public user{
	bool vipremovetime;											//���ڼ�¼VIP���������Ƿ�ʹ��
public:				
	vipuser(std::wstring name=L"defaultuser");//����д���캯����ͬʱ���ID��vipuser����ΪVIP�û�
	bool remove();														//����ֵ����¼VIP�����Ƿ�ʹ��
	void settle();															//����ԭ�е����ú��������������ڼ�¼VIP�����Ƿ�ʹ�õĲ���ֵ
};

#endif