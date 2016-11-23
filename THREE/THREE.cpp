/*
---------------------------------------------------
|		C++DOS����С��Ϸ������    Դ�ļ�չʾ		|	
|																						|
|											���ߣ�����					|
|											ѧ�ţ�2014010902		|
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

//Ϊ�ж��Ƿ���Ҫ����excel 
void judgeexcel();	

int main(){
	//��ϵͳʱ�䶨Ϊ���������
	srand((unsigned)time(NULL));
	judgeexcel();
	scene SCENE;
	SCENE.whole();//��������
}

void judgeexcel(){
	//���Ѿ����ļ��������κζ���
	//��û���ļ����򴴽�excel��񣬲���д�õ�һ�л�����Ϣ
	fstream _file;
	_file.open("user.xlsx",ios::in);
	if(_file);
	else {
		Book* book=xlCreateXMLBook();
		if (book){
			Sheet* sheet=book->addSheet(L"Sheet1");
			if (sheet){
				//����һ��excel��񣬹����У�����������Ϊ��username,score,date
				sheet->writeStr(0, 0, L"User Name");
				sheet->writeStr(0,1,L"Score");
				sheet->writeStr(0,2,L"Date");
				//���õ�Ԫ���ʽ
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