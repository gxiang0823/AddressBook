#include"AddressBook.h"

//构造函数
AddressBook::AddressBook()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "通讯录未创建!" << endl;
		//初始化属性
		this->m_ConNum = 0;
		this->m_ConArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，但为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "通讯录为空！" << endl;
		//初始化属性
		this->m_ConNum = 0;
		this->m_ConArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，且不为空
	int connum = this->Get_ConNum();
	cout << "联系人人数为： " << connum << endl;
	this->m_ConNum = connum;
	this->m_ConArray = new Contacts * [this->m_ConNum];
	this->Init_Con();

}

//展示菜单
void AddressBook::ShowMenu()
{
	cout << "**********************************" << endl;
	cout << "**********通讯录管理系统**********" << endl;
	cout << "********** 0、退出通讯录 *********" << endl;
	cout << "********** 1、添加联系人 *********" << endl;
	cout << "********** 2、显示联系人 *********" << endl;
	cout << "********** 3、删除联系人 *********" << endl;
	cout << "********** 4、修改联系人 *********" << endl;
	cout << "********** 5、查找联系人 *********" << endl;
	cout << "********** 6、清空通讯录 *********" << endl;
	cout << "**********************************" << endl;
}

//退出系统
void AddressBook::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//添加联系人
void AddressBook::AddPerson()
{
	int newSize = this->m_ConNum + 1;
	Contacts** newSpace = new Contacts * [newSize];
	if (this->m_ConArray != NULL)
	{
		for (int i = 0; i < this->m_ConNum; i++)
		{
			newSpace[i] = this->m_ConArray[i];
		}
	}

	//添加数据
	string name;
	int sex;
	int age;
	string phone;
	string addr;

	cout << "请输入联系人姓名： " << endl;
	cin >> name;

	while (true)
	{
		cout << "请输入联系人性别： " << endl;
		cout << "1 ---------- 男" << endl;
		cout << "2 ---------- 女" << endl;
		if (!(cin >> sex))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入有误，请重新输入!" << endl;
			continue;
		}
		else if (sex != 1 && sex != 2)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入有误，请重新输入!" << endl;
			continue;
		}
		else
			break;
	}

	while (true)
	{
		cout << "请输入联系人年龄： " << endl;
		if (!(cin >> age))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入有误，请重新输入!" << endl;
			continue;
		}
		else if (age<=0||age>200)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "年龄不正确，请重新输入"<< endl;
			continue;
		}
		else
			break;
	}

	cout << "请输入联系方式： " << endl;
	cin >> phone;

	cout << "请输入联系人地址： " << endl;
	cin >> addr;

	Contacts* con = NULL;
	con = new Contacts(name, sex, age, phone, addr);
	newSpace[this->m_ConNum] = con;

	//释放原有空间
	delete[] this->m_ConArray;
	this->m_ConArray = newSpace;
	this->m_ConNum = newSize;
	this->m_FileIsEmpty = false;

	cout << "添加联系人成功！" << endl;
	this->SaveCon();

	system("pause");
	system("cls");
}

//统计人数
int AddressBook::Get_ConNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string name;
	int sex;
	int age;
	string phone;
	string addr;

	int num = 0;
	while (ifs >> name && ifs >> sex && ifs >> age && ifs >> phone && ifs >> addr)
	{
		num++;
	}
	return num;
}

//读入数据
void AddressBook::Init_Con()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string name;
	int sex;
	int age;
	string phone;
	string addr;

	int index = 0;
	while (ifs >> name && ifs >> sex && ifs >> age && ifs >> phone && ifs >> addr)
	{
		Contacts* con;
		con = new Contacts(name, sex, age, phone, addr);
		this->m_ConArray[index] = con;
		index++;
	}

	ifs.close();
}

//存储文件
void AddressBook::SaveCon()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_ConNum; i++)
	{
		ofs << this->m_ConArray[i]->m_Name << "\t"
			<< this->m_ConArray[i]->m_Sex << "\t"
			<< this->m_ConArray[i]->m_Age << "\t"
			<< this->m_ConArray[i]->m_Phone << "\t"
			<< this->m_ConArray[i]->m_Addr << endl;
	}
	ofs.close();
}

//显示联系人
void AddressBook::ShowPerson()
{
	if (this->m_FileIsEmpty)
	{
		cout << "通讯录为空，请添加第一个联系人！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_ConNum; i++)
		{
			this->m_ConArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

//删除联系人
void AddressBook::DelPerson()
{
	if (this->m_FileIsEmpty)
	{
		cout << "通讯录为空，请添加第一个联系人！" << endl;
	}
	else
	{
		cout << "请输入要删除的联系人" << endl;
		string name;
		cin >> name;
		int ret = IsExist(name);
		if (ret != -1)
		{
			for (int i = ret; i < this->m_ConNum; i++)
			{
				this->m_ConArray[i] = this->m_ConArray[i + 1];
			}
			this->m_ConNum--;
			this->SaveCon();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "未找到该联系人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//存在性判断
int AddressBook::IsExist(string name)
{
	for (int i = 0; i < this->m_ConNum; i++)
	{
		if (this->m_ConArray[i]->m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//修改联系人
void AddressBook::ModPerson()
{
	if (this->m_FileIsEmpty)
	{
		cout << "通讯录为空，请添加第一个联系人！" << endl;
	}
	else
	{
		cout << "请输入您要修改的联系人" << endl;
		string name;
		cin >> name;
		int ret = IsExist(name);
		if (ret != -1)
		{
			delete this->m_ConArray[ret];
			cout << "查找到联系人：" << name << endl;
			cout << "请输入修改后的信息" << endl;

			string newName;
			cout << "请输入联系人姓名：" << endl;
			cin >> newName;

			int newSex;
			while (true)
			{
				cout << "请输入联系人性别： " << endl;
				cout << "1 ---------- 男" << endl;
				cout << "2 ---------- 女" << endl;
				if (!(cin >> newSex))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入有误，请重新输入!" << endl;
					continue;
				}
				else if (newSex != 1 && newSex != 2)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入有误，请重新输入!" << endl;
					continue;
				}
				else
					break;
			}
			int newAge;
			while (true)
			{
				cout << "请输入联系人年龄： " << endl;
				if (!(cin >> newAge))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入有误，请重新输入！" << endl;
					continue;
				}
				else if (newAge <= 0 || newAge >= 200)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "年龄有误，请重新输入！" << endl;
					continue;
				}
				else
					break;
			}

			string newPhone;
			cout << "请输入联系人电话： " << endl;
			cin >> newPhone;

			string newAddr;
			cout << "请输入联系人住址： " << endl;
			cin >> newAddr;

			Contacts* con = NULL;
			con = new Contacts(newName, newSex, newAge, newPhone, newAddr);
			this->m_ConArray[ret] = con;

			this->SaveCon();
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "未找到该联系人" << endl;
		}
	}

	system("pause");
	system("cls");
}

//查找联系人
void AddressBook::FindPerson()
{
	if (this->m_FileIsEmpty)
	{
		cout << "通讯录为空，请添加第一位联系人！" << endl;
	}
	else
	{
		cout << "请输入要查找的联系人姓名： " << endl;
		string name;
		cin >> name;
		int ret = IsExist(name);
		if (ret != -1)
		{
			cout << "查找到联系人 " << name << " 的信息" << endl;
			this->m_ConArray[ret]->ShowInfo();
		}
		else
		{
			cout << "未找到此联系人信息" << endl;
		}
	}

	system("pause");
	system("cls");
}

//清空通讯录
void AddressBook::CleanFile()
{
	cout << "************ 确认清空通讯录？ ************" << endl;
	cout << "此操作将导致通讯录文件清空，且数据无法恢复" << endl;
	cout << "************ 1-----------确认 ************" << endl;
	cout << "************ 2-----------取消 ************" << endl;

	int select = 0;
	while (true)
	{
		if (!(cin >> select))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "请输入正确的选项！" << endl;
			continue;
		}
		else if (select != 1 && select != 2)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "请输入正确的选项！" << endl;
			continue;
		}
		else
			break;
	}
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);		//删除文件后重新创建
		ofs.close();

		if (this->m_ConArray != NULL)
		{
			for (int i = 0; i < this->m_ConNum; i++)
			{
				if (this->m_ConArray[i] != NULL)
				{
					delete this->m_ConArray[i];
				}
			}
			delete[] this->m_ConArray;
			this->m_ConArray = NULL;
			this->m_ConNum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "清空通讯录成功！" << endl;
	}

	system("pause");
	system("cls");
}