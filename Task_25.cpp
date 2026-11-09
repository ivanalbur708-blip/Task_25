#include <iostream>
#include <string>
#include "Windows.h"

class Email
{
private:
	std::string email;
public:
	Email()
	{
		email = "example@example.org";
	}

	void SetEmail(const std::string& newEmail){
		email = newEmail;
	}

	std::string GetEmail() const 
	{
		return email;
	}

	void SubStr() const 
	{
		auto pos = email.find('@');

		if (pos != std::string::npos)
		{
			std::string username = email.substr(0, pos);
			std::string domain = email.substr(pos + 1);

			std::cout << "Username: " << username << '\n';
			std::cout << "Domain: " << domain << '\n';
		}
		else
		{
			std::cout << "Invalid email" << '\n';
		}
	}

};




int main()
{
	// Використовуємо кодування UTF-8 для коректного
    // введення та виведення кириличних символів.
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8); 


	//Task1
	std::string email;

    std::getline(std::cin, email);

	auto pos = email.find('@');

	if (pos != std::string::npos)
	{
		std::string username = email.substr(0, pos);
		std::string domain = email.substr(pos + 1);

		std::cout << "Username: " << username << '\n';
		std::cout << "Domain: " << domain << '\n';
	}

	else
	{
		std::cout << "Invalid email" << '\n';
	}

	//Task2
	std::string text;
	std::string word;

	std::getline(std::cin, text);

	std::getline(std::cin, word);

	auto poss = text.find(word);

	if (!word.empty() && poss != std::string::npos)
	{
		text.replace(poss, word.length(), "***");
	}
	text += "[Відредаговано]";

	std::cout << text << '\n';
}
