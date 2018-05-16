#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Template

template < typename T>

T add(T x, T y) {
	return x + y;
}
int main() {
	vector<string> num{ "one", "two", "three", "four" }; //Like an array
	vector<int> realNum{ 1,2,3,4 };

	cout << add<float>(7, 9) << endl;


	for (string s : num) //range based for loop
	{
		cout << s << " ";
	}
	for (int i : realNum)
	{
		cout << i << " ";
	}
	return 0;
}