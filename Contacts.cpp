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
	cout << "姓名： " << this->m_Name
		<< "\t性别： " << ((this->m_Sex==1)?"男":"女")
		<< "\t年龄： " << this->m_Age
		<< "\t电话： " << this->m_Phone
		<< "\t住址： " << this->m_Addr << endl;
}