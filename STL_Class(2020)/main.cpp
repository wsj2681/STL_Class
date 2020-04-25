#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include "String.h"
#include "save.h"

using namespace std;

string file{ "STL Wiki.txt"s };
string out_file{ "STL Wiki 역순.txt"s };

int main()
{
	// file 읽기
	ifstream in(file);

	vector<char> v = { istreambuf_iterator<char>(in),istreambuf_iterator<char>() };
	reverse(v.begin(), v.end());

	for (auto a : v)
		cout << a;

	//vector<char> str;
	//for (int i = 0; i < 2000; ++i) {

	//	if(v[i] == ' ')
	//		
	//}
	
}