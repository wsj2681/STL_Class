#include <iostream> 
#include <memory>
using namespace std;

class Dog {
	int n;
public:
	// 생성과 소멸 관찰용
	Dog() { cout << "생성" << endl; }
	~Dog() { cout << "소멸" << endl; }
	void show() {
		cout << "Dog입니다만" << endl;
	}
};

int main()
{
	// 관찰이 쉽게 코드를 지역으로 나눴다
	{
		// 객체 한 개 - 이렇게 unique_ptr를 생성하는 것이 더 좋다
		auto dog = make_unique<Dog>();
	}
	// 객체 여러 개
	unique_ptr<Dog[]> dogs{ new Dog[3] };
}
