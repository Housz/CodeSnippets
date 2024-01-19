#include <iostream>

enum class Type : int
{
	BT_UNKOWN = -1,
	BT_LEFT = 0,
	BT_RIGHT = 1,
	BT_MIDDLE = 2,
};

enum class Key : int
{
	PKEY_0 = 1,
	PKEY_1 = 49,
	PKEY_2 = 50,
	PKEY_3 = 51,
	PKEY_4 = 52,
	PKEY_5 = 53,
	PKEY_6 = 54,
	PKEY_7 = 55,
	PKEY_8 = 56,
	PKEY_9 = 57,
};

int main()
{

	std::cout << (Type::BT_UNKOWN == Type::BT_LEFT) << std::endl;
	// std::cout << (Type::BT_RIGHT == Key::PKEY_0) << std::endl; // error

	return 0;
}