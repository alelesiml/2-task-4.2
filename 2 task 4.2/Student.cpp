#include "Student.h"

using namespace std;

Student::Student()
{
	name = "";
	age = 0;
	course = 0;
	gender = "";
	grade = 0;
}

Student::Student(const string& name, int age, int course,const string& gender, double grade)
{
	this->name = name;
	this->age = age;
	this->course = course;
	this->gender = gender;
	this->grade = grade;
}

Student::Student(const Student& other_student)
{
	name = other_student.get_name();
	age = other_student.get_age();
	course = other_student.get_course();
	gender = other_student.get_gender();
	grade = other_student.get_grade();
}

Student::Student(Student&& other_student)
{
	name = other_student.get_name();
	age = other_student.get_age();
	course = other_student.get_course();
	gender = other_student.get_gender();
	grade = other_student.get_grade();
	other_student.delete_student();
}

void Student::output_student()
{
	for (int i = 0; i < name.size(); ++i)
	{
		cout << name[i];
	}

	cout<<" " << age << " " << course;

	for (int i = 0; i < gender.size(); ++i)
	{
		cout << gender[i];
	}

	cout << " " << grade << endl;
}

Student::~Student() {}

string Student::get_name() const
{
	return name;
}

int Student::get_age() const
{
	return age;
}

int Student::get_course() const
{
	return course;
}

string Student::get_gender() const
{
	return gender;
}

int Student::get_grade() const
{
	return grade;
}

void Student::delete_student()
{
	name = "";
	age = 0;
	course = 0;
	gender = "";
	grade = 0;
}

void Student::enter_from_keyboard()
{
	cout << "������� ���: ";
	cin >> name;

	cout << "������� �������: ";
	cin >> age;

	cout << "������� ����: ";
	cin >> course;

	cout << "������� ������: ";
	cin >> gender;

	cout << "������� ������������: ";
	cin >> grade;
}

void Student::save_in_file(const string& filename, ofstream &file)
{
	if (file.is_open())
	{
		file.write(reinterpret_cast<char*>(this), sizeof(*this));
		
	}
	else 
	{
		cout << "������ �������� �����" << endl;
	}
}

void Student::get_from_file(const string& filename, ifstream &file)
{
	if (file.is_open())
	{
		file.read(reinterpret_cast<char*>(this), sizeof(*this));

	}
	else 
	{
		cout << "������ �������� �����" << endl;
	}
}
//2 asd 2 3 asd 5 qwe 4 4 ewq 7
void Student::output()
{
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "����: " << course << endl;
	cout << "������: " << gender << endl;
	cout << "������������: " << grade << endl;
}
