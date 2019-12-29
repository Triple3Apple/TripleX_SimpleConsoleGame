/*
git user name: Triple3Apple

*/

// preprocessor directive
#include <iostream>
#include <string>

// NOTE: Unreal Engine Naming Convention: ParcelCase, e.g. int LoopIndex;

bool ValidateInput(std::string TempGuess);
void StartGame();
void PrintIntroAndHints();

const int CodeA = 3;
const int CodeB = 7;
const int CodeC = 5;

const int CodeSum = CodeA + CodeB + CodeC;
const int CodeProduct = CodeA * CodeB * CodeC;
int GuessSum;
int GuessProduct;

int GuessA, GuessB, GuessC;


int main()
{
	StartGame();
	return 0;
}

void StartGame()
{
	PrintIntroAndHints();

	std::string TempA, TempB, TempC;

	GuessSum = 0;
	GuessProduct = 0;

	// clearing input buffer (cin)
	std::cin.clear();


	std::cout << "Enter the first number of the secret code to continue...\n";
	std::cin >> TempA;

	// loops until player enters a integer
	while (!ValidateInput(TempA))
	{
		std::cout << TempA << " <-- is not a valid input, please enter a integer\n";
		std::cin >> TempA;
	}

	std::cout << "Enter the second number of the secret code to continue...\n";
	std::cin >> TempB;

	// loops until player enters a integer
	while (!ValidateInput(TempB))
	{
		std::cout << TempB << " <-- is not a valid input, please enter a integer\n";
		std::cin >> TempB;
	}

	std::cout << "Enter the third number of the secret code to continue...\n";
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

	// Check if player's code is correct
	if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
	{
		std::cout << "You cracked the code!\n";
	}
	else
	{
		std::cout << "ERROR! Wrong code entered! You Lose!\n";
	}
}

void PrintIntroAndHints()
{
	std::string test = "   |_|  |_|  \\_\\_____|_|    |______|______| /_/ \\_\\ \n";
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
	std::cout << "\n\n";

	std::cout << "You are a secret agent breaking into a secure server room...\n";
	std::cout << "You need a secret code to enter.\n";
	std::cout << "# There are 3 numbers in the code.\n";
	std::cout << "# The code adds up to: " << CodeSum << std::endl;
	std::cout << "# The code multiplies to : " << CodeProduct << "\n\n";
}

bool ValidateInput(std::string TempGuess)
{
	for (unsigned int i = 0; i < TempGuess.length(); i++)
		if (!isdigit(TempGuess[i])) return false;		// returns false if any part of string is not a digit

	return true;
}