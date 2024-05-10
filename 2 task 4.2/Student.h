#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Student
{
	string name;
	int age;
	int course;
	string gender;
	double grade;

public:
	~Student();
	Student();
	Student(const string&, int, int, const string&, double);
	Student(const Student&);
	Student(Student&&);
	void output_student();
	string get_name() const;
	int get_age() const;
	int get_course() const;
	string get_gender() const;
	int get_grade() const;
	void delete_student();
	void enter_from_keyboard();
	void get_from_file(const string&, ifstream&);
	void save_in_file(const string&, ofstream&);
	void output();
};