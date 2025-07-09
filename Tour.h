#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Tour
{
    char* name;
    char* destination;
    float dayPrice;
    int daysCount;
    bool foodIncluded;
    float transportCost;
public:
    Tour();
    Tour(const char* _name, const char* _destination, float _dayPrice, int _daysCount, bool _foodIncluded, float _transportCost);
    Tour(const Tour& obj);
    Tour& operator=(const Tour& obj);
    ~Tour();

    void setName(const char* _name);
    void setDestination(const char* _destination);
    void setDayPrice(float _price);
    void setDaysCount(int _count);
    void setFoodIncluded(bool _food);
    void setTransportCost(float _cost);

    const char* getName() const;
    const char* getDestination() const;
    float getDayPrice() const;
    int getDaysCount() const;
    bool isFoodIncluded() const;
    float getTransportCost() const;

    void showInfo() const;
};
