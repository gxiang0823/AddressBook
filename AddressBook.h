#pragma once
#include<iostream>
#include<fstream>
#include"Contacts.h"
#define FILENAME "ConFile.txt"
using namespace std;

class AddressBook
{
public:
	//构造函数
	AddressBook();

	//展示菜单
	void ShowMenu();

	//退出系统
	void ExitSystem();

	//添加联系人
	void AddPerson();

	//通讯录人数
	int m_ConNum;

	//联系人数组指针
	Contacts** m_ConArray;

	//文件是否为空标志
	bool m_FileIsEmpty;

	//获取联系人数目
	int Get_ConNum();

	//读取文件数据
	void Init_Con();

	//存储文件
	void SaveCon();

	//显示联系人
	void ShowPerson();

	//删除联系人
	void DelPerson();

	//存在性判断
	int IsExist(string name);

	//修改联系人
	void ModPerson();

	//查找联系人
	void FindPerson();

	//清空通讯录
	void CleanFile();
};