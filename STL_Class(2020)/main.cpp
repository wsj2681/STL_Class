#include <iostream> 
#include <string>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

class Dog {
	string name; // 이름 - 15글자까지만 허용
	int age; // 나이
	int id; // 생성 시 결정되는 고유의 숫자로 된 id
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
	ifstream in("Dog만마리", ios::binary);

	Dog data[10000];

	in.read((char*)data, sizeof(Dog) * 10000);

	sort(begin(data), end(data), [](Dog& a, Dog& b) {
		return a > b;
		});

	for (const Dog& dog : data)
		cout << dog << endl;
}