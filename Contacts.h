#pragma once
#include<iostream>
using namespace std;

class Contacts
{
public:
	//���캯��
	Contacts(string name, int sex, int age, string phone, string addr);

	//��ʾ��Ϣ
	void ShowInfo();

	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//��ַ
	string m_Addr;
};