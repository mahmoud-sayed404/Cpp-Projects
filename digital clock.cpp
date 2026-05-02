#include<iostream>
#include<iomanip>
#include<windows.h>
#include<stdlib.h>
using namespace std;
int main()
{
	system("color 4A");
	int hour, min, sec;
	cout << setw(70) << "*Enter Current time*\n";
	cout << "HH: ";
	cin >> hour;
	cout << "MM: ";
	cin >> min;
	cout << "SS: ";
	cin >> sec;
	system("color 4A");
	if (hour > 23)
	{
		cout << "Wrong Time input";
	}
	else if (min > 60)
	{
		cout << "Wrong Time input";
	}
	else if (sec > 60)
	{

		cout << "Wrong Time input";
	}

	else
	{
		while (1)
		{
			system("cls");
			for (hour; hour < 24; hour++)
			{

				for (min; min < 60; min++)
				{

					for (sec; sec < 60; sec++)
					{
						system("cls");
						cout << "\n\n\n\n~~~~~~~~~"
							"~~~~~~~~~~~~~~~~~~~~~"
							"~~~~~~~~~~~~~~~~~~"
							"Current Time = "
							<< hour << ":" << min << ":"
							<< sec
							<< "Hrs~~~~~~~~~~~~~~~~~~"
							"~~~~~~~~~~~~~~~~~~~~~"
							"~~~~~~~~~";
						Sleep(900);




					}
					sec = 0;




				}
				min = 0;



			}




		}



	}




	return 0;
}