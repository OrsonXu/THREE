/*
------------------------------------------------------------
		界面调用模块
		cpp实现文件
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
	//打印横线条，为方便排版界面所设
	for (int i=0;i<40;i++) cout<<"-";
	cout<<"\n";
}

void scene::printvoid(){
	//打印空行，和两边边界，为方便排版界面所设
	cout<<"|";
	for (int i=0;i<38;i++) cout<<" ";
	cout<<"|\n";
}

void scene::BeginInterface(){
	//打印欢迎界面
	printline();
	printvoid();
	cout<<"|";
	for (int i=0;i<9;i++) cout<<" ";
	cout<<"欢迎来到DOS界面小游戏";
	for (int i=0;i<8;i++) cout<<" ";
	cout<<"|\n";
	cout<<"|";
	for (int i=0;i<18;i++) cout<<" ";
	cout<<"——三";
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
	//打印最开始的选择界面
	cout<<"\n\n";
	printline();
	printvoid();
	cout<<"|\t三 ——  主界面  —— 三       |\n";
	printvoid();
	cout<<"|\t      进入游戏【B】            |\n";
	cout<<"|\t      查看规则【R】            |\n";
	cout<<"|\t      查看排名【L】            |\n";
	cout<<"|\t      更多信息【I】            |\n";
	cout<<"|\t      退出游戏【Q】            |\n";
	printvoid();
	printline();
}
void scene::RuleInterface(){
	//打印游戏的规则
	printline();
	printvoid();
	cout<<"|\t     游戏规则——三            |\n";
	printvoid();
	cout<<"|      “三”是一款精致简约的小游戏。  |\n";
	printvoid();
	cout<<"|  操作规则：                          |\n";
	cout<<"|      玩家通过w、s、a、d分别作为上、  |\n";
	cout<<"|  下、左、右方向键 ，控制方块移动。对 |\n";
	cout<<"|  每一次移动，数字只移动一格。        |\n";
	cout<<"|      数字“1”只能与数字“2”组合为  |\n";
	cout<<"|  “3”，而“3”及以上的数字则只能与  |\n";
	cout<<"|  相同的数字组合成为更高级的数字。每  |\n";
	cout<<"|  一次成功的移动，新的数字将随机出现  |\n";
	cout<<"|  在与移动方向相对的最后一行/列。当   |\n";
	cout<<"|  数字填满方块，且没有数字可以组合时  |\n";
	cout<<"|  ，游戏结束。                        |\n";
	printvoid();
	cout<<"|  贵宾特权：                          |\n";
	cout<<"|      玩家需要输入正确的贵宾密码才能  |\n";
	cout<<"|  够成为贵宾。贵宾的每一次游戏，都有  |\n";
	cout<<"|  一次特殊功能使用权，可以消除当前方  |\n";
	cout<<"|  块中所有的数字“1”、“2” 与“3”，|\n";
	cout<<"|  被消除的数字不被计入总分。该特权只  |\n";
	cout<<"|  能在游戏本当结束时使用。            |\n";
	printvoid();
	cout<<"|  记分规则：                          |\n";
	cout<<"|  每个“1”，“2”为10分，“3”为20分 |\n";
	cout<<"|  “6”为40分，“12”为80分，以此类推 |\n";
	cout<<"|  最终得分为方块中所有得分的总和。    |\n";
	printvoid();
	printline();
	cout<<"请按任意键返回...";
	char buffer;
	buffer=_getch();if((int)buffer==0||(int)buffer==-32) _getch();
}
void scene::Rankinginterface(){
	//打印excel表格中现有的玩家前5名（若不足5名就打印所有）
	printline();
	printvoid();
	cout<<"|              实力英雄榜              |"<<endl;
	printvoid();
	user::ranking();		//调用user类中的静态成员函数，展示排名
	printvoid();
	printline();
	cout<<"请按任意键返回...";
	char buffer;
	buffer=_getch();if((int)buffer==0||(int)buffer==-32) _getch();
}
void scene::MoreInfointerface(){
	//打印作者的个人信息
	printline();
	printvoid();
	cout<<"|             作者个人信息             |"<<endl;
	printvoid();
	cout<<"|         姓名：\t徐栩海         |"<<endl;
	cout<<"|         班级：\t工四二         |"<<endl;
	cout<<"|         学号：\t2014010902     |"<<endl;
	printvoid();
	cout<<"|         本项目只用于学习交流         |"<<endl;
	cout<<"|           禁止任何商业用途           |"<<endl;
	printvoid();
	printline();
	cout<<"请按任意键返回...";
	char buffer;
	buffer=_getch();if((int)buffer==0||(int)buffer==-32) _getch();
}

void scene::VIPInterface(){
	// 对VIP用户进行处理
	//创建VIP类的用户（从VIP类用户继承）
	vipuser VIPPLAYER;
	PlayerInterface(& VIPPLAYER);
}

void scene::nVIPInterface(){
	//对非VIP用户进行处理
	//创建非VIP类的用户
	user nVIPPLAYER;
	PlayerInterface(& nVIPPLAYER);
}

void scene::PlayerInterface(user* PLAYER){
	//不论是否是VIP用户，统一处理

	//对PLAYER对象中的一些参数进行初始化
	PLAYER->initialization();
	if (PLAYER->vipflag){
		printline();
		printvoid();
		cout<<"|——尊敬的稀客，敢问您是老手？        |\n";
		printvoid();
		cout<<"|  恭维恭维称不得，但多少玩过几次【1】 |\n";
		cout<<"|  第一次来，未尝有过记录        【2】 |\n";
		printvoid();
		printline();
	}
	else {
		printline();
		printvoid();
		cout<<"|——这位客人，敢问您是否是老手？      |\n";
		printvoid();
		cout<<"|  老手称不上，但是多少玩过几次【1】   |\n";
		cout<<"|  第一次来，未尝有过记录      【2】   |\n";
		printvoid();
		printline();
	}
	for (;;){
		//死循环方便重复输入
		bool JUDGE1=0;		//由于采用switch，break不容易跳出循环，借助该值用于在适合时间跳出
		char oldjudge;
		cout<<"请输入：";
		//实现不需要用回车键入，直接输入即可响应
		oldjudge=_getch();if((int)oldjudge==0||(int)oldjudge==-32) _getch();cout<<oldjudge<<endl;
		switch(oldjudge){
			{
		case '1':
			JUDGE1=1;
			cout<<"\n——好的，请看下面的花名册，有没有您的大名：\n"<<endl;
			PLAYER->olduser();
			cout<<"载入成功！\n请稍等，游戏即将开始..."; 
			Sleep(1000);
			break;
			}
			{
		case '2':
			JUDGE1=1;
			cout<<"\n——那请写下您的大名吧（按回车键结束哦~）：";
			PLAYER->newuser();
			cout<<"——您的大名已被记录~\n请稍等，游戏即将开始...";
			Sleep(1000);
			break;
			}
		default:
			cout<<"——您输错了...请重新输入哦...\n";
			Sleep(500);
			break;
		}
		if (JUDGE1)
			break;
		else
			continue;
	}
	for (;;){
		//死循环为了实现可以重复进行游戏

		//调用游戏界面，进行游戏，游戏结束后直接记录分数
		PLAYER->setscore(GameInterface(PLAYER));
		//将分数写入文件中
		PLAYER->record();
		bool JUDGE2=0;		//同理，由于采用switch，break不容易跳出循环，借助该值用于在适合时间跳出
		printline();
		printvoid();
		cout<<"|——您玩得感觉如何？                  |\n";
		printvoid();
		cout<<"|  甚爽！还没过瘾，再来一局！【1】     |\n";
		cout<<"|  待我修炼一番再来战吧！    【2】     |\n";
		printvoid();
		printline();
		char continuejudge;
		continuejudge=_getch();if((int)continuejudge==0||(int)continuejudge==-32) _getch();cout<<continuejudge<<endl;
		switch(continuejudge){
		case '1':
			JUDGE2=1;
			//对除用户名之外的东西进行重置
			PLAYER->settle();
			cout<<"——稍等哦~游戏正在为您重置...\n";
			Sleep(500);
			break;
		case '2':
			cout<<"——好叻~那咱就回去啦~\n";
			Sleep(1000);
			break;
		default:
			cout<<"——您输错了...那就当您暂时不玩了吧.."<<endl;
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
	//游戏界面运行，返回值为最终得分，退出前，重置矩阵中的所有数字（保险起见）
	system("CLS");
	cout<<"******************* loading...***********************\n";
	Sleep(100);
	//实现游戏真实体验感
	for(int i=0;i<4;i++){
		for (int j=0;j<13;j++)
			cout<<"*";
		Sleep(300);
	}
	cout<<"*\n";
	Sleep(300);
	cout<<"载入成功！\n";
	int length,bufferscore=0;
	char clength;
	cout<<"——这位客官，请自定义游戏界面边长：";
	//确定游戏界面的大小
	clength=_getch();
	//将字符型转换为整型
	length=clength-48;
	if(length==-80||length==-48) _getch();
	cout<<length<<endl;
	while(length<=2){
		if (length<=0)
			cout<<"边长怎么可以不是正的呢？！您的数学是体育老师教的呀~\n重新输入哦~：";
		else if(length>0&&length<=2)
			cout<<"您这玩的也太没有难度了吧？~咱玩大一点的呗~\n重新输入哦~：";
		clength=_getch();
		length=clength-48;
		if(length==-80||length==-48) _getch();
		cout<<length<<endl;
	}
	cout<<"游戏正在为您初始化...\n";
	Sleep(1000);
	//创建游戏模块类
	number THREE(length);
	system("CLS");
	//初始化THREE对象中的一些参数
	THREE.initialization();
	//打印游戏界面
	THREE.printinterface();
	for(;;){
		//正式开始游戏，死循环为了每次实现输入动作和退出
		char movement;
		cout<<"请输入您的动作：";
		movement=_getch();if((int)movement==0||(int)movement==-32) _getch();cout<<movement<<endl;
		Sleep(100);
		THREE.move(movement);
		if(THREE.endflag){
			//判断游戏结束，如果是vip则有机会继续游戏
			if (PLAYER->vipflag){ 
				//判断是否是vip玩家
				//如果是，则临时强制转换为指向vipuser的指针
				vipuser* vipPLAYER; 
				vipPLAYER=dynamic_cast <vipuser*>(PLAYER);
				if (vipPLAYER->remove()){
					//如果有机会继续游戏，那么根据用户意愿看是否需要使用VIP功能
					cout<<"请问您是否要使用vip功能？(请注意被消除的数字将不再被计入得分)(Y/N)：";
					char vipmethodjudge;
					cin>>vipmethodjudge;
					switch(vipmethodjudge){
					case 'y':
					case 'Y':
						THREE.vipsettle();				//消去其中的1，2，3这些数字
						system("CLS");
						THREE.printinterface();
						break;
					case 'n':
					case 'N':
						break;
					default:
						cout<<"很抱歉您的输入有误！默认为不使用消除功能。"<<endl;
						break;
					}
				}
			}
			if (THREE.endflag){
				//若经过上面的步骤之后endflag没有变化，说明不是VIP玩家，或者是VIP玩家没有使用消除工具，游戏结束，计算得分
				cout<<"正在计算您的得分...\n";
				bufferscore=THREE.scorecal();
				Sleep(500);
				cout<<"您的得分为："<<bufferscore<<endl;
				break;
			}
		}
		else {
			//否则刷新界面，继续游戏
			system("CLS");
			THREE.printinterface();
		}
	}
	return bufferscore;
}

void scene::whole(){
	//对所有的函数进行调用
	BeginInterface();
	FirstInterface();
	for (;;){
		char choice;
		cout<<"请选择：";
		choice=_getch();if((int)choice==0||(int)choice==-32) _getch();cout<<choice<<endl;
		switch(choice){
		case 'q':
		case 'Q':
			cout<<"退出游戏...欢迎下次再来~\n";
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
			cout<<"|——这位兄弟，有些面熟，是贵客？      |\n";
			printvoid();
			cout<<"|  请看，这是贵宾卡，吾乃稀客也【1】   |\n";
			cout<<"|  非也非也，路过而已，常客罢了【2】   |\n";
			printvoid();
			printline();
			cout<<"请输入：";		
			char userjudge;
			userjudge=_getch();if((int)userjudge==0||(int)userjudge==-32) _getch();cout<<userjudge<<endl;
			switch(userjudge){
				{
			case '1':
				string password;
				for (;;){
					//死循环为了保证可以多次尝试着输入密码
					cout<<"\n——请输入您的VIP密码（以回车结束）：";
					cin>>password;
					if(password=="three"||password=="THREE"){
						cout<<"——恭喜您密码正确！\n"<<endl;
						VIPInterface();
						break;
					}
					else{
						char continuejudge;
						printline();
						printvoid();
						cout<<"|——抱歉您输入的密码有误！            |\n";
						printvoid();
						cout<<"|  一时手抖，请让鄙人再输一次吧  【1】 |\n";
						cout<<"|  老夫健忘，这次就不坐贵宾席了吧【2】 |\n";
						printvoid();
						printline();
						cout<<"请输入：";
						continuejudge=_getch();if((int)continuejudge==0||(int)continuejudge==-32) _getch();cout<<continuejudge<<endl;
						if (continuejudge=='1')
							//采用if而不采用switch，方便跳出死循环
							continue;
						else if (continuejudge=='2'){
							nVIPInterface();
							break;
						}
						else{
							cout<<"\n——我似乎没有听懂您说的话，那就当做您不坐贵宾席了吧。"<<endl;
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
				cout<<"\n——我咋没听懂？那就当您是常客吧~\n";
				Sleep(500);
				nVIPInterface();
				break;
			}
			break;
		default:
			cout<<"抱歉您的输入有误！请重新输入。"<<endl;
			Sleep(500);
			break;
		}
		system("CLS");
		BeginInterface();
		FirstInterface();
	}
}
