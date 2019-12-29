/*
Triple X
git user name: Triple3Apple
ABOUT: A short puzzle game that involves guessing 3 numbers (the code) given the sum and product
	   of the three numbers. There are a total of 5 levels that increase in difficulty. This
	   code features coding convention from Unreal Engine (practicing coding conventions)
	   Referenced a tutorial* for how to structure this game, but most of the code is implemented 
	   by me.

	   * https://www.udemy.com/course/unrealcourse/
*/

// preprocessor directives
#include <iostream>
#include <string>
#include <windows.h>   // WinApi header (ONLY FOR WINDOWS)
#include <ctime>

// NOTE: Unreal Engine Naming Convention: ParcelCase, e.g. int LoopIndex;

bool ValidateInput(std::string TempGuess);
void StartGame();
void ChangeCode();
void PrintIntroAndHints();
void PrintIntro();
bool StartRound();

int LevelDifficulty = 1;
const int MaxLevelDifficulty = 5;

int CodeA = (rand() % LevelDifficulty) + 1;		// NOTE: rand() % 5   gives us a range of values from 0 - 4
int CodeB = (rand() % LevelDifficulty) + 1;
int CodeC = (rand() % LevelDifficulty) + 1;

int CodeSum = CodeA + CodeB + CodeC;
int CodeProduct = CodeA * CodeB * CodeC;
int GuessSum;
int GuessProduct;

int GuessA, GuessB, GuessC;

// color changing text reference from: https://www.daniweb.com/programming/software-development/code/216345/add-a-little-color-to-your-console-text
HANDLE  hConsole;


int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));		// making rand() random [changing the seed of rand!]
	StartGame();
	return 0;
}

void StartGame()
{
	PrintIntro();
	bool bLevelPassed = true;
	

	while (LevelDifficulty <= MaxLevelDifficulty)
	{
		bLevelPassed = StartRound();

		// clearing input buffer (cin)
		std::cin.clear();
		std::cin.ignore();	// discards the buffer

		if (bLevelPassed)
		{
			// increase difficulty
			LevelDifficulty++;
			if (LevelDifficulty != MaxLevelDifficulty + 1)
			{
				std::cout << "\nDifficulty Increasing..\n";
				ChangeCode();
			}
		}
	}
}


void ChangeCode()
{
	CodeA = (rand() % LevelDifficulty) + LevelDifficulty;		// NOTE: rand() % 5   gives us a range of values from 0 - 4
	CodeB = (rand() % LevelDifficulty) + LevelDifficulty;
	if (LevelDifficulty == 2)
	{
		CodeB = (rand() % LevelDifficulty) + LevelDifficulty;
	}
	else
	{
		CodeC = (rand() % LevelDifficulty) + LevelDifficulty - 1;
	}

	CodeSum = CodeA + CodeB + CodeC;
	CodeProduct = CodeA * CodeB * CodeC;
}

void PrintIntroAndHints()
{
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\nYou are a secret agent breaking into a level [ " << LevelDifficulty << " ] secure server room...\n";
	std::cout << "You need a secret code to enter.\n";
	std::cout << "# There are 3 numbers in the code.\n";
	std::cout << "# The code adds up to: " << CodeSum << std::endl;
	std::cout << "# The code multiplies to : " << CodeProduct << "\n\n";
}

void PrintIntro()
{
	
	std::cout << " _______ _____   _____ _____  _      ______  __   __\n";
	std::cout << "|__   __|  __ \\ |_   _|  __ \\| |    |  ____| \\ \\ / / \n";
	std::cout << "   | |  | |__) |  | | | |__) | |    | |__     \\ V / \n";
	std::cout << "   | |  |  _  /   | | |  ___/| |    |  __|     > <  \n";
	std::cout << "   | |  | | \\ \\  _| |_| |    | |____| |____   / . \\ \n";
	std::cout << "   |_|  |_|  \\_\\|_____|_|    |______|______| /_/ \\_\\ \n\n";
	std::cout << "By: Triple3Apple\n";

	std::cout << "\n";
	std::cout << "       WNNXXXXNNNNNNXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXNWW\n";
	std::cout << "     WKkxdddddddddddddddddddddddddddddddddddooooooodkKW\n";
	std::cout << "     XxoooooooooooooooooooooooooolllllllllllllllllllldK\n";
	std::cout << "     KdoooooooooooooooooooooooooollllollllolllllllllldK\n";
	std::cout << "   WWKdoooooooooooooooooooooooooolllllllllloolllllllldK\n";
	std::cout << " N0kkxoooooooox00OxooooooooooooooollollloxO0OdllllllldK\n";
	std::cout << " XxoooooooooookXNWX0xooooooooooollloolox0XWNKxclllllldK\n";
	std::cout << " Xxoooooooooooox0XNWX0xoloooooooololox0XWWXOocccclllloK\n";
	std::cout << " Xxoooooooooooolox0XNWX0xxOO0000Okxx0XNNXOocccccccclldK\n";
	std::cout << " Xkoooooooooooooolox0XNWNNWWWWNWWNNNWNXOoc:cccloddlccoK\n";
	std::cout << "  XKKkdooooooooooooloONWWWWNXKKXNWWWWNkc:cccccd0K0xcco0\n";
	std::cout << "     KdooooooooooooodKNWWN0dlllld0NWWN0occccccx0KKxcco0\n";
	std::cout << "     KdoooooooooolookXWWWKo:cccccoKWWWXxccccccd0KKxcco0\n";
	std::cout << "     KdooooooooollllxXWNWXxccccclxXWWWKdccccccxKXKxcco0\n";
	std::cout << "   WW0dllllllllloolloONWWNX0kkkk0XNWWNklccccccxKXKxcco0\n";
	std::cout << " N0kkxoolllllllllllox0NWWWWWWWWWWWWWWN0dccccccok0Oocco0\n";
	std::cout << " Xxllllllllllllllox0XWNX0OKXXNNXXKO0XNNXOdlcccclllccco0\n";
	std::cout << " Xxllllllllllllox0XNNXOocclooooollccoOXNNXOdlcccccccco0\n";
	std::cout << " Xxllllllllllld0XWNXOocccccccccccccccldOXNNXOocccllllo0\n";
	std::cout << " XxooolllllllokXNXOocccccccccccccccccccldOXNXxcccllllo0\n";
	std::cout << "  XKKkollllllloddoccccccccccccccccccccccclodolcclllllo0\n";
	std::cout << "     KdlllllllllllccccccccccccccccccccccccccccllllllloK\n";
	std::cout << "     Kdlllllllllllllcccccccccccccccccccccllllllllllllo0\n";
	std::cout << "     XxollllllllllllllcccccccccccccccllllllllllllllllxX\n";
	std::cout << "      WN0OkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkO0\n";
}

bool StartRound()
{
	PrintIntroAndHints();

	std::string TempA, TempB, TempC;
	bool bIsPlayerCorrect;					// NOTE: For unreal engine, "b" needs to be in front of a boolean name!

	GuessSum = 0;
	GuessProduct = 0;

	std::cout << "Enter the first number of the secret code to continue...\n";
	std::cin >> TempA;

	// loops until player enters a integer
	while (!ValidateInput(TempA))
	{
		std::cout << TempA << " <-- is not a valid input, please enter a integer\n";
		std::cin >> TempA;
	}

	std::cout << "\nEnter the second number of the secret code to continue...\n";
	std::cin >> TempB;

	// loops until player enters a integer
	while (!ValidateInput(TempB))
	{
		std::cout << TempB << " <-- is not a valid input, please enter a integer\n";
		std::cin >> TempB;
	}

	std::cout << "\nEnter the third number of the secret code to continue...\n";
	std::cin >> TempC;

	// loops until player enters a integer
	while (!ValidateInput(TempC))
	{
		std::cout << TempC << " <-- is not a valid input, please enter a integer\n";
		std::cin >> TempC;
	}


	// converting the strings to integer values
	GuessA = std::stoi(TempA);
	GuessB = std::stoi(TempB);
	GuessC = std::stoi(TempC);

	GuessSum = GuessA + GuessB + GuessC;
	GuessProduct = GuessA * GuessB * GuessC;

	std::cout << "\n-----------------------------------------------------\n";
	// Check if player's code is correct
	if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
	{
		SetConsoleTextAttribute(hConsole, 10);
		if (LevelDifficulty == MaxLevelDifficulty)
		{
			std::cout << "\nYou WIN! You have retrieved all the files! Now get out of there agent!\n";
		}
		else
		{
			std::cout << "\nGood job agent, you cracked the code and retrieved a file! Keep Going!\n";
		}
		SetConsoleTextAttribute(hConsole, 15);
		bIsPlayerCorrect = true;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "\n## ERROR! Wrong code entered! Try again agent! ##\n";
		SetConsoleTextAttribute(hConsole, 15);
		
		bIsPlayerCorrect = false;
	}
	std::cout << "\n-----------------------------------------------------\n";
	return bIsPlayerCorrect;
}

bool ValidateInput(std::string TempGuess)
{
	for (unsigned int i = 0; i < TempGuess.length(); i++)
		if (!isdigit(TempGuess[i])) return false;		// returns false if any part of string is not a digit

	return true;
}

//git user name : Triple3Apple