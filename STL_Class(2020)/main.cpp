#include <iostream>
#include <vector>
#include <algorithm>
#include "String.h"
using namespace std;
int main()
{
	vector<String> v;
	cout << "vector v�� �ּ�: " << &v << endl;
	v.reserve(4);
	v.emplace_back("�Ϻ�");
	v.emplace_back("�ڷγ�");
	v.emplace_back("�ű�Ȯ��");
	v.emplace_back("700��");
	cout << "------------------" << endl;
	cout << "���Ҹ� �߰��ϱ� ��" << endl;
	
	// v�� ����Ͽ� ���ϴ� ���� �� ��ŭ�ߴ�. �׷��� ���Ұ� �� �� �� �ʿ��ϴ�.
	// �Ʒ��� ���� ���Ҹ� �߰��ϸ� � ���� �Ͼ��?
	v.emplace_back("PANDEMIC");
	cout << "���Ҹ� �߰��� ��" << endl;
	cout << "------------------" << endl;
	cout << "vector v�� �ּ�: " << &v << endl;
}
