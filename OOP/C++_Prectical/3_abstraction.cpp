/*Define a base class `Animal` with private attributes `name` and `sound`. Implement public methods for setting and getting these attributes.
 Derive two classes, `Dog` and `Cat`, from the `Animal` class.
  Implement methods to make each animal produce its specific sound.
  Demonstrate abstraction by calling the sound methods for both `Dog` and `Cat`.*/
#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string name, sound;

public:
    void setData(string n, string s)
    {
        name = n;
        sound = s;
    }

    string getName()
    {
        return name;
    }

    string getSound()
    {
        return sound;
    }
};

class Dog : public Animal
{
public:
    void makeSound()
    {
        cout << getName() << " says " << getSound() << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound()
    {
        cout << getName() << " says " << getSound() << endl;
    }
};

int main()
{
    Dog d;
    d.setData("Dog", "Bark Bark");

    Cat c;
    c.setData("Cat", "Meow Meow");

    d.makeSound();
    c.makeSound();

    return 0;
}

