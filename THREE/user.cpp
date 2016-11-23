/*
------------------------------------------------------------
		�û���
		cppʵ���ļ�
------------------------------------------------------------
*/
#include "user.h"
#include "libxl.h"
#include <iostream>
#include <ctime>
#include <locale>
#include <iomanip>
#include <windows.h>

using namespace std;
using namespace libxl;

//����ȫ�ֵ�ʱ�������Ϊ�˷���֮���ڼ�¼�м�¼��Ϸ���ڡ�
time_t tt = time(NULL);
tm* t= localtime(&tt);

//��̬���ݳ�ʼ����һ��ʼ����������Ϊ��
int user::usercount=0;
int user::allusercount=0;

user::user(std::wstring name/*=L"defaultuser"*/){
	//���캯����Ĭ���û�����ͬʱȷ�����ID��user����Ϊ��VIP�û�
	this->username=name;
	vipflag=0;
}

user::~user(void){
	//�����������ͷŶ�̬�ڴ�
	delete [] oldusers;
	delete [] olduserNO;
}

void user::initialization(){
	//��ʼ����Ϣ���ѱ���е���Ϣ����������Ŀ��������ͬ���û�����¼�����У�ͬʱΪ�����
	Book* book=xlCreateXMLBook();
	if (book){
		if (book->load(L"user.xlsx")){
			Sheet* sheet=book->getSheet(0);
			if(sheet){
				allusercount=sheet->lastRow()-1;							//���ڵ�һ�в����û�����Ҫ��1
				oldusers=new wstring[allusercount];					//��̬���������ܵĲ�ͬ�û�����
				olduserNO=new int[allusercount];							//��̬�����Ӧ�ı������
				for (int i=1;i<=allusercount;i++){
					wstring buffername = sheet->readStr(i, 0);
					if (i==1){
						//��һ���˻�����ֱ�Ӽ�¼
						oldusers[0]=buffername;
						olduserNO[0]=1;
						usercount=1;
					}
					else{
						//��ͬ�����ֲ��ܹ�������ͬ����ң��������е��û����֣���flag���
						//�����µ����֣��������µ��û�������������
						int flag=0;																
						for (int j=0;j<i-1;j++){
							if (buffername==oldusers[j])
								flag++;
						}
						if(flag==0){
							usercount++;
							oldusers[usercount-1]=buffername;
							olduserNO[usercount-1]=usercount;
						}
					}
				}
			}
			else 
				cout<<"Cannot find the sheet!"<<endl;
		}
		else 
			cout<<"Cannot find the excel!"<<endl;
		book->release();
	}
	else 
		cout<<"Cannot creat a book!"<<endl;
}

void user::olduser(){
	//��ӡ�����е������û����û������������û�����ѡ���û���
	Book* book=xlCreateXMLBook();
	if (book){
		if (book->load(L"user.xlsx")){
			Sheet* sheet=book->getSheet(0);
			if(sheet){
				//���ڼ�¼Ŀǰ�����������ֶ�Ӧ�ĵı��
				int nownumber;																	
				for (int i=0;i<40;i++) cout<<"-";
				cout<<"\n";
				cout<<"|\t�û���\t\t���           |"<<endl;
				cout<<"|";
				for (int i=0;i<38;i++) cout<<" ";
				cout<<"|\n";
				for(int k=0;k<usercount;k++)
					//������в�ͬ����Һͱ��
					wcout<<"|\t"<<oldusers[k]<<"\t\t"<<setw(3)<<olduserNO[k]<<"            |"<<endl;
				cout<<"|";
				for (int i=0;i<38;i++) cout<<" ";
				cout<<"|\n";
				for (int i=0;i<40;i++) cout<<"-";
				cout<<"\n";
				for (;;){
					//��ѭ��Ϊ��ֹ�������
					cout<<"����Ӧ�ı���ǣ������س�������Ŷ~����";
					cin>>nownumber;
					if (nownumber>usercount||nownumber<1){
						cout<<"��Ǹ������������������";
						Sleep(500);
						cout<<"\r";
						continue;
					}
					else{
						username=oldusers[nownumber-1];
						break;
					}
				}
			}
			else 
				cout<<"Cannot find the sheet!"<<endl;
		}
		else 
			cout<<"Cannot find the excel!"<<endl;
		book->release();
	}
	else 
		cout<<"Cannot creat a book!"<<endl;
}

void user::newuser(){
	//���û��Լ���������
	wcin>>username;
}

void user::ranking(){
	//��̬��������ӡ��Excel�е�ǰ�������а�������������ȫ��ӡ������ֱ��ͨ����������
	//Ϊʵ��һ������Ϸ�Ϳ��Բ鿴���а񣬲���Ҫ��ʼ��
	//Ҳ������ˣ����������Щ�����ڱ�ĺ���֮�⣬�û����������Լ��������õġ�
	Book* book=xlCreateXMLBook();
	if (book){
		if (book->load(L"user.xlsx")){
			Sheet* sheet=book->getSheet(0);
			if(sheet){
				int allusercount=sheet->lastRow()-1;			//�����Ǿ�̬���������¿�һ��������������ֵ
				int* scorelist=new int [allusercount];			//��¼���е����еĵ÷�
				int* scoreNO=new int [allusercount];			//��¼��÷����ڵ�������Ϊ�˷���֮��ͨ�������ҵ��û���
				for (int j=1;j<=allusercount;j++)
					scorelist[j-1]=static_cast<int>(sheet->readNum(j,1));
				for (int k=0;k<allusercount;k++)
					scoreNO[k]=k+1;
				int temp1,temp2;
				//���ò������򷨣�ͬʱ�����������������
				for(int i=1;i<allusercount;i++){
					temp1=*(scorelist+i);
					temp2=*(scoreNO+i);
					int j=i;
					for(;j>0&&*(scorelist+j-1)>temp1;j--){
						*(scorelist+j)=*(scorelist+j-1);
						*(scoreNO+j)=*(scoreNO+j-1);
					}
					*(scorelist+j)=temp1;
					*(scoreNO+j)=temp2;
				}
				//�Է�excel��û���κμ�¼
				if(allusercount==0){
					cout<<"��ǸExcel��û�м�¼��"<<endl;
				}
				else {
					cout<<"|  "<<"����\t�û���\t�÷�\t����"<<setw(12)<<"|"<<endl;
					//�Է�excel������������
					int bufferint;
					if(allusercount>5)
						bufferint=5;
					else 
						bufferint=allusercount;
					for(int k=0;k<bufferint;k++){
						int bufyear,bufmonth,bufday;
						book->dateUnpack(sheet->readNum(scoreNO[allusercount-1-k], 2), &bufyear, &bufmonth, &bufday);
						wcout<<"|   "<<k+1<<"\t"<<sheet->readStr(scoreNO[allusercount-1-k],0)<<"\t"<<scorelist[allusercount-1-k]<<"\t"<<setw(4)<<bufyear<<"-"<<setw(2)<<bufmonth<<"-"<<setw(2)<<bufday<<"     |"<<endl;
					}
					delete[] scorelist;
					delete[] scoreNO;
				}
			}
			else 
				cout<<"Cannot find the sheet!"<<endl;
		}
		else 
			cout<<"Cannot find the excel!"<<endl;
		book->release();
	}
	else 
		cout<<"Cannot creat a book!"<<endl;
}

void user::setscore(const int score){
	//��¼������ҵĵ÷� 
	this->score=score;
}

void user::record(){
	//��������Ϸ�ĳɼ���¼��Excel��
	Book* book=xlCreateXMLBook();
	if (book){
		if (book->load(L"user.xlsx")){
			Sheet* sheet=book->getSheet(0);
			if(sheet){
				sheet->writeStr(allusercount+1,0,username.c_str());
				sheet->writeNum(allusercount+1,1,score);
				sheet->writeNum(allusercount+1, 2, book->datePack(t->tm_year+1900, t->tm_mon+1, t->tm_mday));
				allusercount++;
				//�ж��Ƿ��б�Ҫ�����û���������1��ԭ��֮ͬǰ������flag���
				int flag=0;	
				for (int i=0;i<usercount;i++)
					if (username==oldusers[i])
						flag++;
				if (flag==0)
					usercount++;
			}
			else 
				cout<<"Cannot find the sheet!"<<endl;
		}
		else 
			cout<<"Cannot find the excel!"<<endl;
		//�����ݴ���excel�����
		if(book->save(L"user.xlsx"));
		else 
			cout<<"Save error!"<<endl;
		book->release();
	}
	else 
		cout<<"Cannot creat a book!"<<endl;
}

void user::settle(){
	//�Գ����û���֮������ݽ�������
	//����������������´�Excel����ж�ȡ����
	setscore(0);
	initialization();
}


vipuser::vipuser(std::wstring name/*=L"defaultuser"*/):user(name){
	//����д���캯����ͬʱ���ID��vipuser����ΪVIP�û�
	vipremovetime=0;
	vipflag=1;
}

bool vipuser::remove(){
	//����ֵ����¼VIP�����Ƿ�ʹ��
	if (vipremovetime!=0)
		return 0;
	else{
		vipremovetime=1;
		return 1;
	}
}

void vipuser::settle(){
	//����ԭ�е����ú���
	//����������������´�Excel����ж�ȡ���ݣ��������ò���ֵ
	setscore(0);
	vipremovetime=0;
	vipflag=1;
}