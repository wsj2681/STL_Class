#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

void save(const char* fileName) {

	cout << fileName << " save complte" << endl;

	ifstream inFile(fileName);
	ofstream outFile("2020_STL_���ǳ���.txt", ios::app);

	auto now = chrono::system_clock::now();// ���� �ð� ��
	auto time = chrono::system_clock::to_time_t(now);

	outFile << "\n\n\n";
	outFile << "****************************" << endl;
	outFile << ctime(&time);
	outFile << "****************************" << endl;
	outFile << "\n\n";


	char c;

	while ((c = inFile.get()) != EOF) {
		outFile.put(c);
	}
}