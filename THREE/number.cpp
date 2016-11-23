/*
------------------------------------------------------------
		��Ϸ����ģ��
		cppʵ���ļ�
------------------------------------------------------------
*/
#include "number.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

number::number(int length){
	this->length=length;
	if (this->length<=0)
		cout<<"Parameter errors!";
	else {
		num=new int* [length];
		for (int i=0;i<length;i++)
			num[i]=new int[length]();
		buffernum=new int* [length];
		for (int i=0;i<length;i++)
			buffernum[i]=new int[length]();
	}
	endflag=0;
}

number::~number(void){
	for(int i=0;i<length;i++)
		delete[] num[i];
	delete[] num;
	for(int i=0;i<length;i++)
		delete[] buffernum[i];
	delete[] buffernum;
}

void number::printnumber(int a, int b){
	//��ӡ�����֣�����ʵ�ֲ�ͬ���ֲ�ͬ��ɫ
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (num[a][b]==1){
		SetConsoleTextAttribute(hOut,
			FOREGROUND_RED | 
			FOREGROUND_GREEN);
		cout<<setw(5)<<num[a][b];
	}
	else if (num[a][b]==2){
		SetConsoleTextAttribute(hOut,
			FOREGROUND_GREEN | 
			FOREGROUND_BLUE);
		cout<<setw(5)<<num[a][b];
	}
	else if (num[a][b]==96){
		SetConsoleTextAttribute(hOut,
			FOREGROUND_INTENSITY |
			FOREGROUND_RED | 
			FOREGROUND_BLUE);
		cout<<setw(5)<<num[a][b];
	}
	else if (num[a][b]==192){
		SetConsoleTextAttribute(hOut,
			FOREGROUND_INTENSITY |
			FOREGROUND_GREEN);
		cout<<setw(5)<<num[a][b];
	}
	else if (num[a][b]==384){
		SetConsoleTextAttribute(hOut,
			FOREGROUND_INTENSITY |
			FOREGROUND_BLUE);
		cout<<setw(5)<<num[a][b];
	}
	else if (num[a][b]==768){
		SetConsoleTextAttribute(hOut,
			FOREGROUND_INTENSITY |
			FOREGROUND_RED);
		cout<<setw(5)<<num[a][b];
	}
	else if((num[a][b]>=3&&num[a][b]<=48)||num[a][b]>=1536){
		SetConsoleTextAttribute(hOut,
			FOREGROUND_RED | 
			FOREGROUND_GREEN | 
			FOREGROUND_BLUE);
		cout<<setw(5)<<num[a][b];
	}
	else{
		cout<<setw(5)<<" ";
	}
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED | 
		FOREGROUND_GREEN | 
		FOREGROUND_BLUE);
}

int number::randomnum(){
	//����һ�����������������
	//�ڱ������У�1,2���ֵĸ��ʸ�ռ25%��3���ֵĸ���ռ29%��
	//6���ֵĸ���ռ12%��12���ֵĸ���ռ6%  24���ֵĸ���ռ3%
	int ran=rand()%100+1;
	if (ran>=1&&ran<=25)
		return 1;
	else if (ran>=26&&ran<=50)
		return 2;
	else if (ran>=51&&ran<=79)
		return 3;
	else if (ran>=80&&ran<=91)
		return 6;
	else if (ran>=92&&ran<=97)
		return 12;
	else if (ran>=98&&ran<=100)
		return 24;
}


void number::printinterface(){
	//��ӡ������Ϸ����
	for (int i=0;i<10*length+1;i++) 
		cout<<"-";
	cout<<"\n";
	for(int k=0;k<length;k++){
		//��������
		cout<<"|";						
		for (int i=0;i<length;i++){
			for (int j=0;j<9;j++)
				cout<<" ";
			cout<<"|";
		}							
		cout<<"\n";					
		//��������
		cout<<"|";
		for (int i=0;i<length;i++){
			printnumber(k,i);
			for (int j=0;j<4;j++)
				cout<<" ";
			cout<<"|";
		}
		cout<<"\n";
		//��������	
		cout<<"|";						
		for (int i=0;i<length;i++){
			for (int j=0;j<9;j++)
				cout<<" ";
			cout<<"|";
		}
		cout<<"\n";
		//����	
		for (int i=0;i<10*length+1;i++) 
			cout<<"-";
		cout<<"\n";
	}
}


void number::initialization(){
	//��ʼ����Ϸ�����������λ�õ����ֽ��������ʼ��
	int flag=0;
	for (;flag<=2*length-3;){
		int i=rand()%length;
		int j=rand()%length;
		if (num[i][j]==0){
			num[i][j]=randomnum();
			flag++;
		}
	}
}

void number::upmove(int **num){
	int buffer[20];
	for (int i=0;i<20;i++)
		buffer[i]=0;
		int bigflag=0;																		//��¼�����е��У��ж����п��Ա��ƶ�����û�У���˵��������Ч��
		int linenum=-1;																	//��¼�������е�����-1   ����1Ϊ��ӭ���������������Ҳ��˷ѿռ䣩
		for(int line=0;line<length;line++){							
			//��ѭ��Ϊ��Ѱ�����е��ܹ������ֱ仯���У�ҲΪ��Ѱ�Ҵ�������
			for(int row=0;row<length-1;row++){					
				//��ѭ��Ϊ���жϸ����е������Ƿ���Ժϲ����Ƿ�����ƶ����Կ��Բ��������ֽ��в���
				//���濪ʼ��������
				if (num[row][line]==1){
					//���������������������
					if(num[row+1][line]==2){									
						//˵�����ֿ��Ժϲ� �ʽ���ϲ������ҽ��������������ƶ�
						num[row][line]=3;
						int temprow1=row+1;									
						for (;temprow1<length-1;temprow1++)
							num[temprow1][line]=num[temprow1+1][line];
						num[temprow1][line]=0;
						bigflag++;
						break;
					}
					else
						//���������޷��ϲ�������ѭ�����жϸ��е���һ������
						continue;
				}
				if (num[row][line]==2){
					//ͬ�ϴ������治��׸��
					if(num[row+1][line]==1){									
						num[row][line]=3;
						int temprow1=row+1;											
						for (;temprow1<length-1;temprow1++)
							num[temprow1][line]=num[temprow1+1][line];
						num[temprow1][line]=0;
						bigflag++;
						break;
					}
					else 
						continue;
				}
				else if(num[row][line]>=3){
					//ͬ�ϴ�������׸��
					if(num[row+1][line]==num[row][line]){
						num[row][line]=2*num[row][line];
						int temprow1=row+1;							
						for (;temprow1<length-1;temprow1++)
							num[temprow1][line]=num[temprow1+1][line];
						num[temprow1][line]=0;
						bigflag++;
						break;
					}
					else 
						continue;
				}
				else if (num[row][line]==0){
					//����������������㣬��û�����֣�����Ҫ��һ���жϣ�
					//�����һ��֮����������ֶ����㣬��ô���������޷��ƶ�
					//�����һ��֮������ִ��ڲ�����ģ���ô�������ֿ��Ա��ƶ�
					int judge=0,temprow1=row+1;					
					for(;temprow1<length;temprow1++)
						if(num[temprow1][line]!=0)
							judge++;
					if (judge==0)
						//˵����һ�����ֶ�����
						break;
					else if (judge>0){
						//˵����һ�����ֿ����ƶ�
						int temprow2=row;										
						for (;temprow2<length-1;temprow2++)
							num[temprow2][line]=num[temprow2+1][line];
						num[temprow2][line]=0;
						bigflag++;
						break;
					}
				}
			}
			//�������������ж϶�����֮����Ҫ�ж����������Ƿ������ĩβ��������
			if(num[length-1][line]==0){
				//˵�����Ա�������֣������¼����һ�������д�����
				linenum++;
				buffer[linenum]=line;											
			}
		}
		if (linenum==-1){
			//˵��û�����ܹ��ٱ���������ˣ���Ҫ��һ���ж��Ƿ������Ѿ������ƶ�
			if (!judge()){
				//˵����Ϸ����
				cout<<"��ѽ~��Ϸ����������\n";
				endflag=1;
			}
			else if (bigflag==0){
				//˵����Ϸ��û�н�����������������ϵ��ƶ�����Ч��
				cout<<"��Ǹ~��������ЧŶ~\n";
				Sleep(500);
			}
		}
		else {
			//�������п��Ա���������ˣ��������ǰ����������ƶ��������ֱ������ˣ���Ҫ�ж���һ��
			if (bigflag==0){
				//˵��û�����ֱ�������һ�ζ�����Ȼ���ܹ��������
				cout<<"��Ǹ~��������ЧŶ~\n";
				Sleep(500);
			}
			else 
				//˵�������ֱ������ˣ������������
				//�����ѡһ���������У�������������һ������	
				num[length-1][buffer[rand()%(linenum+1)]]=randomnum();
		}
}
void number::move(char movement){
	//ʵ�����ֵ��ƶ����ϲ��������㷨��
	//�����������¼��������ĩβ������֡��Ĵ�������/����
	//���Ǳ���Ϸ�������㷨����w��s��a��d�ĸ�����Ĳ��������Ƶģ�����wΪ������ϸ����ÿһ�������壬���಻��׸��
	switch(movement){
	case'w':
	case'W':
		upmove(num);
		break;
	case's':
	case'S':
		for(int line=0;line<length;line++){
			for (int row=0;row<length;row++)
				buffernum[row][line]=num[length-1-row][line];
		}
		upmove(buffernum);
		for(int line=0;line<length;line++){
			for (int row=0;row<length;row++)
				num[row][line]=buffernum[length-1-row][line];
		}
		break;
	case'a':
	case'A':
		for(int line=0;line<length;line++){
			for (int row=0;row<length;row++)
				buffernum[row][line]=num[line][row];
		}
		upmove(buffernum);
		for(int line=0;line<length;line++){
			for (int row=0;row<length;row++)
				num[row][line]=buffernum[line][row];
		}
		break;
	case'd':
	case'D':
		for(int line=0;line<length;line++){
			for (int row=0;row<length;row++)
				buffernum[row][line]=num[line][length-1-row];
		}
		upmove(buffernum);
		for(int line=0;line<length;line++){
			for (int row=0;row<length;row++)
				num[row][line]=buffernum[length-1-line][row];
		}
		break;
		break;
	default:
		cout<<"��ѽ�ⲻ�Ƿ�����ģ����������~";
		Sleep(500);
		break;
	}
}

bool number::judge(){//����Ϸ�������򷵻�0�������Լ������򷵻�1
	bool flag=0;
//�ж�ws�������Ƿ������ֶԿ��Լ�����Ϸ
	for(int line=0;line<length;line++){
		for(int row=0;row<length-1;row++){
			if(num[row][line]==1){
				if(num[row+1][line]==2)
					return flag=1;
				else continue;
			}
			else if	(num[row][line]==2){
				if(num[row+1][line]==1)
					return flag=1;
				else continue;
			}
			else if (num[row][line]>=3){
				if (num[row+1][line]==num[row][line])
					return flag=1;
				else continue;
			}
		}
	}
//�ж�ad�������Ƿ������ֿ��Լ�����Ϸ
	for(int row=0;row<length;row++){
		for(int line=0;line<length-1;line++){
			if(num[row][line]==1){
				if(num[row][line+1]==2)
					return flag=1;
				else continue;
			}
			else if (num[row][line]==2){
				if(num[row][line+1]==1)
					return flag=1;
				else continue;
			}
			else if (num[row][line]>=3){
				if (num[row][line+1]==num[row][line])
					return flag=1;
				else continue;
			}
		}
	}
	return 0;
}

int number::scorecal(){
	//�����ֲܷ����ط���ֵ
	int score=0;
	for (int line=0;line<length;line++)
		for (int row=0;row<length;row++){
			if(num[row][line]==1||num[row][line]==2)
				score+=10;
			else if (num[row][line]>=3)
				score+=20*num[row][line]/3;
		}
	return score;
}

void number::vipsettle(){
	//vip��ҿ����������1,2,3����
	for (int row=0;row<length;row++)
		for (int line=0;line<length;line++)
			if (num[row][line]==1||num[row][line]==2||num[row][line]==3)
				num[row][line]=0;
	endflag=0;
}

void number::settle(){
	//���ã������е����ֽ������㣬���߳���������
	length=0;
	endflag=0;
	for (int row=0;row<length;row++)
		for (int line=0;line<length;line++)
			num[row][line]=0;
}
