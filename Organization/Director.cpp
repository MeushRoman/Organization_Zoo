#include "Director.h"

Director::Director(string name, int age, string sex, int workYears)
	:Employee(name, age, sex, workYears)
{
}


double Director::getSalary() const
{
	double coef = 2;
	return coef;
}

string Director::getStringFileInfo() const
{
	string res = Employee::getStringFileInfo();
	
	return res;
}

void Director::readStringInfo(string & res)
{
	Employee::readStringInfo(res);
}
