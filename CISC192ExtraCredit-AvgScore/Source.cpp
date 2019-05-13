//This program will return the average score of the lowest and highest scores in a set of numbers given by the user

#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <ctime>
using namespace std;

bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}


int main()
{
	char choice = 'y';

	do
	{
		string scoreGiven;
		int score, avgScore;
		vector<int> scoreList = {};
		char play = 'y';
		

		do
		{
			//ask for the score
			std::cout << "What score would you like to enter? ";
			std::cin >> scoreGiven;
			std::cout << "\n";
			
			//check if entered line was int and display error message if not
			if (isNumber(scoreGiven) == false)
			{
				std::cout << "Incorrect format, entry must be a number 1-100.\n\n\n" << endl;
			}
			//if string contains only digits, convert to int
			else
			{
				score = std::stoi(scoreGiven);
				//check if int is an acceptable value
				if (score < 1 || score > 100)
				{
					std::cout << "Incorrect score, must be 1-100.\n\n\n";

				}
				else
				{
					//add score to vector
					scoreList.push_back(score);
					//see if the user wants to add another score
					if (scoreList.size() > 1)
					{
						std::cout << "Would you like to add another score? (Y/N): ";
						std::cin >> play;
						std::cout << "\n";
					}
				}
			}

		} while (play == 'y' || play == 'Y');

		
		//find the min and max elements of the vector
		auto min_iter = min_element(scoreList.begin(), scoreList.end());
		auto max_iter = max_element(scoreList.begin(), scoreList.end());

		//calculate the average of the min and max values and print it
		avgScore = (*min_iter + *max_iter) / 2;
		std::cout << "\nThe average of the highest and lowest score entered is: " << avgScore << endl;


		//see if the user wants to continue and continue if desired
		std::cout << "\n\nWould you like to check another set of scores? (Y/N): ";
		std::cin >> choice;
		std::cout << endl;

	} while (choice == 'y' || choice == 'Y');

	//display author of the program
	cout << "Programmed by Brent Kinney" << endl;
	cout << "Press [Enter] key to end..."; //prompt lets user know
	cin.ignore(256, '\n');
	cin.get();

	return 0;
}