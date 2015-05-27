//inheritance and polymorphism

#include <iostream>
#include <string>

using namespace std;

//base class
class Shape
{
private:
	string name;

public:
	Shape(string s)
	{
		name = s;
	}

	void setName(string s)
	{
		name = s;
	}

	string getName() const
	{
		return name;
	}

	//pure virtual function
	virtual double getArea() const = 0;

};

//first child class
class circle : public Shape
{
private:
	double radius;

public:
	circle(string n, double r) : Shape(n)
	{
		radius = r;
	}

	void setRadius(double r)
	{
		radius = r;
	}

	double getRadius() const
	{
		return radius;
	}

	virtual double getArea() const
	{
		return 3.14159 * radius * radius;
	}
};

//second child class
class rectangle : public Shape
{
	double length, width;

public:
	rectangle(string n, double l, double w) : Shape(n)
	{
		length = l;
		width = w;
	}

	void setLength(double l)
	{
		length = l;
	}

	void setWidth(double w)
	{
		width = w;
	}

	double getLength()
	{
		return length;
	}

	double getWidth()
	{
		return width;
	}

	virtual double getArea() const
	{
		return length * width;
	}
};

int main()
{


	circle c("Circle", 3.1);
	c.setName("First circle");
	cout << c.getName() << " " << c.getRadius() << " Area: "<< c.getArea() << endl;

	rectangle r("Rekt", 4.2, 2.5);
	cout << r.getName() << " " << r.getLength() << " " << r.getWidth() << " " << " Area: " << r.getArea() << endl;
	
	// POLYMORPHISM - combine different objects and store in same array
	// create array of pointers of the base class
	Shape* shapes[2] = { new circle("circle", 2.9), 
						 new rectangle("Rektangle", 5.6, 8.7) };
	cout << endl;

	// print area of all shape objects in shape array
	for (int i = 0; i < 2; i++)
	{
		cout << "Shape: " << shapes[i]->getName() << " Area: " << shapes[i]->getArea() << endl;
	}


	for (int i = 0; i < 2; i++)
	{
		delete shapes[i];
	}

	cout << endl;
	return 0;
}