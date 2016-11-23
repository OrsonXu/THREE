/*
------------------------------------------------------------
		�������ģ��
		cppʵ���ļ�
------------------------------------------------------------
*/
#include "number.h"
#include "scene.h"
#include "user.h"
#include "libxl.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;
using namespace libxl;

void scene::printline(){
	//��ӡ��������Ϊ�����Ű��������
	for (int i=0;i<40;i++) cout<<"-";
	cout<<"\n";
}

void scene::printvoid(){
	//��ӡ���У������߽߱磬Ϊ�����Ű��������
	cout<<"|";
	for (int i=0;i<38;i++) cout<<" ";
	cout<<"|\n";
}

void scene::BeginInterface(){
	//��ӡ��ӭ����
	printline();
	printvoid();
	cout<<"|";
	for (int i=0;i<9;i++) cout<<" ";
	cout<<"��ӭ����DOS����С��Ϸ";
	for (int i=0;i<8;i++) cout<<" ";
	cout<<"|\n";
	cout<<"|";
	for (int i=0;i<18;i++) cout<<" ";
	cout<<"������";
	for (int i=0;i<14;i++) cout<<" ";
	cout<<"|\n";
	cout<<"|";
	for (int i=0;i<38;i++) cout<<" ";
	cout<<"|\n";
	cout<<"|";
	for (int i=0;i<38;i++) cout<<" ";
	cout<<"|\n";
	cout<<"|";
	for (int i=0;i<16;i++) cout<<" ";
	cout<<"Copyright by Orson Xu";
	for (int i=0;i<1;i++) cout<<" ";
	cout<<"|\n";
	printvoid();
	printline();
}

void scene::FirstInterface(){
	//��ӡ�ʼ��ѡ�����
	cout<<"\n\n";
	printline();
	printvoid();
	cout<<"|\t�� ����  ������  ���� ��       |\n";
	printvoid();
	cout<<"|\t      ������Ϸ��B��            |\n";
	cout<<"|\t      �鿴����R��            |\n";
	cout<<"|\t      �鿴������L��            |\n";
	cout<<"|\t      ������Ϣ��I��            |\n";
	cout<<"|\t      �˳���Ϸ��Q��            |\n";
	printvoid();
	printline();
}
void scene::RuleInterface(){
	//��ӡ��Ϸ�Ĺ���
	printline();
	printvoid();
	cout<<"|\t     ��Ϸ���򡪡���            |\n";
	printvoid();
	cout<<"|      ��������һ��¼�Լ��С��Ϸ��  |\n";
	printvoid();
	cout<<"|  ��������                          |\n";
	cout<<"|      ���ͨ��w��s��a��d�ֱ���Ϊ�ϡ�  |\n";
	cout<<"|  �¡����ҷ���� �����Ʒ����ƶ����� |\n";
	cout<<"|  ÿһ���ƶ�������ֻ�ƶ�һ��        |\n";
	cout<<"|      ���֡�1��ֻ�������֡�2�����Ϊ  |\n";
	cout<<"|  ��3��������3�������ϵ�������ֻ����  |\n";
	cout<<"|  ��ͬ��������ϳ�Ϊ���߼������֡�ÿ  |\n";
	cout<<"|  һ�γɹ����ƶ����µ����ֽ��������  |\n";
	cout<<"|  �����ƶ�������Ե����һ��/�С���   |\n";
	cout<<"|  �����������飬��û�����ֿ������ʱ  |\n";
	cout<<"|  ����Ϸ������                        |\n";
	printvoid();
	cout<<"|  �����Ȩ��                          |\n";
	cout<<"|      �����Ҫ������ȷ�Ĺ���������  |\n";
	cout<<"|  ����Ϊ����������ÿһ����Ϸ������  |\n";
	cout<<"|  һ�����⹦��ʹ��Ȩ������������ǰ��  |\n";
	cout<<"|  �������е����֡�1������2�� �롰3����|\n";
	cout<<"|  �����������ֲ��������ܷ֡�����Ȩֻ  |\n";
	cout<<"|  ������Ϸ��������ʱʹ�á�            |\n";
	printvoid();
	cout<<"|  �Ƿֹ���                          |\n";
	cout<<"|  ÿ����1������2��Ϊ10�֣���3��Ϊ20�� |\n";
	cout<<"|  ��6��Ϊ40�֣���12��Ϊ80�֣��Դ����� |\n";
	cout<<"|  ���յ÷�Ϊ���������е÷ֵ��ܺ͡�    |\n";
	printvoid();
	printline();
	cout<<"�밴���������...";
	char buffer;
	buffer=_getch();if((int)buffer==0||(int)buffer==-32) _getch();
}
void scene::Rankinginterface(){
	//��ӡexcel��������е����ǰ5����������5���ʹ�ӡ���У�
	printline();
	printvoid();
	cout<<"|              ʵ��Ӣ�۰�              |"<<endl;
	printvoid();
	user::ranking();		//����user���еľ�̬��Ա������չʾ����
	printvoid();
	printline();
	cout<<"�밴���������...";
	char buffer;
	buffer=_getch();if((int)buffer==0||(int)buffer==-32) _getch();
}
void scene::MoreInfointerface(){
	//��ӡ���ߵĸ�����Ϣ
	printline();
	printvoid();
	cout<<"|             ���߸�����Ϣ             |"<<endl;
	printvoid();
	cout<<"|         ������\t����         |"<<endl;
	cout<<"|         �༶��\t���Ķ�         |"<<endl;
	cout<<"|         ѧ�ţ�\t2014010902     |"<<endl;
	printvoid();
	cout<<"|         ����Ŀֻ����ѧϰ����         |"<<endl;
	cout<<"|           ��ֹ�κ���ҵ��;           |"<<endl;
	printvoid();
	printline();
	cout<<"�밴���������...";
	char buffer;
	buffer=_getch();if((int)buffer==0||(int)buffer==-32) _getch();
}

void scene::VIPInterface(){
	// ��VIP�û����д���
	//����VIP����û�����VIP���û��̳У�
	vipuser VIPPLAYER;
	PlayerInterface(& VIPPLAYER);
}

void scene::nVIPInterface(){
	//�Է�VIP�û����д���
	//������VIP����û�
	user nVIPPLAYER;
	PlayerInterface(& nVIPPLAYER);
}

void scene::PlayerInterface(user* PLAYER){
	//�����Ƿ���VIP�û���ͳһ����

	//��PLAYER�����е�һЩ�������г�ʼ��
	PLAYER->initialization();
	if (PLAYER->vipflag){
		printline();
		printvoid();
		cout<<"|�����𾴵�ϡ�ͣ������������֣�        |\n";
		printvoid();
		cout<<"|  ��ά��ά�Ʋ��ã�������������Ρ�1�� |\n";
		cout<<"|  ��һ������δ���й���¼        ��2�� |\n";
		printvoid();
		printline();
	}
	else {
		printline();
		printvoid();
		cout<<"|������λ���ˣ��������Ƿ������֣�      |\n";
		printvoid();
		cout<<"|  ���ֳƲ��ϣ����Ƕ���������Ρ�1��   |\n";
		cout<<"|  ��һ������δ���й���¼      ��2��   |\n";
		printvoid();
		printline();
	}
	for (;;){
		//��ѭ�������ظ�����
		bool JUDGE1=0;		//���ڲ���switch��break����������ѭ����������ֵ�������ʺ�ʱ������
		char oldjudge;
		cout<<"�����룺";
		//ʵ�ֲ���Ҫ�ûس����룬ֱ�����뼴����Ӧ
		oldjudge=_getch();if((int)oldjudge==0||(int)oldjudge==-32) _getch();cout<<oldjudge<<endl;
		switch(oldjudge){
			{
		case '1':
			JUDGE1=1;
			cout<<"\n�����õģ��뿴����Ļ����ᣬ��û�����Ĵ�����\n"<<endl;
			PLAYER->olduser();
			cout<<"����ɹ���\n���Եȣ���Ϸ������ʼ..."; 
			Sleep(1000);
			break;
			}
			{
		case '2':
			JUDGE1=1;
			cout<<"\n��������д�����Ĵ����ɣ����س�������Ŷ~����";
			PLAYER->newuser();
			cout<<"�������Ĵ����ѱ���¼~\n���Եȣ���Ϸ������ʼ...";
			Sleep(1000);
			break;
			}
		default:
			cout<<"�����������...����������Ŷ...\n";
			Sleep(500);
			break;
		}
		if (JUDGE1)
			break;
		else
			continue;
	}
	for (;;){
		//��ѭ��Ϊ��ʵ�ֿ����ظ�������Ϸ

		//������Ϸ���棬������Ϸ����Ϸ������ֱ�Ӽ�¼����
		PLAYER->setscore(GameInterface(PLAYER));
		//������д���ļ���
		PLAYER->record();
		bool JUDGE2=0;		//ͬ�����ڲ���switch��break����������ѭ����������ֵ�������ʺ�ʱ������
		printline();
		printvoid();
		cout<<"|��������øо���Σ�                  |\n";
		printvoid();
		cout<<"|  ��ˬ����û��񫣬����һ�֣���1��     |\n";
		cout<<"|  ��������һ������ս�ɣ�    ��2��     |\n";
		printvoid();
		printline();
		char continuejudge;
		continuejudge=_getch();if((int)continuejudge==0||(int)continuejudge==-32) _getch();cout<<continuejudge<<endl;
		switch(continuejudge){
		case '1':
			JUDGE2=1;
			//�Գ��û���֮��Ķ�����������
			PLAYER->settle();
			cout<<"�����Ե�Ŷ~��Ϸ����Ϊ������...\n";
			Sleep(500);
			break;
		case '2':
			cout<<"������߷~���۾ͻ�ȥ��~\n";
			Sleep(1000);
			break;
		default:
			cout<<"�����������...�Ǿ͵�����ʱ�����˰�.."<<endl;
			Sleep(1000);
			break;
		}
		if (JUDGE2)
			continue;
		else 
			break;
	}
}

int scene::GameInterface(user* PLAYER){
	//��Ϸ�������У�����ֵΪ���յ÷֣��˳�ǰ�����þ����е��������֣����������
	system("CLS");
	cout<<"******************* loading...***********************\n";
	Sleep(100);
	//ʵ����Ϸ��ʵ�����
	for(int i=0;i<4;i++){
		for (int j=0;j<13;j++)
			cout<<"*";
		Sleep(300);
	}
	cout<<"*\n";
	Sleep(300);
	cout<<"����ɹ���\n";
	int length,bufferscore=0;
	char clength;
	cout<<"������λ�͹٣����Զ�����Ϸ����߳���";
	//ȷ����Ϸ����Ĵ�С
	clength=_getch();
	//���ַ���ת��Ϊ����
	length=clength-48;
	if(length==-80||length==-48) _getch();
	cout<<length<<endl;
	while(length<=2){
		if (length<=0)
			cout<<"�߳���ô���Բ��������أ���������ѧ��������ʦ�̵�ѽ~\n��������Ŷ~��";
		else if(length>0&&length<=2)
			cout<<"�������Ҳ̫û���Ѷ��˰ɣ�~�����һ�����~\n��������Ŷ~��";
		clength=_getch();
		length=clength-48;
		if(length==-80||length==-48) _getch();
		cout<<length<<endl;
	}
	cout<<"��Ϸ����Ϊ����ʼ��...\n";
	Sleep(1000);
	//������Ϸģ����
	number THREE(length);
	system("CLS");
	//��ʼ��THREE�����е�һЩ����
	THREE.initialization();
	//��ӡ��Ϸ����
	THREE.printinterface();
	for(;;){
		//��ʽ��ʼ��Ϸ����ѭ��Ϊ��ÿ��ʵ�����붯�����˳�
		char movement;
		cout<<"���������Ķ�����";
		movement=_getch();if((int)movement==0||(int)movement==-32) _getch();cout<<movement<<endl;
		Sleep(100);
		THREE.move(movement);
		if(THREE.endflag){
			//�ж���Ϸ�����������vip���л��������Ϸ
			if (PLAYER->vipflag){ 
				//�ж��Ƿ���vip���
				//����ǣ�����ʱǿ��ת��Ϊָ��vipuser��ָ��
				vipuser* vipPLAYER; 
				vipPLAYER=dynamic_cast <vipuser*>(PLAYER);
				if (vipPLAYER->remove()){
					//����л��������Ϸ����ô�����û���Ը���Ƿ���Ҫʹ��VIP����
					cout<<"�������Ƿ�Ҫʹ��vip���ܣ�(��ע�ⱻ���������ֽ����ٱ�����÷�)(Y/N)��";
					char vipmethodjudge;
					cin>>vipmethodjudge;
					switch(vipmethodjudge){
					case 'y':
					case 'Y':
						THREE.vipsettle();				//��ȥ���е�1��2��3��Щ����
						system("CLS");
						THREE.printinterface();
						break;
					case 'n':
					case 'N':
						break;
					default:
						cout<<"�ܱ�Ǹ������������Ĭ��Ϊ��ʹ���������ܡ�"<<endl;
						break;
					}
				}
			}
			if (THREE.endflag){
				//����������Ĳ���֮��endflagû�б仯��˵������VIP��ң�������VIP���û��ʹ���������ߣ���Ϸ����������÷�
				cout<<"���ڼ������ĵ÷�...\n";
				bufferscore=THREE.scorecal();
				Sleep(500);
				cout<<"���ĵ÷�Ϊ��"<<bufferscore<<endl;
				break;
			}
		}
		else {
			//����ˢ�½��棬������Ϸ
			system("CLS");
			THREE.printinterface();
		}
	}
	return bufferscore;
}

void scene::whole(){
	//�����еĺ������е���
	BeginInterface();
	FirstInterface();
	for (;;){
		char choice;
		cout<<"��ѡ��";
		choice=_getch();if((int)choice==0||(int)choice==-32) _getch();cout<<choice<<endl;
		switch(choice){
		case 'q':
		case 'Q':
			cout<<"�˳���Ϸ...��ӭ�´�����~\n";
			exit(0);
			break;
		case 'r':
		case 'R':
			system("CLS");
			RuleInterface();
			break;
		case 'l':
		case 'L':
			system("CLS");
			Rankinginterface();
			break;
		case 'i':
		case 'I':
			system("CLS");
			MoreInfointerface();
			break;
		case'b':
		case 'B':
			system("CLS");
			printline();
			printvoid();
			cout<<"|������λ�ֵܣ���Щ���죬�ǹ�ͣ�      |\n";
			printvoid();
			cout<<"|  �뿴�����ǹ����������ϡ��Ҳ��1��   |\n";
			cout<<"|  ��Ҳ��Ҳ��·�����ѣ����Ͱ��ˡ�2��   |\n";
			printvoid();
			printline();
			cout<<"�����룺";		
			char userjudge;
			userjudge=_getch();if((int)userjudge==0||(int)userjudge==-32) _getch();cout<<userjudge<<endl;
			switch(userjudge){
				{
			case '1':
				string password;
				for (;;){
					//��ѭ��Ϊ�˱�֤���Զ�γ�������������
					cout<<"\n��������������VIP���루�Իس���������";
					cin>>password;
					if(password=="three"||password=="THREE"){
						cout<<"������ϲ��������ȷ��\n"<<endl;
						VIPInterface();
						break;
					}
					else{
						char continuejudge;
						printline();
						printvoid();
						cout<<"|������Ǹ���������������            |\n";
						printvoid();
						cout<<"|  һʱ�ֶ������ñ�������һ�ΰ�  ��1�� |\n";
						cout<<"|  �Ϸ�������ξͲ������ϯ�˰ɡ�2�� |\n";
						printvoid();
						printline();
						cout<<"�����룺";
						continuejudge=_getch();if((int)continuejudge==0||(int)continuejudge==-32) _getch();cout<<continuejudge<<endl;
						if (continuejudge=='1')
							//����if��������switch������������ѭ��
							continue;
						else if (continuejudge=='2'){
							nVIPInterface();
							break;
						}
						else{
							cout<<"\n�������ƺ�û��������˵�Ļ����Ǿ͵������������ϯ�˰ɡ�"<<endl;
							Sleep(500);
							nVIPInterface();
							break;
						}
					}
				}
				break;
				}
			case '2':
				nVIPInterface();
				break;
			default:
				cout<<"\n������զû�������Ǿ͵����ǳ��Ͱ�~\n";
				Sleep(500);
				nVIPInterface();
				break;
			}
			break;
		default:
			cout<<"��Ǹ���������������������롣"<<endl;
			Sleep(500);
			break;
		}
		system("CLS");
		BeginInterface();
		FirstInterface();
	}
}
