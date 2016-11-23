/*
------------------------------------------------------------
		界面调用模块
		将界面的所有打印操作封装为一个类
		头文件
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
	void printline();													//打印横线条，为方便排版界面所设
	void printvoid();												//打印空行，和两边边界，为方便排版界面所设
	void BeginInterface();										//打印欢迎界面
	void FirstInterface();										//打印最开始的选择界面
	void RuleInterface();										//打印游戏规则
	void Rankinginterface();								//打印excel表格中现有的玩家前5名（若不足5名就打印所有）
	void MoreInfointerface();								//打印作者的个人信息
	void VIPInterface();											//对VIP用户，创建vipuser类
	void nVIPInterface();										//对非VIP用户，创建user类
	void PlayerInterface(user* PLAYER);			//不论是否是VIP用户，统一处理，实现多态
	int GameInterface(user* PLAYER);				//游戏运行，返回值为最终得分，退出前重置所有数字（保险起见）
	void whole();														//对所有的函数进行调用
};

#endif