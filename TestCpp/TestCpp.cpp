#include <iostream>
#include <conio.h>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

void render_menu(int& current_menu, std::vector<std::string>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (current_menu == i)
		{
			std::cout << "\033[1;30m->\033[0m \033[1;31m" + arr[i] + "\033[0m\n";
		}
		else
		{
			std::cout << "   " + arr[i] + "\n";
		}
	}
}

std::string get_answer(int value)
{
	switch (value) {
	case 1:
		return "Hello, World!";
	case 2:
		return "Bye, World!";
	case 3:
		exit(0);
	default:
		return "You need to add new case for menu in get_answer function!";
	}
}

void get_key(int &value, int menu_size, std::string &answer)
{
	int key = _getch();

	switch (key) {
	case KEY_UP:
		if (value > 0 && value != menu_size)
		{
			value--;
		}

		break;
	case KEY_DOWN:
		if (value >= 0 && value != menu_size - 1)
		{
			value++;
		}

		break;
	case KEY_ENTER:
		answer = get_answer(value + 1);

		break;
	}

	if (key != KEY_UP && key != KEY_DOWN && key != KEY_ENTER)
		get_key(value, menu_size, answer);
}

int main()
{
	std::vector<std::string> arr = { "Hello", "Bye" ,"Exit" };
	int current_menu = 0;
	std::string answer = "";

	while (answer.size() == 0)
	{
		render_menu(current_menu, arr);

		get_key(current_menu, arr.size(), answer);
	
		system("cls");
	}

	std::cout << answer << std::endl;
}
