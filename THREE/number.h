/*
------------------------------------------------------------
		游戏主体模块
		将各方块中数字和对数字的操作封装为一个类
		头文件
------------------------------------------------------------
*/
#ifndef _NUMBER_H_
#define _NUMBER_H_
class number
{
	//私有数据成员
	int length;															//用于记录游戏界面的边长
	int** num;															//用于动态申请二维数组，在其中存放各个数字
	int** buffernum;
	//私有函数成员
	bool judge();														//判断游戏是否已经结束，若游戏结束，则返回0，若可以继续，则返回1
																					//被move()函数调用
	void printnumber(int a,int b);						//打印各数字，并且实现不同数字不同颜色
																					//被printinterface()函数调用
	int randomnum();												//按照一定比例随机生成数字
																					//被initialization()和move()函数调用
	void upmove(int **num);
public:
	//公有数据成员
	bool endflag;															//用于对外显示是否游戏结束，提高函数效率，避免多次重复判断
	//公有函数成员
	number(int length);											//构造函数，动态分配二维数组内存
	~number();															//析构函数，释放二维数组
	void printinterface();										//打印整体游戏界面
	void initialization();											//初始化游戏
	void move(char movement);							//实现数字的移动，合并使
	int scorecal();														//计算总分并返回分数值
	void vipsettle();													//vip玩家可以随机消除1,2,3数字
	void settle();														//重置，对所有的数字进行清零，将边长参数清零
};

#endif 