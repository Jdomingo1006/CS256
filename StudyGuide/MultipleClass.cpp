#include <iostream> 
using namespace std;
class Count {
private:
	int a;	//each object will have its own 
	int b;	//each object will have its own 
	static int count;	//one variable declared. Shared by all instances of class(OBJECTS) 

public:
	Count(int, int);
	void printCount() const;	//means its const safe   
	static void getCount(); //Static function. Don't have to create an object
};

int Count::count = 0;	//static variables need to be initalized outside of constructor  

void Count::getCount() {
	cout << count << endl;
}

Count::Count(int a = 1, int b = 1) {
	a = a;
	this->b = b;	//this is same as b=b; 
	count++;	//All instances of objects will increment count by 1 
}

void Count::printCount() const {
	cout << count << endl;
}

int main()
{
	Count::getCount();
	Count A;
	A.printCount();
	Count B(2, 2);
	B.printCount();
	Count C(3, 3);
	C.printCount();
	return 0;
}*/

/*********************************************************************************************/


#include <iostream> 
using namespace std;

class Humidity; //Forward declaration tell compiler - dont freak out
class Temperature
{
private:
	int m_temp;
public:
	Temperature(int temp = 0) { m_temp = temp; }
	friend void printWeather(const Temperature &temperature, const Humidity &humidity); //"&" symbol is the symbol for reference
};

class Humidity
{
private:
	int m_humidity;
public:
	Humidity(int humidity = 0) { m_humidity = humidity; }
	friend void printWeather(const Temperature &temperature, const Humidity &humidity);
};

void printWeather(const Temperature &temperature, const Humidity &humidity)
{
	cout << "The temperature is " << temperature.m_temp <<
		" and the humidity is " << humidity.m_humidity << '\n';
}

int main()
{
	Humidity hum(10);
	Temperature temp(12);
	printWeather(temp, hum);
	return 0;
}*/

/****************************************************************/

#include <iostream> 
using namespace std;

class Storage
{
private:
	int m_nValue;
	double m_dValue;
public:
	Storage(int nValue, double dValue)
	{
		m_nValue = nValue;
		m_dValue = dValue;
	}
	// Make the Display class a friend of Storage 
	friend class Display;
};



class Display
{
private:
	bool m_displayIntFirst;
public:
	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
	void displayItem(Storage &storage)
	{
		if (m_displayIntFirst)
			cout << storage.m_nValue << " " << storage.m_dValue << '\n';
		else // display double first 
			cout << storage.m_dValue << " " << storage.m_nValue << '\n';
	}
};

int main()
{
	Storage storage(5, 6.7);
	Display display(false);
	display.displayItem(storage);
	return 0;
}*/

/****************************************************************/
#include <iostream> 

using namespace std;
class Storage; // forward declaration for class Storage 
class Display
{
private:
	bool m_displayIntFirst;
public:
	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
	void displayItem(Storage &storage); // forward declaration above needed for this declaration line 
};

class Storage // full definition of Storage class 
{
private:
	int m_nValue;
	double m_dValue;
public:
	Storage(int nValue, double dValue)
	{
		m_nValue = nValue;
		m_dValue = dValue;
	}
	// Make the Display::displayItem member function a friend of the Storage class (requires seeing the full declaration of class Display, as above) 
	friend void Display::displayItem(Storage& storage);
};
// Now we can define Display::displayItem, which needs to have seen the full declaration of class Storage 
void Display::displayItem(Storage &storage)
{
	if (m_displayIntFirst)
		cout << storage.m_nValue << " " << storage.m_dValue << '\n';
	else // display double first 
		cout << storage.m_dValue << " " << storage.m_nValue << '\n';
}

int main()
{
	Storage storage(5, 6.7);
	Display display(false);
	display.displayItem(storage);
	return 0;
}