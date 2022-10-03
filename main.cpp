#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

struct StudentData {
	int studentID;
	string firstName;
	string lastName;
	int homework;
	int test;
	int total;
	char grade;
};

const int SIZE = 4;

void addHomeTest(StudentData& st, int homeTest) {
	if ((st.homework == 0 || st.test == 0) && homeTest >= 0 && homeTest <= 50) {
		int ans;
		cout << "You want to add homework or test? (0 for homework & 1 for test)\n";
		cin >> ans;
		if (ans == 0)
			st.homework = homeTest;
		else if (ans == 1)
			st.test = homeTest;
		else
			cout << "You entered the wrong parameter";
	}
	else
		cout << "Homework or Test already exist";
}

void editHomeTest(StudentData& st, int homeTest) {
	if ((st.homework != 0 || st.test != 0) && homeTest >= 0 && homeTest <= 50) {
		int ans;
		cout << "You want to change homework or test? (0 for homework & 1 for test)\n";
		cin >> ans;
		if (ans == 0)
			st.homework = homeTest;
		else if (ans == 1)
			st.test = homeTest;
		else
			cout << "You entered the wrong parameter";
	}
	else
		cout << "Homework or Test doesn't exist";
}

void deleteHomeTest(StudentData& st) {
	if (st.homework != 0 || st.test != 0) {
		int ans;
		cout << "You want to change homework or test? (0 for homework & 1 for test)\n";
		cin >> ans;
		if (ans == 0)
			st.homework = 0;
		else if (ans == 1)
			st.test = 0;
		else
			cout << "You entered the wrong parameter";
	}
	else
		cout << "Homework or Test doesn't exist";
}

void setTotal(StudentData st[]) {
	for (int i = 0; i < SIZE; i++) {
		if (st[i].studentID != NULL) {
			st[i].total = st[i].homework + st[i].test;
		}
	}
}
/**
* Pre-condition:
* Post-condition:
*/
void setGrade(StudentData st[]) {
	for (int i = 0; i < SIZE; i++) {
		if (st[i].studentID != NULL) {
			if (st[i].total >= 90)
				st[i].grade = 'A';
			else if (st[i].total >= 80)
				st[i].grade = 'B';
			else if (st[i].total >= 70)
				st[i].grade = 'C';
			else if (st[i].total >= 60)
				st[i].grade = 'D';
			else
				st[i].grade = 'F';
		}
	}
}

void printStudentData(StudentData st[]) {
	for (int i = 0; i < SIZE; i++) {
		if (st[i].studentID != NULL) {
			cout << "Name of Student: " << st[i].firstName << " " << st[i].lastName << endl;
			cout << "Grade earned: " << st[i].grade << endl;
			cout << endl;
		}
	}
}

int main() {

	StudentData st[SIZE];
	double whole = 0.0;

	for (int i = 0; i < SIZE; i++) {
		cout << "Enter Student ID: ";
		cin >> st[i].studentID;

		cout << "Enter Student Name: ";
		cin >> st[i].firstName;
		cin >> st[i].lastName;

		cout << "Homework Marks: ";
		cin >> st[i].homework;

		cout << "Test Marks: ";
		cin >> st[i].test;

		cout << endl;
	}

	cout << endl;
	setTotal(st);
	setGrade(st);
	printStudentData(st);

	int id, editMarks;
	cout << "Enter id of student you want to change the marks: ";
	cin >> id;
	cout << "Enter marks you want to change: ";
	cin >> editMarks;
	for (int i = 0; i < SIZE; i++) {
		if (st[i].studentID == id) {
			editHomeTest(st[i], editMarks);
			break;
		}
	}

	cout << "\nEnter id of student you want to delete: ";
	cin >> id;
	for (int i = 0; i < SIZE; i++) {
		if (st[i].studentID == id) {
			deleteHomeTest(st[i]);
			break;
		}
	}

	int addMarks;
	cout << "\nEnter Student ID you want to add marks: ";
	cin >> id;
	cout << "Enter marks you want to change: ";
	cin >> addMarks;
	for (int i = 0; i < SIZE; i++) {
		if (st[i].studentID == id) {
			addHomeTest(st[i], addMarks);
			break;
		}
	}

	setTotal(st);
	setGrade(st);
	printStudentData(st);

	for (int i = 0; i < SIZE; i++) {
		if (st[i].studentID != NULL) {
			whole = whole + st[i].total;
		}
	}
	whole = whole / SIZE;

	ofstream out;
	out.open("Results.txt");

	try {
		for (int i = 0; i < SIZE; ++i) {
			out << "Name of Student: " << st[i].firstName << " " << st[i].lastName << endl;
			out << "Grade earned: " << st[i].grade << " (" << st[i].total << "%)" << endl;
			out << "Whole class percentage: " << whole << endl;
			out << endl;
		}
	}
	catch (...) {
		cout << "Error: file could not be opened\n";
	}

	out.close();

	system("PAUSE");
	return 0;
}
