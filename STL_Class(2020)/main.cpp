#include <iostream> 
#include <string>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

class Dog {
	string name; // �̸� - 15���ڱ����� ���
	int age; // ����
	int id; // ���� �� �����Ǵ� ������ ���ڷ� �� id
public:
	Dog() {
		name = { NULL };
		age = 0;
		id = 0;
	}

	Dog(string name, int age, int id) : name{ name }, age{ age }, id(id) {
	}

	string getname() {
		return this->name;
	}
	operator <(const Dog& a, const Dog& b) {
		if(a.)
	}

	friend ostream& operator<<(ostream&, const Dog&);
};

ostream& operator<<(ostream& os, const Dog& dog) {
	os << dog.name << ' ' << dog.age << ' ' << dog.id;
	return os;
}

int main() {
	ifstream in("Dog������", ios::binary);

	Dog data[10000];

	in.read((char*)data, sizeof(Dog) * 10000);

	sort(begin(data), end(data), [](Dog& a, Dog& b) {
		return a > b;
		});

	for (const Dog& dog : data)
		cout << dog << endl;
}