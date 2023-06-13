#include <iostream>
#include <thread>
#include <chrono>

#include <string>
#include <fstream>

void loading()
{
	std::string load = ". ";
	std::string dot = ". ";

	for (int i = 0; i < 3; i++)
	{
		system("cls");
		std::cout << "\v\v\v\t\t\t" << load;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		load = load + dot;
	}

	std::cout << "\v\v\v\t\t\t" << std::endl;
	system("cls");
}

void registerExit();
void loginExit();

void displayMenu()
{
	std::cout << "\t\tDATABASE" << std::endl;
	std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
	std::cout << "\t  1. Login " << std::endl;
	std::cout << "\t  2. Register " << std::endl;
	std::cout << "\t  3. Exit " << std::endl;
	std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
}

int inputUser()
{
	int choice;
	std::cout << "\t : ";
	std::cin >> choice;
	return choice;
}

bool checkInputUser(int input)
{
	if (input > 3 || input < 1)
	{
		system("cls");
		std::cout << "\t Invalid Input! Try Again!" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");
		return true;
	}
	return false;
}

bool checkLoginUser(const std::string& username, const std::string& password)
{
	std::fstream file2;
	std::fstream file3;
	file2.open("Username.txt", std::ios::in);
	file3.open("Password.txt", std::ios::in);

	std::string Username;
	std::string Password;
	std::string Pass;

	bool flag = false;

	if (file2.is_open())
	{
		while (std::getline(file2, Username))
		{
			if (Username == username)
			{
				if (file3.is_open())
				{
					while (std::getline(file3, Password))
					{
						if (Password == password)
						{
							file2.close();
							file3.close();
							return false;
						}
					}
					file3.clear();
					file3.seekg(0);
					while (flag == false)
					{
						system("cls");
						std::cout << "\t\tLOGIN" << std::endl;
						std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
						std::cout << "\t ( Incorrect Password!)" << std::endl;
						std::cout << "\t  Username:  " << username << std::endl;
						std::cout << "\t  Password: ";
						std::getline(std::cin, Pass);
						std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(2));
						while (std::getline(file3, Password))
						{
							if (Password == Pass)
							{
								file2.close();
								file3.close();
								return false;
							}
						}
						file3.clear();
						file3.seekg(0);
					}
				}
			}
		}
		file2.close();
	}
	return true;
}



void loginUser()
{
	std::string Username;
	std::string Password;

	bool flag;

	std::cout << "\t\tLOGIN" << std::endl;
	std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
	std::cout << "\t  Username:  ";
	std::getline(std::cin >> std::ws, Username);
	std::cout << "\t  Password: ";
	std::getline(std::cin >> std::ws, Password);
	std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;

	flag = checkLoginUser(Username, Password);

	while (flag == true)
	{
		system("cls");
		std::cout << "\t\tLOGIN" << std::endl;
		std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
		std::cout << "\t( Incorrect Username or Password! ) " << std::endl;
		std::cout << "\t  Username:  ";
		std::getline(std::cin >> std::ws, Username);
		std::cout << "\t  Password: ";
		std::getline(std::cin >> std::ws, Password);
		std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
		flag = checkLoginUser(Username, Password);
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "\t Login Successful!" << std::endl;
}

bool checkName(const std::string& name)
{
	std::string Name;
	std::fstream file1;
	file1.open("Name.txt", std::ios::in);
	if (file1.is_open())
	{
		while (std::getline(file1, Name))
		{
			if (Name == name)
			{
				return true;
			}
		}
		file1.close();
	}
	return false;
}

void registerUser()
{
	std::fstream file1;
	std::fstream file2;
	std::fstream file3;
	file1.open("Name.txt", std::ios::app);
	file2.open("Username.txt", std::ios::app);
	file3.open("Password.txt", std::ios::app);

	std::string Name;
	std::string Username;
	std::string Password;

	int choice;
	bool flag;

	std::cout << "\t\tRegister" << std::endl;
	std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
	std::cout << "\t Name:  ";
	std::getline(std::cin >> std::ws, Name);
	flag = checkName(Name);

	while (flag == true)
	{
		system("cls");
		std::cout << "\t\tRegister" << std::endl;
		std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
		std::cout << "\t ( Name already been used! ) " << std::endl;
		std::cout << "\t Name:  ";
		std::getline(std::cin >> std::ws, Name);
		flag = checkName(Name);
	}

	if (file1.is_open())
	{
		file1 << std::endl << Name;
		file1.close();
	}

	if (file2.is_open())
	{
		std::cout << "\t Username:  ";
		std::getline(std::cin >> std::ws, Username);
		file2 << std::endl << Username;
		file2.close();
	}

	if (file3.is_open())
	{
		std::cout << "\t Password ";
		std::getline(std::cin >> std::ws, Password);
		file3 << std::endl << Password;
		file3.close();
	}

	std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	system("cls");
	std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
	std::cout << "\t   Registration Successful!" << std::endl;
	std::cout << "\t* * * * * * * * * * * * * * * * " << std::endl;
	std::cout << "\t   1. Login         2. Exit" << std::endl;
	std::cout << std::endl;
	choice = inputUser();

	if (choice == 1)
	{
		loading();
		loginUser();
	}
	else
	{
		loading();
		registerExit();
	}
}

int main()
{
	bool userInput;
	int choice;
	do
	{
		displayMenu();
		choice = inputUser();
		userInput = checkInputUser(choice);
	} while (userInput == true);
	loading();
	if (choice == 1)
	{
		system("cls");
		loginUser();
	}
	else if (choice == 2)
	{
		system("cls");
		registerUser();
	}
	else
	{
		exit(0);
	}
	return 0;
}

void registerExit()
{
	main();
}

void loginExit()
{
	main();
}