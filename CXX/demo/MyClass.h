class MyClass
{
public:
	// 成员变量a
	int a;
	// 成员变量b
	float b;

	//成员函数add
	int add(int n, int m)
	{
		int result = n + m;
		return result;
	}

public:
	// 构造函数（初始化函数）
	MyClass(int _a, int _b)
	{
		a = _a; // 等价于 this.a = _a;
		b = _b; // 等价于 this.b = _b;
	}
};

MyClass::MyClass(int _a, int _b)
{
	a = _a; // 等价于 this.a = _a;
	b = _b; // 等价于 this.b = _b;
}


