#include <iostream> 
#include <memory>
using namespace std;

class Dog {
	int n;
public:
	// ������ �Ҹ� ������
	Dog() { cout << "����" << endl; }
	~Dog() { cout << "�Ҹ�" << endl; }
	void show() {
		cout << "Dog�Դϴٸ�" << endl;
	}
};

int main()
{
	// ������ ���� �ڵ带 �������� ������
	{
		// ��ü �� �� - �̷��� unique_ptr�� �����ϴ� ���� �� ����
		auto dog = make_unique<Dog>();
	}
	// ��ü ���� ��
	unique_ptr<Dog[]> dogs{ new Dog[3] };
}
