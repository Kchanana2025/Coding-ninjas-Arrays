#include <iostream>
using namespace std;
class Vehicle
{
private:
    int maxspeed;

protected:
    int numtyres;

public:
    string color;
    Vehicle()
    {
    }
    Vehicle(int x)
    {
        maxspeed = x;
    }

}; // dont forget semicolon
int main()
{
    Vehicle v;
    v.color = "Blue";
    // v.maxspeed=100; cant be accessed
    // v.numtyres=4; cant be accessed
}