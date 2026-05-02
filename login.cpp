/*1. Register User
2. Login User
3. Show User List
4. Search User
5. Delete User



Program Source Code
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class User {
private:
	string UserName, Password;
public:
	User(string name, string pass) :UserName(name), Password(pass)
	{


	}
	string GetUser()
	{
		return UserName;
     }
	string GetPass()
	{
		return Password;

	}

};
class ManageUser {
private:
	vector<User>users;
public:
	void Register()
	{
		string nam, pas;
		cout << "\t\tEnter User Name: ";
		cin.ignore();
		getline(cin, nam);

		cout << "\t\tEnter Password: ";
		cin.ignore();
		getline(cin, pas);

		User newuser(nam, pas);
		users.push_back(newuser);
		cout << "\t\tUser Register Sucessfully...\n";
	
	}
	bool Login(string n, string p)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].GetUser() == n&&users[i].GetPass()==p)
			{
				cout << "\t\tLogin Successfully...." << endl;
				return true;

			}


		}

		cout << "\t\tInvalid User Name or Password..." << endl;
		return false;

	}
	void Show()
	{
		cout << "\t\t---Users List---" << endl;
		for (int i = 0; i < users.size(); i++)
		{

			cout <<"\t\t" << users[i].GetUser() << "\n";

		}




	}
	void Search(string n)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].GetUser() == n)
			{
				cout << "\t\t User Found" << endl;

			}
		}

			

				cout << "\t\t User Not Found" << endl;

	



	}
	void Delete(string n)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].GetUser() == n)
			{
				users.erase(users.begin() + i);

				cout << "\t\tUser Remove Successfully...." << endl;
			}


		}

	}



};
int main() {
	ManageUser Use;
	int op;
	char choice;
	do {
	system("cls");
	cout << "\n\t\t1. Register User " << "\n";
	cout << "\t\t2. Login " << "\n";
	cout << "\t\t3. Show User List " << "\n";
	cout << "\t\t4. Search User " << "\n";
	cout << "\t\t5. Delete User " << "\n";
	cout << "\t\t6. Exit\n";
	cout << "\t\t Enter Your Choice: ";
	cin >> op;

		switch (op)
		{
		case 1:
		{
			Use.Register();
			break;


		}
		case 2:
		{
			string n, p;
			cout << "\t\tEnter User: ";
			cin.ignore();
			getline(cin,n);

			cout << "\t\tEnter password: ";
			cin.ignore();
			getline(cin, p);

			Use.Login(n, p);
			break;

		}

		case 3:
		{
			Use.Show();
			break;

		}
		case 4:
		{

			string n;
			cout << "\t\tEnter User Name: ";
			cin.ignore();
			getline(cin, n);

			Use.Search(n);
			break;

		}
		case 5:

		{
			string username;
			cout << "\t\tEnter User Name :";
			cin.ignore();
			getline(cin, username);

				Use.Delete(username);
			break;
		}

		case 6:
			exit(1);



		}
		cout << "\t\tDo You Want to Continue [Yes/ No] ? :";
		cin >> choice;


	} while (choice=='Y'||choice=='y');





	return 0;
}