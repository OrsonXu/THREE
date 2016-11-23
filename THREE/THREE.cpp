/*
---------------------------------------------------
|		C++DOS界面小游戏——三    源文件展示		|	
|																						|
|											作者：徐栩海					|
|											学号：2014010902		|
|																						|
---------------------------------------------------
*/

#include "scene.h"
#include "libxl.h"
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
using namespace libxl;

//为判断是否需要创建excel 
void judgeexcel();	

int main(){
	//将系统时间定为随机数种子
	srand((unsigned)time(NULL));
	judgeexcel();
	scene SCENE;
	SCENE.whole();//主调函数
}

void judgeexcel(){
	//若已经有文件，则不做任何动作
	//若没有文件，则创建excel表格，并且写好第一行基本信息
	fstream _file;
	_file.open("user.xlsx",ios::in);
	if(_file);
	else {
		Book* book=xlCreateXMLBook();
		if (book){
			Sheet* sheet=book->addSheet(L"Sheet1");
			if (sheet){
				//生成一个excel表格，共三列，从左到右依次为，username,score,date
				sheet->writeStr(0, 0, L"User Name");
				sheet->writeStr(0,1,L"Score");
				sheet->writeStr(0,2,L"Date");
				//设置单元格格式
				sheet->setCol(0,2,30);
			}
			else 
				cout<<"Cannot find the sheet!"<<endl;
			if(book->save(L"user.xlsx"));
			else
				cout<<book->errorMessage()<<endl;
		}
		else 
			cout<<"Cannot create a book!"<<endl;
		book->release();
	}
}