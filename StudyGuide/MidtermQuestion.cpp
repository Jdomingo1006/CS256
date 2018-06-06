#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Top {
public:
	virtual void MyMemory() { cout << "I forget" << endl; }
	void Disk() { cout << "Space" << endl; }
	void Erased() { cout << "For good" << endl; }
	void ThisExam() { Erased(); MyMemory(); }
	virtual ~Top() {}
};

class Bottom : public Top {
public:
	void MyMemory() { cout << "Gone" << endl; }
	void Disk() { cout << "Slipped" << endl; }
	void virtual Erased() { cout << "Rubbed out" << endl; }
};

int main() {
	Top* Hat = new Bottom;
	Hat->MyMemory();
	Hat->Disk();
	Hat->ThisExam();
	Top Dog = *(new Bottom);
	Dog.MyMemory();
	Dog.Disk();
	Dog.ThisExam();
}

//Output:
/*
*Gone0
*Space
*For good
*Gone
*I forget
*Space
*For good
*I forget
*/