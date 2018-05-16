/*
*James Domingo
*CS256
* May 15th 2018	
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Human Class
class Human {
private:
	string name;
	int age;
	char sex;
	Human();
protected:
	Human(string inputName, int inputAge, char inputSex) {
		name = inputName;
		age = inputAge;
		sex = inputSex;
	}
public:
	//setters
	void setName(string inputName) {name = inputName;}
	void setAge(int inputAge) {	age = inputAge;}
	void setSex(char inputSex) { sex = inputSex;}
	//getters
	string getName() { return name; }
	int getAge() { return age; }
	char getSex() { return sex; }
	//virtual work
	virtual void work();

	friend class Parent;
	friend class Child;

};

//Parent class
class Parent : public Human {
private:
	vector<Child> children;
public:
	string name2;
	int age2;
	char sex2;
	string workplace;

	//Setters
	void setChildName(string inputName) { name2 = inputName; }
	void setChildAge(int inputAge) { age2 = inputAge; }
	void setChildSex(char inputSex) { sex2 = inputSex; }

	//Getters
	string getChildName() { return name2; }
	int getChildAge() { return age2; }
	char getChildSex() { return sex2; }

	void work(string work) {
		workplace = work;
	}
	string getWork() { return workplace; }

};

//Child class
class Child : public Human {
private:
	string ParentMom;
	string ParentDad;
	Child();
public:
	string workplace;
	Child(string inputMom, string inputDad) {
		ParentMom = inputMom;
		ParentDad = inputDad;
	}
	void work(string work) {
		workplace = work;
	}
	string getWork() { return workplace; }
};



int main() {
	//Creating objects
	Parent Marge ("Marge", 34, 'F');
	Parent Homer("Homer", 36, 'M');
	Child Bart("Bart", 10, 'M');
	Child Lisa("Lisa", 12, 'F');
	Child Maggie("Maggie", 3, 'F');

	//Setting work
	Marge.work("Housewife");	
	Homer.work("Safety Inspector");
	Bart.work("Student");
	Lisa.work("Student");
	Maggie.work("Play");

	//Printing out information
	cout << "Name\t\t" << "Age\t" << "Sex\t" << "Work" << endl;
	cout << Homer.getName() << "\t" << Homer.getAge() << "\t" << Homer.getSex() << "\t" << Homer.getWork() << endl;
	cout << Lisa.getName() << "\t" << Lisa.getAge() << "\t" << Lisa.getSex() << "\t" << Lisa.getWork() << endl;
	cout << Maggie.getName() << "\t" << Maggie.getAge() << "\t" << Maggie.getSex() <<"\t" << Maggie.getWork()<< endl;

	return 0;
}