/*
------------------------------------------------------------
		游戏主体模块
		cpp实现文件
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
	//打印各数字，并且实现不同数字不同颜色
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
	//按照一定比例随机生成数字
	//在本程序当中，1,2出现的概率各占25%，3出现的概率占29%，
	//6出现的概率占12%，12出现的概率占6%  24出现的概率占3%
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
	//打印整体游戏界面
	for (int i=0;i<10*length+1;i++) 
		cout<<"-";
	cout<<"\n";
	for(int k=0;k<length;k++){
		//无数字行
		cout<<"|";						
		for (int i=0;i<length;i++){
			for (int j=0;j<9;j++)
				cout<<" ";
			cout<<"|";
		}							
		cout<<"\n";					
		//有数字行
		cout<<"|";
		for (int i=0;i<length;i++){
			printnumber(k,i);
			for (int j=0;j<4;j++)
				cout<<" ";
			cout<<"|";
		}
		cout<<"\n";
		//无数字行	
		cout<<"|";						
		for (int i=0;i<length;i++){
			for (int j=0;j<9;j++)
				cout<<" ";
			cout<<"|";
		}
		cout<<"\n";
		//分行	
		for (int i=0;i<10*length+1;i++) 
			cout<<"-";
		cout<<"\n";
	}
}


void number::initialization(){
	//初始化游戏，对其中随机位置的数字进行随机初始化
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
		int bigflag=0;																		//记录所有列当中，有多少列可以被移动，若没有，则说明操作无效。
		int linenum=-1;																	//记录待处理列的数量-1   （减1为了迎合数组的情况，并且不浪费空间）
		for(int line=0;line<length;line++){							
			//此循环为了寻找所有的能够有数字变化的列，也为了寻找待处理列
			for(int row=0;row<length-1;row++){					
				//此循环为了判断该列中的数字是否可以合并，是否可以移动，对可以操作的数字进行操作
				//下面开始分类讨论
				if (num[row][line]==1){
					//对这种情况继续分类讨论
					if(num[row+1][line]==2){									
						//说明数字可以合并 故将其合并，并且将此列整体向上移动
						num[row][line]=3;
						int temprow1=row+1;									
						for (;temprow1<length-1;temprow1++)
							num[temprow1][line]=num[temprow1+1][line];
						num[temprow1][line]=0;
						bigflag++;
						break;
					}
					else
						//否则数字无法合并，继续循环，判断该列的下一个数字
						continue;
				}
				if (num[row][line]==2){
					//同上处理，下面不作赘述
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
					//同上处理，不作赘述
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
					//如果碰到了数字是零，即没有数字，则需要进一步判断：
					//如果这一列之后的所有数字都是零，那么这列数字无法移动
					//如果这一列之后的数字存在不是零的，那么这列数字可以被移动
					int judge=0,temprow1=row+1;					
					for(;temprow1<length;temprow1++)
						if(num[temprow1][line]!=0)
							judge++;
					if (judge==0)
						//说明这一列数字都是零
						break;
					else if (judge>0){
						//说明这一列数字可以移动
						int temprow2=row;										
						for (;temprow2<length-1;temprow2++)
							num[temprow2][line]=num[temprow2+1][line];
						num[temprow2][line]=0;
						bigflag++;
						break;
					}
				}
			}
			//这列所有数字判断都结束之后，需要判断这列数字是否可以在末尾添上数字
			if(num[length-1][line]==0){
				//说明可以被添加数字，将其记录在另一个数组中待处理
				linenum++;
				buffer[linenum]=line;											
			}
		}
		if (linenum==-1){
			//说明没有列能够再被添加数字了，需要进一步判断是否数字已经不可移动
			if (!judge()){
				//说明游戏结束
				cout<<"诶呀~游戏结束了诶！\n";
				endflag=1;
			}
			else if (bigflag==0){
				//说明游戏还没有结束，但是这个方向上的移动是无效的
				cout<<"抱歉~本操作无效哦~\n";
				Sleep(500);
			}
		}
		else {
			//尽管有列可以被添加数字了，但是这个前提是在这次移动中有数字被处理了，需要判断这一点
			if (bigflag==0){
				//说明没有数字被处理，这一次动作依然不能够添加数字
				cout<<"抱歉~本操作无效哦~\n";
				Sleep(500);
			}
			else 
				//说明有数字被处理了，可以添加数字
				//随机挑选一条待处理行，在最后随机加入一个数字	
				num[length-1][buffer[rand()%(linenum+1)]]=randomnum();
		}
}
void number::move(char movement){
	//实现数字的移动，合并（主体算法）
	//该数列用与记录“可以在末尾添加数字”的待处理列/行数
	//这是本游戏的主体算法，对w、s、a、d四个方向的操作是类似的，故以w为例，详细阐述每一步的意义，其余不做赘述
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
		cout<<"诶呀这不是方向键哪！重新输入吧~";
		Sleep(500);
		break;
	}
}

bool number::judge(){//若游戏结束，则返回0，若可以继续，则返回1
	bool flag=0;
//判断ws方向上是否还有数字对可以继续游戏
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
//判断ad方向上是否还有数字可以继续游戏
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
	//计算总分并返回分数值
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
	//vip玩家可以随机消除1,2,3数字
	for (int row=0;row<length;row++)
		for (int line=0;line<length;line++)
			if (num[row][line]==1||num[row][line]==2||num[row][line]==3)
				num[row][line]=0;
	endflag=0;
}

void number::settle(){
	//重置，对所有的数字进行清零，将边长参数清零
	length=0;
	endflag=0;
	for (int row=0;row<length;row++)
		for (int line=0;line<length;line++)
			num[row][line]=0;
}
