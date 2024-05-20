#include <iostream>

class String
{
public:
	String() = default;

	String(const char *string)
	{
		std::cout << "Created\n";
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String &other)
	{
		std::cout << "Copied\n";
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	/**************************************************************************/
	String(String &&other)
	{
		std::cout << "Moved\n";
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}
	/**************************************************************************/

	~String()
	{
		std::cout << "Destoryed\n";
		delete[] m_Data;
	}

	void print()
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			printf("%c", m_Data[i]);
		}
		printf("\n");
	}

private:
	char *m_Data;
	size_t m_Size;
};

class Entity
{
public:
	Entity(const String &name)
		: m_Name(name)
	{
	}

	/**************************************************************************/
	// Entity(String &&name)
	// 	: m_Name(name) // still call [String(const String &other)], will make a copy.
	// 				   // String &&name, name is a R-reference, name itself is a L-value
	// {
	// }

	// Entity(String &&name)
	// 	: m_Name((String &&)name) // static cast name(a R-value) to a L-value,
	// 							  // will call [String(String &&other)]
	// {
	// }

	Entity(String &&name)
		: m_Name(std::move(name)) // equals [(String &&)name], std::move just do a static cast
	{
	}

	/**************************************************************************/

	void printName()
	{
		m_Name.print();
	}

private:
	String m_Name;
};

int main()
{

	// Entity e(String("Harry"));
	Entity e("Harry");

	e.printName();
	/*
	Created
	Copied // m_Name(name) in Entity(const String &name)
	Destoryed
	Harry
	Destoryed
	*/

	/**************************************************************************/

	return 0;
}