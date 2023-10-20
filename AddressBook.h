#pragma once
#include<iostream>
#include<fstream>
#include"Contacts.h"
#define FILENAME "ConFile.txt"
using namespace std;

class AddressBook
{
public:
	//���캯��
	AddressBook();

	//չʾ�˵�
	void ShowMenu();

	//�˳�ϵͳ
	void ExitSystem();

	//�����ϵ��
	void AddPerson();

	//ͨѶ¼����
	int m_ConNum;

	//��ϵ������ָ��
	Contacts** m_ConArray;

	//�ļ��Ƿ�Ϊ�ձ�־
	bool m_FileIsEmpty;

	//��ȡ��ϵ����Ŀ
	int Get_ConNum();

	//��ȡ�ļ�����
	void Init_Con();

	//�洢�ļ�
	void SaveCon();

	//��ʾ��ϵ��
	void ShowPerson();

	//ɾ����ϵ��
	void DelPerson();

	//�������ж�
	int IsExist(string name);

	//�޸���ϵ��
	void ModPerson();

	//������ϵ��
	void FindPerson();

	//���ͨѶ¼
	void CleanFile();
};