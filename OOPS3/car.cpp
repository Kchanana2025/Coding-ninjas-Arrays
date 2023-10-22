#include "Vehicle.cpp"
// protected data from Vehicle is inherited to protected data of child
// public data from Vehicle is inherited  to public data of child
class Car : public Vehicle
{
public:
    int numGears;

    Car(int x, int y) : Vehicle(x)
    {
        cout << "car's constructor";
        numGears = y;
    }
    ~Car()
    {
        cout << "Car's Destructor";
    }
    void print()
    {
        cout << "NumTyres :" << numtyres << endl; // accessible
        cout << "color:" << color << endl;        // accessible
        cout << "numgears:" << numGears << endl;
        // cout << "Max Speed:" << maxspeed << endl; // not accessible because it is private member of parent class
    }
    Car()
    {
    }
};
#include <iostream>
using namespace std;
int main()
{
    Car c;
    c.color = "Black";
    // c.numTyres=4;//cant be accessed because it is protected mem

    return 0;
}