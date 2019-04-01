#include "Address.h"
#include "Project.h"
#include "Employee.h"

Address::Address(char* house_Number, char* Street_Name, char * City, char* County)
{
	int a;
	a = strlen(house_Number);
	int b;
	b = strlen(Street_Name);
	int c;
	c = strlen(City);
	int d;
	d = strlen(County);

	this->house_Number = new char[a];
	strcpy(this->house_Number, house_Number);

	this->street_Name = new char[b];
	strcpy(this->street_Name, Street_Name);

	this->city = new char[c];
	strcpy(this->city, City);

	this->county = new char[d];
	strcpy(this->county, County);
}
\
Address::Address(const Address& x)
{
	int a;
	a = strlen(x.house_Number);
	int b;
	b = strlen(x.street_Name);
	int c;
	c = strlen(x.city);
	int d;
	d = strlen(x.county);

	this->house_Number = new char[a];
	strcpy(this->house_Number, x.house_Number);

	this->street_Name = new char[b];
	strcpy(this->street_Name, x.street_Name);

	this->city = new char[c];
	strcpy(this->city, x.city);

	this->county = new char[d];
	strcpy(this->county, x.county);
}


ostream& operator<<(ostream& osObject, const Address& a)
{
	osObject << "house_number:" << a.house_Number << endl;
	osObject << "street_Name:" << a.street_Name << endl;
	osObject << "city:" << a.city << endl;
	osObject << "country:" << a.county << endl;
	return osObject;
}

const Address& Address::operator = (const Address& dummy)
{
	if (this != &dummy)
	{

		int s = strlen(dummy.house_Number) + 1;
		if (this->house_Number != nullptr)
			delete[]this->house_Number;
		this->house_Number = new char[s];
		strcpy_s(this->house_Number, s, dummy.house_Number);

		s = strlen(dummy.street_Name) + 1;
		if (this->street_Name != nullptr)
			delete[]this->street_Name;
		this->street_Name = new char[s];
		strcpy_s(this->street_Name, s, dummy.street_Name);

		s = strlen(dummy.city) + 1;
		if (this->city != nullptr)
			delete[]this->city;
		this->city = new char[s];
		strcpy_s(this->city, s, dummy.city);

		s = strlen(dummy.county) + 1;
		if (this->county != nullptr)
			delete[]this->county;
		this->county = new char[s];
		strcpy_s(this->county, s, dummy.county);
	}
	return *this;
}

Address::~Address()
{
	if (this->house_Number != nullptr)
		delete[]this->house_Number;

	if (this->street_Name != nullptr)
		delete[]this->street_Name;

	if (this->city != nullptr)
		delete[]this->city;

	if (this->county != nullptr)
		delete[]this->county;
}

Project::Project(char* name, int budget, int duration)
{
	int a;
	a = strlen(name);
	this->name = new char[a];
	strcpy(this->name, name);
	this->budget = budget;
	this->duration = duration;
}

ostream& operator<<(ostream& osObject, const Project&a)
{
	osObject << "name:" << a.name << endl;
	osObject << "Budget:" << a.budget << endl;
	osObject << "duration:" << a.duration;

	return osObject;
}


Project::Project(const Project&a)
{
	this->name = a.name;
	this->budget = a.budget;
	this->duration = a.duration;

}


void Project::setBudget(int a)
{
	if (budget > 0)
		budget = a;
}

const Project& Project::operator = (const Project& dummy)
{
	if (this != &dummy)
	{
		int s = strlen(dummy.name) + 1;
		if (this->name != nullptr)
			delete[]this->name;
		this->name = new char[s];
		strcpy_s(this->name, s, dummy.name);

		this->budget = dummy.budget;
		this->duration = dummy.duration;
	}

	return *this;
}


Project::~Project()
{
	if (this->name != nullptr)
		delete[]this->name;
}

Employee::Employee(char *name, const Address& address)
{
	int s = strlen(name) + 1;
	this->emp_name = new char[s];
	strcpy_s(this->emp_name, s, name);

	this->address = &address;
	for (int i = 0; i < 2; i++)
		this->projects[i] = nullptr;
}


Employee::Employee(const Employee& dummy)
{
	this->address = dummy.address;

	int s = strlen(dummy.emp_name) + 1;
	this->emp_name = new char[s];
	strcpy_s(this->emp_name, s, dummy.emp_name);
	for (int i = 0; i < 3; i++)
		this->projects[i] = dummy.projects[i];
}

ostream& operator << (ostream& osobject, const Employee& dummy)
{
	osobject << "Employee Name: " << dummy.emp_name << endl;
	osobject << "Address: " << *dummy.address << ". His projects are follow: ";

	for (int i = 0; i < 2; i++)
	{
		if (dummy.projects[i] != nullptr)
			osobject << endl << *dummy.projects[i];
	}

	return osobject;
}

void Employee::addProject(Project const* ptr)
{
	for (int i = 0; i < 2; i++)
	{
		if (this->projects[i] == nullptr)
		{
			this->projects[i] = ptr;
			break;
		}
	}
}

void Employee::removeProject(Project const* ptr)
{
	for (int i = 0; i < 2; i++)
	{
		if (projects[i] == ptr)
			projects[i] = nullptr;
	}
}

Employee::~Employee()
{
	delete this->address;
	if (this->emp_name != nullptr)
		delete[]this->emp_name;
}