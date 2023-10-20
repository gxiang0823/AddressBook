#include"AddressBook.h"

//���캯��
AddressBook::AddressBook()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "ͨѶ¼δ����!" << endl;
		//��ʼ������
		this->m_ConNum = 0;
		this->m_ConArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ���Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		//��ʼ������
		this->m_ConNum = 0;
		this->m_ConArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ��Ҳ�Ϊ��
	int connum = this->Get_ConNum();
	cout << "��ϵ������Ϊ�� " << connum << endl;
	this->m_ConNum = connum;
	this->m_ConArray = new Contacts * [this->m_ConNum];
	this->Init_Con();

}

//չʾ�˵�
void AddressBook::ShowMenu()
{
	cout << "**********************************" << endl;
	cout << "**********ͨѶ¼����ϵͳ**********" << endl;
	cout << "********** 0���˳�ͨѶ¼ *********" << endl;
	cout << "********** 1�������ϵ�� *********" << endl;
	cout << "********** 2����ʾ��ϵ�� *********" << endl;
	cout << "********** 3��ɾ����ϵ�� *********" << endl;
	cout << "********** 4���޸���ϵ�� *********" << endl;
	cout << "********** 5��������ϵ�� *********" << endl;
	cout << "********** 6�����ͨѶ¼ *********" << endl;
	cout << "**********************************" << endl;
}

//�˳�ϵͳ
void AddressBook::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//�����ϵ��
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

	//�������
	string name;
	int sex;
	int age;
	string phone;
	string addr;

	cout << "��������ϵ�������� " << endl;
	cin >> name;

	while (true)
	{
		cout << "��������ϵ���Ա� " << endl;
		cout << "1 ---------- ��" << endl;
		cout << "2 ---------- Ů" << endl;
		if (!(cin >> sex))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������������������!" << endl;
			continue;
		}
		else if (sex != 1 && sex != 2)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������������������!" << endl;
			continue;
		}
		else
			break;
	}

	while (true)
	{
		cout << "��������ϵ�����䣺 " << endl;
		if (!(cin >> age))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������������������!" << endl;
			continue;
		}
		else if (age<=0||age>200)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���䲻��ȷ������������"<< endl;
			continue;
		}
		else
			break;
	}

	cout << "��������ϵ��ʽ�� " << endl;
	cin >> phone;

	cout << "��������ϵ�˵�ַ�� " << endl;
	cin >> addr;

	Contacts* con = NULL;
	con = new Contacts(name, sex, age, phone, addr);
	newSpace[this->m_ConNum] = con;

	//�ͷ�ԭ�пռ�
	delete[] this->m_ConArray;
	this->m_ConArray = newSpace;
	this->m_ConNum = newSize;
	this->m_FileIsEmpty = false;

	cout << "�����ϵ�˳ɹ���" << endl;
	this->SaveCon();

	system("pause");
	system("cls");
}

//ͳ������
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

//��������
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

//�洢�ļ�
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

//��ʾ��ϵ��
void AddressBook::ShowPerson()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ͨѶ¼Ϊ�գ�����ӵ�һ����ϵ�ˣ�" << endl;
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

//ɾ����ϵ��
void AddressBook::DelPerson()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ͨѶ¼Ϊ�գ�����ӵ�һ����ϵ�ˣ�" << endl;
	}
	else
	{
		cout << "������Ҫɾ������ϵ��" << endl;
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
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "δ�ҵ�����ϵ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�������ж�
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

//�޸���ϵ��
void AddressBook::ModPerson()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ͨѶ¼Ϊ�գ�����ӵ�һ����ϵ�ˣ�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
		string name;
		cin >> name;
		int ret = IsExist(name);
		if (ret != -1)
		{
			delete this->m_ConArray[ret];
			cout << "���ҵ���ϵ�ˣ�" << name << endl;
			cout << "�������޸ĺ����Ϣ" << endl;

			string newName;
			cout << "��������ϵ��������" << endl;
			cin >> newName;

			int newSex;
			while (true)
			{
				cout << "��������ϵ���Ա� " << endl;
				cout << "1 ---------- ��" << endl;
				cout << "2 ---------- Ů" << endl;
				if (!(cin >> newSex))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "������������������!" << endl;
					continue;
				}
				else if (newSex != 1 && newSex != 2)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "������������������!" << endl;
					continue;
				}
				else
					break;
			}
			int newAge;
			while (true)
			{
				cout << "��������ϵ�����䣺 " << endl;
				if (!(cin >> newAge))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�����������������룡" << endl;
					continue;
				}
				else if (newAge <= 0 || newAge >= 200)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�����������������룡" << endl;
					continue;
				}
				else
					break;
			}

			string newPhone;
			cout << "��������ϵ�˵绰�� " << endl;
			cin >> newPhone;

			string newAddr;
			cout << "��������ϵ��סַ�� " << endl;
			cin >> newAddr;

			Contacts* con = NULL;
			con = new Contacts(newName, newSex, newAge, newPhone, newAddr);
			this->m_ConArray[ret] = con;

			this->SaveCon();
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "δ�ҵ�����ϵ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

//������ϵ��
void AddressBook::FindPerson()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ͨѶ¼Ϊ�գ�����ӵ�һλ��ϵ�ˣ�" << endl;
	}
	else
	{
		cout << "������Ҫ���ҵ���ϵ�������� " << endl;
		string name;
		cin >> name;
		int ret = IsExist(name);
		if (ret != -1)
		{
			cout << "���ҵ���ϵ�� " << name << " ����Ϣ" << endl;
			this->m_ConArray[ret]->ShowInfo();
		}
		else
		{
			cout << "δ�ҵ�����ϵ����Ϣ" << endl;
		}
	}

	system("pause");
	system("cls");
}

//���ͨѶ¼
void AddressBook::CleanFile()
{
	cout << "************ ȷ�����ͨѶ¼�� ************" << endl;
	cout << "�˲���������ͨѶ¼�ļ���գ��������޷��ָ�" << endl;
	cout << "************ 1-----------ȷ�� ************" << endl;
	cout << "************ 2-----------ȡ�� ************" << endl;

	int select = 0;
	while (true)
	{
		if (!(cin >> select))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "��������ȷ��ѡ�" << endl;
			continue;
		}
		else if (select != 1 && select != 2)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "��������ȷ��ѡ�" << endl;
			continue;
		}
		else
			break;
	}
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);		//ɾ���ļ������´���
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

		cout << "���ͨѶ¼�ɹ���" << endl;
	}

	system("pause");
	system("cls");
}