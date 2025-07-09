#pragma once
#include "Tour.h"
#include "Array_Template.h"

class TouristAgency
{
    char* name;
    int sizeTour;
    Tour* arrTour;
public:
    TouristAgency();
    TouristAgency(const char* _name);
    ~TouristAgency();

    void addTour(Tour obj);
    void showInfo() const;
    void removeTourByName(const char* _name);
    void searchByDestination(const char* _dest) const;

    void sortByDestination();
    void sortByTransportCost();
};
