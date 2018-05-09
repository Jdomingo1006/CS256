//Inheritance Example
/*#include <iostream> 
#include <cstdio> 
#include <string> 
using namespace std;

// Base class 
class Animal {
private:
	//Private by defualt without "private: "
	string _name;
	string _type;
	string _sound;
	// private constructor prevents construction of base class 
	Animal() {};
protected:
	// protected constructor for use by derived classes 
	Animal(const string & n, const string & t, const string & s)
		: _name(n), _type(t), _sound(s) {
		printf("Animal Constructed\n");
	}
public:
	void speak() const;
	const string & name() const { return _name; }
	const string & type() const { return _type; }
	const string & sound() const { return _sound; }
};

void Animal::speak() const {
	printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal 
class Dog : public Animal {
	int walked; //Private
public:
	Dog(string n) : Animal(n, "dog", "woof"), walked(0) {
		printf("Dog Constructed\n");
	};
	int walk() {
		return ++walked;
	}
};

// Cat class - derived from Animal 
class Cat : public Animal {
	int petted; //Private
public:
	Cat(string n) : Animal(n, "cat", "meow"), petted(0) {
		printf("Cat Constructed\n");
	};
	int pet() { 
		return ++petted; 
	}
};

// Pig class - derived from Animal 
class Pig : public Animal {
	int fed;
public:
	Pig(string n) : Animal(n, "pig", "oink"), fed(0) {
		printf("Pig Constructed\n");
	};
	int feed() {
		return ++fed; 
	}
	string piglatin() const;
};
//Added new function
string Pig::piglatin() const {
	return Animal::name() + "-ay";
}

int main(int argc, char ** argv) {

	Dog d("Rover");
	Cat c("Fluffy");
	Pig p("Arnold");

	d.speak();
	c.speak();
	p.speak();

	printf("the dog has been walked %d times\n", d.walk());
	printf("the cat has been petted %d times\n", c.pet());
	printf("the pig has been fed %d times\n", p.feed());
	printf("The pig can also be called %s\n", p.piglatin().c_str());
}*/

//Multiple Inheritance

/*
#include <cstdio> 
#include <string> 
using namespace std;

class Fur {
private:
	string _type;
	Fur() {};
protected:
	Fur(const string & f) : _type(f) {};
public:
	const string & type() const { return _type; }
};

// Base class 
class Animal {
	string _name;
	string _type;
	string _sound;
	// private constructor prevents construction of base class 
	Animal() {};
protected:
	// protected constructor for use by derived classes 
	Animal(const string & n, const string & t, const string & s)
		: _name(n), _type(t), _sound(s) {
		printf("Animal Constructed\n");
	}
public:
	void speak() const;
	const string & name() const { return _name; }
	const string & type() const { return _type; }
	const string & sound() const { return _sound; }
};

void Animal::speak() const {
	printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal 
class Dog : public Animal {
	int walked;
public:
	Dog(string n) : Animal(n, "dog", "woof"), walked(0) {
		printf("Dog Constructed\n");
	};
	int walk() { return ++walked; 
};

// Cat class - derived from Animal 
class Cat : public Animal, public Fur {
	int petted;
public:
	Cat(string n) : Animal(n, "cat", "meow"), Fur("fluffy"), petted(0) {
		printf("Cat Constructed\n");
	};
	int pet() { return ++petted; }
	void grooming() const;
};

void Cat::grooming() const {
	printf("%s grooms her %s fur\n", Animal::name().c_str(), Fur::type().c_str());
}

// Pig class - derived from Animal 

class Pig : public Animal {
	int fed;
public:
	Pig(string n) : Animal(n, "pig", "oink"), fed(0) {
		printf("Pig Constructed\n");
	};
	int feed() { return ++fed; }
};

int main(int argc, char ** argv) {
	Dog d("Rover");
	Cat c("Fluffy");
	Pig p("Arnold");

	d.speak();
	c.speak();
	p.speak();

	printf("the dog has been walked %d times\n", d.walk());
	printf("the cat has been petted %d times\n", c.pet());
	printf("the pig has been fed %d times\n", p.feed());
	c.grooming();
}*/