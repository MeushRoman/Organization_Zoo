#include "OrganizationConsole.h"
#include<iomanip>
OrganizationConsole::OrganizationConsole()
	:org("", 0)
{
	//startMenu();
}
void OrganizationConsole::start()
{
	mainMenu();
}
void OrganizationConsole::startMenu()
{
	system("cls");
	cout << "Welcome!";
	Sleep(2000);
	this->setOrgNameMenu();
	this->setSalaryMenu();
}
void OrganizationConsole::mainMenu()
{
	int choise = 0;
	while (choise != 5)
	{
		system("cls");
		cout << "Название организации: " << org.getName();
		cout << "\nЗарплата: " << org.getBaseSalary();
		cout << "\nКоличество сотрудников: " << org.getCountOfEmployee();
		cout << "\n\n----------------------------\n\n";
		cout << "\
		1. Добавить нового сотрудника\n\
		2. Удалить сотрудника\n\
		3. Информация по организации\n\
        4. Информация по сотрудникам\n\
		5. Выход\n"
			;
		cin >> choise;
		switch (choise)
		{

		case 1:
			addEmpMenu();
			break;
		case 2:
			removeEmpMenu();
			break;
		case 3:
			showInfo();
			pause();
			break;
		case 4:
			setEmpInfoMenu();
			pause();
			break;
		case 5:
			break;
		default:
			cout << "Неизвестная команда\nНажмити любую клавишу для продолжения\n";
			pause();
			system("cls");
			break;
		}
	}
	cout << "Досвидания\n";
}
void OrganizationConsole::addEmpMenu()
{
	size_t ch;
	while (1) {
		system("cls");
		cout << "Выберити должность\n";
		cout << "1. Садовод\n2. Смотритель\n3. Директор\n4. Менеджер\n5. Ветеринар\n6.Main menu";
		cin >> ch;
		if (ch > 6) {
			cout << "Неизвестная должность\n";
			pause();
		}
		else
			break;
	}
	if (ch == 6)
		return;
	string name;
	int age;
	string sex;
	int exp;
	system("cls");
	cout << "Введите имя сотрудника\n";
	cin >> name;
	cout << "Введите возвраст сотрудника\n";
	cin >> age;
	cout << "Введите пол сотрудника\n";
	cin >> sex;
	cout << "Введите опыт сотрудника\n";
	cin >> exp;
	Employee*emp = nullptr;
	switch (ch)
	{
	case 1:
		bool creativeSkills;
		cout << "Имеется ли творческий стиль? (1 - да, 0 - нет)\n";
		cin >> creativeSkills;
		emp = new Gardener(name, age, sex, exp, creativeSkills);
		break;
	case 2:
		bool attentiveness;
		cout << "Внимательность? (1 - да, 0 - нет)\n";
		cin >> attentiveness;
		
		emp = new Keeper(name, age, sex, exp, attentiveness);
		break;
	case 3:
		emp = new Director(name, age, sex, exp);
		break;
	case 4:
		bool edu1;
		bool communication;
		cout << "Наличие высшего образования? (1 - да, 0 - нет)\n" << endl;
		cin >> edu1;
		cout << "Коммуникативность? (1 - да, 0 - нет)\n" << endl;
		cin >> communication;
		emp = new Manager(name, age, sex, exp, edu1, communication);
		break;
	case 5:
		bool anesthesiology;
		bool surgery;
		bool ophthalmology;
		cout << "Обладает ли сотрудник следующими навыками: \n";
		cout << "анестезиологии? (1 - да, 0 - нет)\n" << endl;
		cin >> anesthesiology;
		cout << "анестезиологии? (1 - да, 0 - нет)\n" << endl;
		cin >> surgery;
		cout << "анестезиологии? (1 - да, 0 - нет)\n" << endl;
		cin >> ophthalmology;

		emp = new Veterinarian(name, age, sex, exp, anesthesiology, surgery, ophthalmology);
		break;
	}
	system("cls");
	org.addEmployee(emp);
	cout << "Сотрудник добавлен!\n";
	pause();
}
void OrganizationConsole::removeEmpMenu()
{
	while (1) {
		system("cls");
		cout << "Choose Id of employee to remove" << endl;
		showShortInfo();
		int ch;
		cin >> ch;
		if (!org.removeEmployeeById(ch)) {
			cout << "incorrect id!\n";
			system("pause");
			continue;
		}
		cout << "Employee dismissed!\n";
		system("pause");
		return;
	}
}
void OrganizationConsole::showInfo() const
{
	system("cls");
	org.getInfo();
}
void OrganizationConsole::setOrgNameMenu()
{
	system("cls");
	cout << "Set organization name\n";
	string name;
	cin >> name;
	org.setName(name);
}
void OrganizationConsole::setSalaryMenu()
{
	system("cls");
	cout << "Set salary\n";
	int sal;
	cin >> sal;
	org.setBaseSalary(sal);
}
void OrganizationConsole::setEmpInfoMenu()
{
	while (1)
	{
		clearScreen();
		showShortInfo();
		cout << "0- Go back";
		cout << "\nChoose employee\'s id: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Employee *e = org.getEmpById(ch);

		if (e == nullptr)
		{
			cout << "incorrectd id\n";
			pause();
			continue;
		}
		editEmpMenu(e);
	}
}
void OrganizationConsole::showShortInfo() const
{
	for (int i = 0; i < org.getCountOfEmployee(); i++)
	{
		cout << setw(3) << left << org[i].getId()
			<< setw(10) << left << string(typeid(org[i]).name()).substr(6)
			<< setw(10) << left << org[i].getName() << endl;
	}
}
void OrganizationConsole::editEmpMenu(Employee * emp)
{
	while (1)
	{
		clearScreen();
		cout << string(typeid(*emp).name()).substr(6) << endl;
		emp->info();
		cout << "1. Change employee info\n";
		cout << "2. Dismiss employee info\n";
		cout << "3. Change position\n";
		cout << "0. Back\n";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 0:
			return;
		case 1:
			editEmpInfo(emp);
			break;
		case 2:
			org.removeEmployeeById(emp->getId());
			cout << "Employee dissmised!" << endl;
			pause();
			return;
			break;
		case 3:
			changePosition(emp);
			return;
		default:
			cout << "Unknown command";
			break;
		}
	}
}
void OrganizationConsole::editEmpInfo(Employee * emp)
{
	/*while (1)
	{
		clearScreen();
		emp->info();
		int index = 0;
		cout << "\nChoose information to change\n";
		cout << ++index << ". Name\n";
		cout << ++index << ". Age\n";
		cout << ++index << ". Sex\n";
		cout << ++index << ". Experinece in years\n";
		int pos;
		if (typeid(*emp) == typeid(Gardener))
		{
			pos = 1;
			cout << ++index << ". Count of known languages\n";
			cout << ++index << ". Has education\n";
		}
		else if (typeid(*emp) == typeid(Keeper))
		{
			pos = 2;
			cout << ++index << ". 1C experience \n";
		}
		else if (typeid(*emp) == typeid(Manager))
		{
			pos = 3;
			cout << ++index << ". Education \n";
		}
		else if (typeid(*emp) == typeid(Veterinarian))
		{
			pos = 4;
			cout << ++index << ". Works in harmful conditions \n";
		}
		cout << "0. Go back\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "Неизвестная комманда!\n";
			pause();
			continue;
		}
		switch (ch)
		{
		case 0: return;
			break;
		case 1:
		{
			string name;
			cout << "\nВведите новое имя: ";
			cin >> name;
			emp->setName(name);
			break;
		}
		case 2:
		{
			int age;
			cout << "\nВведите возрас: ";
			cin >> age;
			emp->setAge(age);
			break;
		}
		case 3:
		{
			string sex;
			cout << "\nВведите пол: ";
			cin >> sex;
			emp->setSex(sex);
			break;
		}
		case 4:
		{
			int exp;
			cout << "\nВведите опыт работы: ";
			cin >> exp;
			emp->setWorkYears(exp);
			break;
		}
		default:
		{
			switch (pos)
			{
			case 1:
				if (ch == 5)
				{
					cout << "Enter new count of known languages\n";
					int cnt;
					cin >> cnt;
					((Gardener*)emp)->setCntLang(cnt);
				}
				else
				{
					cout << "Eductaion (1-yes, 0-no)";
					bool ed;
					cin >> ed;
					((Gardener*)emp)->setHasEdu(ed);
				}
				break;
			case 2:
				if (ch == 5)
				{
					cout << "Know 1C (1-yes, 0-no)";
					bool know1C;
					cin >> know1C;
					((Gardener*)emp)->setKnow1C(know1C);
				}
				break;
			case 3:
				if (ch == 5)
				{
					cout << "Education (1-yes, 0-no)";
					bool edu;
					cin >> edu;
					((Manager*)emp)->setHasEdu(edu);
				}
				break;
			case 4:
				if (ch == 5)
				{
					cout << "Harmful conditions (1-yes, 0-no)";
					bool harmC;
					cin >> harmC;
					((Janitor*)emp)->setConditions(harmC);
				}
				break;
			}
		}
		break;
		}
	}*/
	pause();
}
void OrganizationConsole::changePosition(Employee * emp)
{
	while (1)
	{
		clearScreen();
		cout << "Choose new position of " << emp->getPosition() << " " << emp->getName() << endl;
		cout << "1. Proger\n";
		cout << "2. Acounter\n";
		cout << "3. Janitor\n";
		cout << "4. Direcor\n";
		cout << "5. HR Manager\n";
		cout << "0. Go back\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch>5)
		{
			cout << "Unknown command\n";
			pause();
			continue;
		}
		Employee *e = nullptr;
		switch (ch)
		{
		case 1:
			e = new Gardener(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			break;
		case 2:
			e = new Keeper(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			break;
		case 3:
			e = new Veterinarian(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0,0,0);
			break;
		case 4:
			e = new Director(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears());
			break;
		case 5:
			e = new Manager(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0);
			break;
		}
		org.addEmployee(e);
		org.removeEmployeeById(emp->getId());
		return;
	}
}