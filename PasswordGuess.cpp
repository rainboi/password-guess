#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

void slowPrint(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
		usleep(27000);
	}
}

int main()
{

	string victim_DB[5] = {"James Hummels", "Mark Rocklinder", "Bob Pearls", "Jenna Matkins", "John Dimberry"};
	string birth_date_DB[5] = {"10/06/1995", "23/12/1997", "05/11/1991", "01/07/1981", "23/09/1983"};
	string info_DB[5] = {"Has a dog named Max", "Favorite band Queen", "Favorite number 47", "Has a doughter, Mary", "John is Dumb"};
	string password_DB[5] = {"10Max1995", "MarkQueen", "47Pearls", "Matkins01", "john1983"};
	int score = 0;
	for (int i = 0; i < 5; i++)
	{
		bool correct;
		int tries = 5;
		string password;
		slowPrint(
			"Victim: " + victim_DB[i] + "\nBirth Date: " + birth_date_DB[i] + "\nInfo: " + info_DB[i] + "\nPassword Length: " + to_string(password_DB[i].size()) + "\n\n");

		do
		{
			correct = true;
			slowPrint("You have " + to_string(tries) + " tries to guess the password\n" + "Password: ");
			cin >> password;
			slowPrint("Output: ");
			for (int j = 0; j < password_DB[i].size(); j++)
			{
				if (password[j] == password_DB[i].at(j))
					cout << password_DB[i].at(j);
				else
				{
					slowPrint("*");
					correct = false;
				}
			}
			cout << endl;
			if (correct)
			{
				score += tries;
				slowPrint("Well Done! ");
				system("pause");
				system("CLS");
			}
			else if (--tries == 0)
			{
				cout << "Ahhh, you failed, you scored " << score << " good luck next time. ";
				system("pause");
				return 0;
			}
		} while (!correct);
	}
	cout << "Good Job Mate, You Scored " << score << " And Beat The Game! ";
	system("pause");
	return 0;
}