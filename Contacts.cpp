#include"Contacts.h"
Contacts::Contacts(string name, int sex, int age, string phone, string addr)
{
	this->m_Name = name;
	this->m_Sex = sex;
	this->m_Age = age;
	this->m_Phone = phone;
	this->m_Addr = addr;
}

void Contacts::ShowInfo()
{
	cout << "������ " << this->m_Name
		<< "\t�Ա� " << ((this->m_Sex==1)?"��":"Ů")
		<< "\t���䣺 " << this->m_Age
		<< "\t�绰�� " << this->m_Phone
		<< "\tסַ�� " << this->m_Addr << endl;
}