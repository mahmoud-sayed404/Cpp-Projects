#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Student {
private:
	int Id;
	string Name;
	string courseName;
	float gpa;

public:
	Student(int id, string name, string co, float ga) :Id(id), Name(name), courseName(co), gpa(ga)
	{

	}
	void SetName(string n) {

		Name = n;

	}
	void SetGap(float g) {

		gpa = g;

	}
	void SetId(int  id) {

		Id = id;

	}
	void SetCourse(string c) {

		courseName = c;

	}
	string GetName() {

		return Name;

	}

	int GetId() {

		return Id;

	}
	float GetGpa() {

		return gpa;

	}
	string GetCourse() {

		return courseName;

	}


	void to_string()
	{


		cout << "\t\ttID: " << "[" << Id << "], "
			<< "Name: " << "[" << Name << "],"
			<< "Course: " << "[" << courseName << "],"
			<< "GPA: " << "[" << gpa << "]. \n";



	}
};
void AddStd(vector<Student>& students) {


	int ID;
	string Nam;
	string courseNam;
	float gp;
	cout << "\t\tEnter Student Name: ";

	cin.ignore();
	getline(cin, Nam);



	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].GetName() == Nam)
		{
			cout << "\t\tStudent Already Exit\n";

		}


	}
	cout << "\t\tEnter ID: ";
	cin >> ID;
	cout << "\t\tEnter Course: ";
	cin >> courseNam;
	cout << "\t\tEnter Gpa: ";
	cin >> gp;
	Student Newstd(ID, Nam, courseNam, gp);
	students.push_back(Newstd);




}
void DisplayAllstd(vector<Student>students) {

	if (students.empty())
	{
		cout << "\t\t No Student Found " << endl;

		return;



	}
	else {
		for (int i = 0; i < students.size(); i++)
		{

			students[i].to_string();



		}


	}


}
void Searchstd(vector<Student>& students) {
	int ID;
	cout << "\t\tEnter ID: ";
	cin >> ID;
	for (int i = 0; i < students.size(); i++)
	{

		if (students[i].GetId() == ID)
		{
			cout << "\t\t--------Student Found ------------\n";
			students[i].to_string();
			return;


		}




	}
	cout << "\t\tStudent Not Found\n";





}















int main() {
	vector<Student>students;
	char choice;
	do {
		system("cls");
		int op;

		cout << "\t\t******Student Management System******\n";
		cout << "\t\t--------------------------------------\n";
		cout << "\t\t1. Add New Student\n";
		cout << "\t\t2. Show All Students\n";
		cout << "\t\t3. Get Student data by Id\n";
		cout << "\t\t4. Exit\n";
		cout << "\t\t--------------------------------------\n";
		cout << "\t\tEnter Your choice: ";
		cin >> op;
		switch (op)
		{
		case 1:
			AddStd(students);
			break;
		case 2:
			DisplayAllstd(students);
			break;
		case 3:
			Searchstd(students);
			break;
		case 4:
			exit(1);
		default:
			cout << "\t\tInvalid Number " << endl;






		}
		cout << "\t\tDo You Want to Continue [Yes/No] ? :";

		cin >> choice;

	} while (choice == 'Y' || choice == 'y');






}