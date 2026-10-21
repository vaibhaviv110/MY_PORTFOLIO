/*Extend the `Animal` hierarchy from Question 3 to include a virtual function `displayDetails()`.
 Implement the `displayDetails()` function in each derived class to print information specific to the animal.
  Create an array of `Animal` pointers, pointing to objects of different animals.
 Demonstrate polymorphism by calling the `displayDetails()` function for each object.*/
#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string name;

public:
    Animal(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    virtual void displayDetails()
    {
        cout << "Animal: " << name << endl;
    }
};

class Dog : public Animal
{
public:
    Dog() : Animal("Dog") {}

    void displayDetails() override
    {
        cout << "Dog says Woof Woof" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat() : Animal("Cat") {}

    void displayDetails() override
    {
        cout << "Cat says Meow Meow" << endl;
    }
};

int main()
{
    Dog d;
    Cat c;

    Animal *a[2];

    a[0] = &d;
    a[1] = &c;

    for (int i = 0; i < 2; i++)
    {
        a[i]->displayDetails();
    }

    return 0;
}

