#include "OrganizationConsole.h"

void main()
{
	setlocale(LC_ALL, "rus");
	OrganizationConsole e;
	e.org.addEmployee(new Gardener("Petya", 30, "male", 15, 1));
	e.org.addEmployee(new Keeper("Masha", 40, "female", 20, 1));
	e.org.addEmployee(new Director("Dinara", 35, "female", 15));
	e.org.addEmployee(new Manager("Tanya", 45, "female", 15, 1,1));
	e.org.addEmployee(new Veterinarian("Bobi", 30, "male", 20, 1,1,1));
	e.start();
	

	system("pause");
}