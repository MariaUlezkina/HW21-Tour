#include "Tour.h"

Tour::Tour()
{
    name = new char[10] {"no"};
    destination = new char[10] {"no"};
    dayPrice = 0;
    daysCount = 0;
    foodIncluded = false;
    transportCost = 0;
}

Tour::Tour(const char* _name, const char* _destination, float _dayPrice, int _daysCount, bool _foodIncluded, float _transportCost)
{
    int size_name = strlen(_name) + 1;
    name = new char[size_name];
    strcpy_s(name, size_name, _name);
    int size_dest = strlen(_destination) + 1;
    destination = new char[size_dest];
    strcpy_s(destination, size_dest, _destination);

    dayPrice = _dayPrice;
    daysCount = _daysCount;
    foodIncluded = _foodIncluded;
    transportCost = _transportCost;
}

Tour::Tour(const Tour& obj)
{
    int size_name = strlen(obj.name) + 1;
    name = new char[size_name];
    strcpy_s(name, size_name, obj.name);
    int size_dest = strlen(obj.destination) + 1;
    destination = new char[size_dest];
    strcpy_s(destination, size_dest, obj.destination);

    dayPrice = obj.dayPrice;
    daysCount = obj.daysCount;
    foodIncluded = obj.foodIncluded;
    transportCost = obj.transportCost;
}

Tour& Tour::operator=(const Tour& obj)
{
    if (this == &obj)
    {
        return *this;
    }

    delete[] name;
    delete[] destination;

    int size_name = strlen(obj.name) + 1;
    name = new char[size_name];
    strcpy_s(name, size_name, obj.name);
    int size_dest = strlen(obj.destination) + 1;
    destination = new char[size_dest];
    strcpy_s(destination, size_dest, obj.destination);

    dayPrice = obj.dayPrice;
    daysCount = obj.daysCount;
    foodIncluded = obj.foodIncluded;
    transportCost = obj.transportCost;

    return *this;
}

Tour::~Tour()
{
    delete[] name;
    delete[] destination;
}

void Tour::setName(const char* _name)
{
    delete[] name;
    int size = strlen(_name) + 1;
    name = new char[size];
    strcpy_s(name, size, _name);
}

void Tour::setDestination(const char* _destination)
{
    delete[] destination;

    int size = strlen(_destination) + 1;
    destination = new char[size];
    strcpy_s(destination, size, _destination);
}

void Tour::setDayPrice(float _price)
{
    dayPrice = _price;
}

void Tour::setDaysCount(int _count)
{
    daysCount = _count;
}

void Tour::setFoodIncluded(bool _food)
{
    foodIncluded = _food;
}

void Tour::setTransportCost(float _cost)
{
    transportCost = _cost;
}

const char* Tour::getName() const
{
    return name;
}

const char* Tour::getDestination() const 
{ 
    return destination;
}

float Tour::getDayPrice() const
{
    return dayPrice; 
}

int Tour::getDaysCount() const
{
    return daysCount;
}

bool Tour::isFoodIncluded() const
{
    return foodIncluded;
}

float Tour::getTransportCost() const
{ 
    return transportCost;
}

void Tour::showInfo() const
{
    cout << "Name: " << name << endl;
    cout << "Destination : " << destination << endl;
    cout << "Day price: " << dayPrice << " uah" << endl;
    cout << "Days: " << daysCount << endl;
    cout << "Food included: " << (foodIncluded ? "Yes" : "No") << endl;
    cout << "Transport cost: " << transportCost << " uah" << endl;
    cout << "====================================================" << endl;
}
