/*
------------------------------------------------------------
		用户类
		cpp实现文件
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

//设置全局的时间变量，为了方便之后在记录中记录游戏日期。
time_t tt = time(NULL);
tm* t= localtime(&tt);

//静态数据初始化，一开始两种人数都为零
int user::usercount=0;
int user::allusercount=0;

user::user(std::wstring name/*=L"defaultuser"*/){
	//构造函数，默认用户名，同时确定标记ID，user对象为非VIP用户
	this->username=name;
	vipflag=0;
}

user::~user(void){
	//析构函数，释放动态内存
	delete [] oldusers;
	delete [] olduserNO;
}

void user::initialization(){
	//初始化信息，把表格中的信息——所有条目数量，不同的用户名记录到其中，同时为其变编号
	Book* book=xlCreateXMLBook();
	if (book){
		if (book->load(L"user.xlsx")){
			Sheet* sheet=book->getSheet(0);
			if(sheet){
				allusercount=sheet->lastRow()-1;							//由于第一行不是用户，需要减1
				oldusers=new wstring[allusercount];					//动态申请最大可能的不同用户数量
				olduserNO=new int[allusercount];							//动态申请对应的编号数组
				for (int i=1;i<=allusercount;i++){
					wstring buffername = sheet->readStr(i, 0);
					if (i==1){
						//第一个账户可以直接记录
						oldusers[0]=buffername;
						olduserNO[0]=1;
						usercount=1;
					}
					else{
						//不同的名字才能够算作不同的玩家，查找已有的用户名字，用flag标记
						//若是新的名字，则算作新的用户，否则不作处理
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
	//打印出所有的已有用户的用户名，并且让用户从中选择用户名
	Book* book=xlCreateXMLBook();
	if (book){
		if (book->load(L"user.xlsx")){
			Sheet* sheet=book->getSheet(0);
			if(sheet){
				//用于记录目前在玩的玩家名字对应的的编号
				int nownumber;																	
				for (int i=0;i<40;i++) cout<<"-";
				cout<<"\n";
				cout<<"|\t用户名\t\t编号           |"<<endl;
				cout<<"|";
				for (int i=0;i<38;i++) cout<<" ";
				cout<<"|\n";
				for(int k=0;k<usercount;k++)
					//输出所有不同的玩家和编号
					wcout<<"|\t"<<oldusers[k]<<"\t\t"<<setw(3)<<olduserNO[k]<<"            |"<<endl;
				cout<<"|";
				for (int i=0;i<38;i++) cout<<" ";
				cout<<"|\n";
				for (int i=0;i<40;i++) cout<<"-";
				cout<<"\n";
				for (;;){
					//死循环为防止输入错误
					cout<<"您对应的编号是？（按回车键结束哦~）：";
					cin>>nownumber;
					if (nownumber>usercount||nownumber<1){
						cout<<"抱歉输入有误！请重新输入";
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
	//由用户自己输入名字
	wcin>>username;
}

void user::ranking(){
	//静态函数，打印出Excel中的前五名排行榜，若不足五人则全打印，可以直接通过类名调用
	//为实现一进入游戏就可以查看排行榜，不需要初始化
	//也正是因此，这个函数有些独立于别的函数之外，用户总数量是自己另外设置的。
	Book* book=xlCreateXMLBook();
	if (book){
		if (book->load(L"user.xlsx")){
			Sheet* sheet=book->getSheet(0);
			if(sheet){
				int allusercount=sheet->lastRow()-1;			//由于是静态函数，重新开一个变量覆盖类中值
				int* scorelist=new int [allusercount];			//记录所有的已有的得分
				int* scoreNO=new int [allusercount];			//记录其得分所在的行数，为了方便之后通过行数找到用户名
				for (int j=1;j<=allusercount;j++)
					scorelist[j-1]=static_cast<int>(sheet->readNum(j,1));
				for (int k=0;k<allusercount;k++)
					scoreNO[k]=k+1;
				int temp1,temp2;
				//采用插入排序法，同时对两个数组进行排序
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
				//以防excel中没有任何记录
				if(allusercount==0){
					cout<<"抱歉Excel中没有记录！"<<endl;
				}
				else {
					cout<<"|  "<<"排名\t用户名\t得分\t日期"<<setw(12)<<"|"<<endl;
					//以防excel中人数不够多
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
	//记录本次玩家的得分 
	this->score=score;
}

void user::record(){
	//将本次游戏的成绩记录到Excel中
	Book* book=xlCreateXMLBook();
	if (book){
		if (book->load(L"user.xlsx")){
			Sheet* sheet=book->getSheet(0);
			if(sheet){
				sheet->writeStr(allusercount+1,0,username.c_str());
				sheet->writeNum(allusercount+1,1,score);
				sheet->writeNum(allusercount+1, 2, book->datePack(t->tm_year+1900, t->tm_mon+1, t->tm_mday));
				allusercount++;
				//判断是否有必要对新用户的数量加1，原理同之前，借助flag标记
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
		//将数据存入excel表格当中
		if(book->save(L"user.xlsx"));
		else 
			cout<<"Save error!"<<endl;
		book->release();
	}
	else 
		cout<<"Cannot creat a book!"<<endl;
}

void user::settle(){
	//对除了用户名之外的内容进行重置
	//包括分数置零和重新从Excel表格中读取数据
	setscore(0);
	initialization();
}


vipuser::vipuser(std::wstring name/*=L"defaultuser"*/):user(name){
	//另外写构造函数，同时标记ID，vipuser对象为VIP用户
	vipremovetime=0;
	vipflag=1;
}

bool vipuser::remove(){
	//布尔值，记录VIP功能是否被使用
	if (vipremovetime!=0)
		return 0;
	else{
		vipremovetime=1;
		return 1;
	}
}

void vipuser::settle(){
	//覆盖原有的重置函数
	//包括分数置零和重新从Excel表格中读取数据，加上重置布尔值
	setscore(0);
	vipremovetime=0;
	vipflag=1;
}