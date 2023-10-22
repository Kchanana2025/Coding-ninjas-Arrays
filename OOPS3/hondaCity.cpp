#include "car.cpp"
class HondaCity : public Car
{
public:
    HondaCity(int x, int y) : Car(x, y)
    {
        cout << "Hondacity Constructor" << endl;
    }
    ~HondaCity()
    {
        cout << "Hondacity Destructor" << endl;
    }
};