#include "Human.h"

Human::Human(string name, int age, string sex)
{
	this->name = name;
	this->age = age;
	this->sex = sex;
}

void Human::setName(string name)
{
	this->name = name;
}

void Human::setAge(int age)
{
	if (age < 0)
		cout << "Неправильный возраст\n";
	else
		this->age = age;
}

void Human::setSex(string sex)
{
	this->sex = sex;
}

void Human::info() const
{
	cout << "Имя: " << name << "\nВозвраст: " << age << "\nПол: " << sex << endl;
}

string Human::getStringFileInfo() const
{
	char d = ';';
	string res = typeid(*this).name();
	res = res.substr(6) + d;
	res += getName() += d;
	res += to_string(getAge()) += d;
	res += getSex() + d;
	return res;
}

void Human::readStringInfo(string & str)
{
	string info[3];
	for (size_t i = 0; i < 3; i++)
	{
		info[i] = str.substr(0, str.find(';'));
		str = str.substr(str.find(';') + 1);
	}
	this->setName(info[0]);
	this->setAge(stoi(info[1]));
	this->setSex(info[2]);
}
