#pragma once
#include "Employee.h"

class Director :
	public Employee
{
public:
	Director(string name, int age, string sex, int workYears);

	double getSalary()const override;

	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
};