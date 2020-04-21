#include <iostream>


using namespace std;
class Cube
{
public:
	int a;
	int b;
	int c;
	static int i;
	~Cube()
	{
		cout<< "Destroyed:"<< Cube::i<<endl;
		Cube::i++;
	}
	
	Cube(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;

	}
	Cube(const Cube& cb)
	{
		cout<< "调用了拷贝构造方法"<<endl;
		this->a = cb.a+999;
		this->b = cb.b+888;
		this->c = cb.c+777;
	}
	bool equals(Cube& cb)
	{
		if (this->a == cb.a && this->b == cb.b && this->c == cb.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	
};

int Cube::i = 0;
void sixtes(Cube cb)
{
	//值传递，形参会复制一份实参的拷贝，会调用拷贝构造方法
	cout << cb.a << endl;
	cout << cb.b << endl;
	cout << cb.c << endl;
}
void sixtes(Cube* cb)
{
	//指针传递，形参会复制一份指针的拷贝,不会调用拷贝构造方法
	cout << cb->a << endl;
	cout << cb->b << endl;
	cout << cb->c << endl;
}
void sixtess(Cube& cb)
{
	//传引用，相当于指针传递，不会调用拷贝构造方法
	cout << cb.a << endl;
	cout << cb.b << endl;
	cout << cb.c << endl;
}
void sixf1()
{
	
	Cube d();
	Cube a (3, 4, 5);
	Cube b (3, 4, 5);
	Cube* c = new Cube(6, 7, 8);
	//sixtes(a);
	//sixtess(a);
	sixtes(&a);
	cout << a.equals(b) << endl;
	cout << a.equals(*c) << endl;
}
void main()
{
	sixf1();
	
}