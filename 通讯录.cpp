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
		cout << "请输入您的选择" << endl;
		if (!(cin >> Choice))
		{
			cin.clear();												// 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n');		// 忽略输入缓冲区中的所有字符，直到遇到换行符
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			continue;
		}
		switch (Choice)
		{
		case 0:		//退出通讯录
			abs.ExitSystem();
			break;
		case 1:		//添加联系人
			abs.AddPerson();
			break;
		case 2:		//显示联系人
			abs.ShowPerson();
			break;
		case 3:		//删除联系人
			abs.DelPerson();
			break;
		case 4:		//修改联系人
			abs.ModPerson();
			break;
		case 5:		//查找联系人
			abs.FindPerson();
			break;
		case 6:		//清空通讯录
			abs.CleanFile();
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
		//cin.clear();												// 清除错误标志
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');		// 忽略输入缓冲区中的所有字符，直到遇到换行符
	}

	system("pause");

	return 0;
}