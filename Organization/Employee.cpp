#include "Employee.h"

int Employee::idSeq = 0;

Employee::Employee(string name, int age, string sex, int workYears)
	:Human(name, age, sex)
{
	this->id = ++idSeq;
	this->workYears = workYears;
}

void Employee::setWorkYears(int workYears)
{
	this->workYears = workYears;
}

void Employee::info() const
{
	cout << "Должность: " << (string(typeid(*this).name()).substr(6)) << endl;
	Human::info();
	cout << "Опыт работы: " << workYears << endl;
}

string Employee::getStringFileInfo() const
{
	string res = Human::getStringFileInfo();
	res += to_string(getWorkYears());
	res += ';';
	return res;
}

void Employee::readStringInfo(string & res)
{
	Human::readStringInfo(res);
	//workYears = stoi(res);
	workYears = stoi(res.substr(0, res.find(';')));
}
