

#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Employee {
private:
	string EmpName;
	int EmpId;
	float Hours,Salary;
public:
	Employee(string nam, int id, float hours,float sal):EmpName(nam),EmpId(id),Hours(hours),Salary(sal)
	{



	}
	string GetName()
	{

		return EmpName;

	}
	int GetId()
	{

		return EmpId;
	}
	float GetHours() {


		return Hours;
	}
	float CalcSal() {
		return Salary*Hours; 

	}




};


class EmpManage {
private:  
	vector<Employee>Emps;
public:
	void AddEmp()
	{
		string nam;
		int id;
		float hours, sal;
		cout << "\t\tEnter Employee Name: ";
		cin.ignore();
		getline(cin, nam);
		cout << "\t\tEnter Employee ID: ";
		cin >> id;
		if (!Check(id)) return;
		cout << "\t\tEnter Employee Hours: ";
		cin >> hours;
		cout << "\t\tEnter Employee Salary Per Hour: ";
		cin >> sal;
		Emps.push_back(Employee(nam, id, hours,sal));
		cout << "\t\tEmployee Added Successfully...\n";


	}
	void ShowAll() {
		if (Emps.empty())
		{
			cout << "\t\tNo Employee Added...\n";
		}
		else {
			for (int i = 0; i < Emps.size(); i++)
			{
				cout << "\t\tName: " << Emps[i].GetName() << " |ID: " << Emps[i].GetId() << " |Hours: " << Emps[i].GetHours() << " |Salary: " << Emps[i].CalcSal() << "\n";
				cout << "\t\t-----------------------------------------------\n";

			}
		}

	}
	void DeleteEmp()
	{
		int id;
		bool found = false;
		cout << "\t\tEnter ID to Remove Employee: ";
		cin >> id;
		
		for (int i = 0; i < Emps.size(); i++)
		{
			if (Emps[i].GetId() == id)
			{
				Emps.erase(Emps.begin() + i);
				cout << "\t\tEmployee Removed Successfully...\n";
				found = true;
			}



		}
		if (!found)
		{
			cout << "\t\tEmployee Not Found...\n";
		}




	}
	bool Check(int id) {
		for (auto& emp : Emps) {
			if (emp.GetId() == id) {
				cout << "\t\tInvalid ID (already exists)...\n";
				return false;
			}
		}
		return true;
	}
	void SearchEmp()
	{

		int id;
		bool found = false;
		cout << "\t\tEnter ID to Search Employee: ";
		cin >> id;

		for (int i = 0; i < Emps.size(); i++)
		{
			if (Emps[i].GetId() == id)
			{
				
				cout << "\t\tEmployee Found Successfully...\n";
				cout << "\t\tName: " << Emps[i].GetName() << " |ID: " << Emps[i].GetId() << " |Hours: " << Emps[i].GetHours() << " |Salary: " << Emps[i].CalcSal() << "\n";

				found = true;
			}



		}
		if (!found)
		{
			cout << "\t\tEmployee Not Found...\n";
		}





	}

};


void Menu()
{
	cout << "\t\t------Employee Management System------\n";
	cout << "\t\t1. Add New Employee\n";
	cout << "\t\t2. Show All Employees\n";
	cout << "\t\t3. Delete Employee\n";
	cout << "\t\t4. Get Employee Data By Id\n";
	cout << "\t\t5. Exit\n";
	cout << "\t\t-----------------------------------------\n";


}
int main()
{
	EmpManage emps;
	
	int choice;
	char op;
	do {
		system("cls");
       	Menu();
	
	cout << "\t\tEnter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1: {
		emps.AddEmp();
		break;

	}
	case 2: {
		emps.ShowAll();
		break;


	}
	case 3: {
		emps.DeleteEmp();
		break;

	}
	case 4: {
		emps.SearchEmp();
		break;
	}
	case 5:
	{
		exit(1);
	
	}
	default:
		cout << "\t\tInvaild Choice...!\n";


	}
	cout << "\t\tDo You Want to Continue [Yes/No] ? :";

	cin >>op;

	} while (op == 'y' || op== 'Y');

	
	
	
	
	

	return 0;
}

