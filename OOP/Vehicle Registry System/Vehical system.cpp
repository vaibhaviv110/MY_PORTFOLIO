//Vehicle Registry System

#include <iostream>
#include <string>
using namespace std;


// Base Class
class Vehicle
{
protected:
    int vehicleID;
    string manufacturer, model;
    int year;


public:
    static int totalVehicles;


    Vehicle()
    {
        vehicleID = 0;
        year = 0;
        totalVehicles++;
    }


    virtual ~Vehicle()
    {
    }


    void setVehicleID(int id) 
    { 
        vehicleID = id; 
    }
    void setManufacturer(string m) 
    { 
        manufacturer = m; 
    }
    void setModel(string m) 
    { 
        model = m; 
    }
    void setYear(int y) 
    { 
        year = y; 
    }


    int getVehicleID() 
    { 
    	return vehicleID; 
    }
    string getManufacturer() 
    { 
        return manufacturer; 
    }
    string getModel() 
    { 
        return model; 
    }
    int getYear() 
    { 
        return year; 
    }


    virtual void display()
    {
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }
};


int Vehicle::totalVehicles = 0;


// Single Inheritance
class Car : public Vehicle
{
protected:
    string fuelType;


public:
    void setFuelType(string f) 
    { 
        fuelType = f; 
    }
    string getFuelType() 
    { 
        return fuelType; 
    }


    void display()
    {
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
    }
};


// Multilevel Inheritance
class ElectricCar : public Car
{
protected:
    int batteryCapacity;


public:
    void setBatteryCapacity(int b) 
    { 
        batteryCapacity = b; 
    }
    int getBatteryCapacity() 
    { 
        return batteryCapacity; 
    }


    void display()
    {
        Car::display();
        cout << "\nBattery Capacity: "
             << batteryCapacity << " kWh";
    }
};


// Multilevel Inheritance
class SportsCar : public ElectricCar
{
private:
    int topSpeed;


public:
    void setTopSpeed(int s) 
    { 
        topSpeed = s; 
    }
    int getTopSpeed() 
    { 
        return topSpeed; 
    }


    void display()
    {
        ElectricCar::display();
        cout << "\nTop Speed: " << topSpeed << " km/h";
    }
};


// Hierarchical Inheritance
class Sedan : public Car
{
public:
    void display()
    {
        cout << "\n--- Sedan Details ---";
        Car::display();
    }
};


class SUV : public Car
{
public:
    void display()
    {
        cout << "\n--- SUV Details ---";
        Car::display();
    }
};


// Second Base Class for Multiple Inheritance
class Aircraft
{
protected:
    int flightRange;


public:
    Aircraft()
    {
        flightRange = 0;
    }


    void setFlightRange(int r) 
    { 
        flightRange = r; 
    }
    int getFlightRange() 
    { 
        return flightRange; 
    }
};


// Multiple Inheritance
class FlyingCar : public Car, public Aircraft
{
public:
    void display()
    {
        cout << "\n--- Flying Car Details ---";
        Car::display();
        cout << "\nFlight Range: " << flightRange << " km";
    }
};


// Vehicle Registry
class VehicleRegistry
{
private:
    Vehicle *vehicles[100];
    int count;


public:
    VehicleRegistry()
    {
        count = 0;
    }


    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete vehicles[i];
        }
    }


    void addVehicle(Vehicle *v)
    {
        if (count < 100)
        {
            vehicles[count] = v;
            count++;
            cout << "\nVehicle added successfully!\n";
        }
        else
        {
            cout << "\nRegistry is full!\n";
            delete v;
        }
    }


    void displayAll()
    {
        if (count == 0)
        {
            cout << "\nNo vehicles found!\n";
            return;
        }


        for (int i = 0; i < count; i++)
        {
            cout << "\n========================";
            cout << "\nVehicle " << i + 1;
            vehicles[i]->display();
            cout << "\n========================\n";
        }


        cout << "\nTotal Registered Vehicles: " << count;
        cout << "\nTotal Vehicle Objects Created: "
             << Vehicle::totalVehicles << "\n";
    }


    void searchVehicle(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\nVehicle Found!";
                vehicles[i]->display();
                cout << endl;
                return;
            }
        }


        cout << "\nVehicle not found!\n";
    }
};


// Input common vehicle details
void inputVehicle(Vehicle *v)
{
    int id, y;
    string m, model;


    cout << "Enter Vehicle ID: ";
    cin >> id;


    cout << "Enter Manufacturer: ";
    cin >> m;


    cout << "Enter Model: ";
    cin >> model;


    cout << "Enter Year: ";
    cin >> y;


    v->setVehicleID(id);
    v->setManufacturer(m);
    v->setModel(model);
    v->setYear(y);
}


// Input Car details
void inputCar(Car *c)
{
    string fuel;


    inputVehicle(c);


    cout << "Enter Fuel Type: ";
    cin >> fuel;


    c->setFuelType(fuel);
}


// Main Function
int main()
{
    VehicleRegistry registry;
    int choice, id;
    string fuel;
    int battery, speed, range;


    do
    {
        cout << "\n===== VEHICLE REGISTRY SYSTEM =====";
        cout << "\n1. Add Car";
        cout << "\n2. Add Electric Car";
        cout << "\n3. Add Sports Car";
        cout << "\n4. Add Sedan";
        cout << "\n5. Add SUV";
        cout << "\n6. Add Flying Car";
        cout << "\n7. View All Vehicles";
        cout << "\n8. Search Vehicle by ID";
        cout << "\n9. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
        {
            Car *c = new Car();
            inputCar(c);
            registry.addVehicle(c);
            break;
        }


        case 2:
        {
            ElectricCar *e = new ElectricCar();
            inputCar(e);


            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;
            e->setBatteryCapacity(battery);


            registry.addVehicle(e);
            break;
        }


        case 3:
        {
            SportsCar *s = new SportsCar();
            inputCar(s);


            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;
            s->setBatteryCapacity(battery);


            cout << "Enter Top Speed (km/h): ";
            cin >> speed;
            s->setTopSpeed(speed);


            registry.addVehicle(s);
            break;
        }


        case 4:
        {
            Sedan *s = new Sedan();
            inputCar(s);
            registry.addVehicle(s);
            break;
        }


        case 5:
        {
            SUV *s = new SUV();
            inputCar(s);
            registry.addVehicle(s);
            break;
        }


        case 6:
        {
            FlyingCar *f = new FlyingCar();
            inputCar(f);


            cout << "Enter Flight Range (km): ";
            cin >> range;
            f->setFlightRange(range);


            registry.addVehicle(f);
            break;
        }


        case 7:
            registry.displayAll();
            break;


        case 8:
            cout << "Enter Vehicle ID to search: ";
            cin >> id;
            registry.searchVehicle(id);
            break;


        case 9:
            cout << "\nThank you for using Vehicle Registry!";
            break;


        default:
            cout << "\nInvalid choice! Try again.\n";
        }


    } while (choice != 9);


    return 0;
}
