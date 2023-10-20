#include<iostream>
#include"AddressBook.h"
#include"Contacts.h"
using namespace std;

int main()
{
	AddressBook abs;
	int Choice = 0;
	while (true)
	{
		abs.ShowMenu();
		cout << "����������ѡ��" << endl;
		if (!(cin >> Choice))
		{
			cin.clear();												// ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n');		// �������뻺�����е������ַ���ֱ���������з�
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			continue;
		}
		switch (Choice)
		{
		case 0:		//�˳�ͨѶ¼
			abs.ExitSystem();
			break;
		case 1:		//�����ϵ��
			abs.AddPerson();
			break;
		case 2:		//��ʾ��ϵ��
			abs.ShowPerson();
			break;
		case 3:		//ɾ����ϵ��
			abs.DelPerson();
			break;
		case 4:		//�޸���ϵ��
			abs.ModPerson();
			break;
		case 5:		//������ϵ��
			abs.FindPerson();
			break;
		case 6:		//���ͨѶ¼
			abs.CleanFile();
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
		//cin.clear();												// ��������־
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');		// �������뻺�����е������ַ���ֱ���������з�
	}

	system("pause");

	return 0;
}