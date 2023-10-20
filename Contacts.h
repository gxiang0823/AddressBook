#pragma once
#include<iostream>
using namespace std;

class Contacts
{
public:
	//构造函数
	Contacts(string name, int sex, int age, string phone, string addr);

	//显示信息
	void ShowInfo();

	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//地址
	string m_Addr;
};