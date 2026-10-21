/*Define a class `Person` with private attributes `name`, `age`, and `address`.
 Encapsulate these attributes using getter and setter methods. 
Implement a parameterized constructor for the `Person` class.
 Create N number of objects using this constructor and display the details.*/
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name, address;
    int age;

public:
    // Parameterized constructor
    Person(string n, int a, string ad)
    {
        name = n;
        age = a;
        address = ad;
    }

    // Setter methods
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setAddress(string ad) { address = ad; }

    // Getter methods
    string getName() { return name; }
    int getAge() { return age; }
    string getAddress() { return address; }

    void display()
    {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Address: " << getAddress() << endl;
    }
};

int main()
{
    Person p1("Vaibhavi", 21, "Ahmedabad");
    Person p2("Palak", 20, "Surat");

    cout << "Person 1:" << endl;
    p1.display();

    cout << "\nPerson 2:" << endl;
    p2.display();

    return 0;
}

