#include <iostream> 
#include <string>
#include <random>
#include <fstream>
using namespace std;

int gid{ 0 };

default_random_engine dre;
uniform_int_distribution<int> uidAge(1, 12);
uniform_int_distribution<int> uidName('a', 'z');
uniform_int_distribution<int> uidNameLen(3, 15);

class Dog {
	string name;
	int age;
	int id;

public:
	Dog() : id{ ++gid } {
		int len = uidNameLen(dre);
		
		for (int i = 0; i < len; ++i)
			name += uidName(dre);

		age = uidAge(dre);
	}
	
	Dog(string name, int age) : name{ name }, age{ age }, id(++gid) {
	}
	string getter()const {
		return name;
	}

	friend ostream& operator<<(ostream&, const Dog&);
};
ostream& operator<<(ostream& os, const Dog& dog) {
	os << dog.name << dog.age << dog.id << endl;
	return os;
}
int main() {
	ifstream in("Dog¸¸¸¶¸®", ios::binary);

	Dog* data = new Dog[1'0000];

	in.read((char*)data, sizeof(Dog) * 1'0000);

	sort(data, data + 1'0000);

	for (int i = 0; i < 1'0000; ++i) {
		cout << data[i] << endl;
	}
}