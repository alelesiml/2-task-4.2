// 

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"

using namespace std;
void calculate_score(Student[], int, int);

int main()
{
	setlocale(LC_ALL, "ru");

	Student student_1("dcsj", 20, 2, "dcbms", 4);
	student_1.output_student();
	Student student_2(student_1);
	student_2.output_student();
	Student student_3(move(student_1));
	student_3.output_student();

	int num;
	cout << "Введите количество студентов: ";
	cin >> num;

	Student* students = new Student[num];

	for (int i = 0; i < num; i++)
	{
		cout << "Студент " << i + 1 << endl;
		students[i].enter_from_keyboard();
		cout << endl;
	}

	const string filename = "file.bin";

	ofstream file(filename, ios::binary);

	for (int i = 0; i < num; i++)
	{
		students[i].save_in_file(filename, file);
	}
	file.close();

	ifstream file1(filename, ios::binary);

	for (int i = 0; i < num; i++)
	{
		students[i].get_from_file(filename, file1);
	}
	file1.close();

	for (int i = 0; i < num; i++)
	{

		cout << "Студент " << i + 1 << endl;
		students[i].output();
		cout << endl;
	}

	int entered_course;
	cout << "Введите курс для определения среднего балла: ";
	cin >> entered_course;

	calculate_score(students, num, entered_course);
}


void calculate_score(Student students[], int num, int course)
{
	int q = 0;
	double score = 0;

	for (int i = 0; i < num; i++)
	{
		if (students[i].get_course() == course)
		{
			score += students[i].get_grade();
			q++;
		}
	}
	score = score / q;
	cout << "Average score: " << score << endl;
}
