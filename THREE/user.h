/*
------------------------------------------------------------
		用户模块
		将用户的信息、对用户信息的操作和对Excel中的信息的处理封装为一个类
		头文件
------------------------------------------------------------
*/
#ifndef _USER_H_
#define _USER_H_
#include <string>
#include "libxl.h"

class user
{
private:
	std::wstring username;										//记录当前玩家的名字
	std::wstring* oldusers;										//记录不同老用户的名字数组首地址
	int* olduserNO;														//对应不同老用户对应编号数组首地址
	int score;																	//记录玩家得分
public:
	//公有非静态数据成员
	bool vipflag;															//手动设置ID，用于记录是否是vip用户，方便判断
	//公有静态数据成员
	static int usercount;												//记录已有不同用户的总数目
	static int allusercount;										//记录整个已有的excel表格的总条目数量（包括相同）
	
	//公有非静态函数成员
	user(std::wstring name=L"defaultuser");	//构造函数，默认用户名，同时确定标记ID，user对象为非VIP用户
	virtual ~user(void);												//析构函数，释放动态内存
	virtual void initialization();								//初始化信息，把表格中的信息——所有条目数量，
																						//不同的用户名记录到*olduser为首地址的动态数组中，
																						//同时为其变编号，编号记录到 *olduserNO为首地址的动态数组中。
	virtual void olduser();											//打印出所有的已有用户的用户名，并且让用户从中选择用户名
	virtual void newuser();										//由用户自己输入名字
	virtual void setscore(const int score);			//记录本次玩家的得分
	virtual void record();											//将本次游戏的成绩记录到Excel中
	virtual void settle();												//对除了用户名之外的内容进行重置
	//公有静态函数成员
	static void ranking();											//打印出Excel中的前五名排行榜，若不足五人则全打印
};

class vipuser : public user{
	bool vipremovetime;											//用于记录VIP消除功能是否被使用
public:				
	vipuser(std::wstring name=L"defaultuser");//另外写构造函数，同时标记ID，vipuser对象为VIP用户
	bool remove();														//布尔值，记录VIP功能是否被使用
	void settle();															//覆盖原有的重置函数，且重置用于记录VIP功能是否被使用的布尔值
};

#endif