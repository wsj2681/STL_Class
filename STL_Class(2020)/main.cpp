#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "save.h"

using namespace std;

//2주 2일차 과제2번

template<class T, int size>
class Array {
	T* data{ nullptr };
public:
	explicit Array() :data{ new T[size] } {}
	~Array() { delete[] data; }
	Array(const Array&) = delete;

	Array& operator=(const Array&) = delete;

	T operator[](int idx) const { return data[idx]; }
	T& operator[](int idx) { return data[idx]; }
};

int main()
{
	Array<string, 10> a; // string 10개를 담을 수 있는 자료구조 a

	for (int i = 0; i < 10; ++i)
		a[i] = "string"s + to_string(i); // a에 쓰기

	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl; // a에서 읽기
}