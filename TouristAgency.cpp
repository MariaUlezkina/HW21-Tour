#include "TouristAgency.h"
#include <cstring>

const char* g_removalName = nullptr;

bool compareTourByName(Tour t)
{
    return strcmp(t.getName(), g_removalName) == 0;
}


TouristAgency::TouristAgency()
{
    name = new char[10] {"no"};

    sizeTour = 0;
    arrTour = nullptr;
}

TouristAgency::TouristAgency(const char* _name)
{
    int size = strlen(_name) + 1;
    name = new char[size];
    strcpy_s(name, size, _name);
    sizeTour = 0;
    arrTour = nullptr;

}

TouristAgency::~TouristAgency()
{
    delete[] name;
    if (sizeTour > 0) delete[] arrTour;
}

void TouristAgency::addTour(Tour obj)
{
    addItemBack(arrTour, sizeTour, obj);
}

void TouristAgency::showInfo() const
{
    cout << "Travel agency name:: " << name << endl;
    cout << "Amount of tours: " << sizeTour << endl;

    for (int i = 0; i < sizeTour; i++)
    {
        arrTour[i].showInfo();
    }
}

void TouristAgency::removeTourByName(const char* _name)
{
    g_removalName = _name;
    myRemoveIf(arrTour, sizeTour, compareTourByName);
}

void TouristAgency::searchByDestination(const char* _dest) const
{
    bool found = false;

    for (int i = 0; i < sizeTour; i++)
    {
        if (strcmp(arrTour[i].getDestination(), _dest) == 0)
        {
            arrTour[i].showInfo();
            found = true;
        }
    }

    if (!found) cout << "No tours found(( : " << _dest << endl;
}

void TouristAgency::sortByDestination()
{
    sort_if<Tour>(arrTour, sizeTour, [](Tour left, Tour right)
        {
            return strcmp(left.getDestination(), right.getDestination()) > 0;
        });
}

void TouristAgency::sortByTransportCost()
{
    sort_if<Tour>(arrTour, sizeTour, [](Tour left, Tour right)
        {
            return left.getTransportCost() > right.getTransportCost();
        });
}
