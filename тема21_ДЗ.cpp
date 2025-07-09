#include <iostream>
#include <windows.h>
#include "TouristAgency.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TouristAgency agency("TOP TRAVEL");
    int choice;

    while (true)
    {
        cout << "\n------- Меню -------\n";
        cout << "1. Додати тур\n";
        cout << "2. Показати всі тури\n";
        cout << "3. Видалити тур за назвою\n";
        cout << "4. Пошук туру за напрямком (країна/місто)\n";
        cout << "5. Сортування за напрямком\n";
        cout << "6. Сортування за вартістю проїзду\n";
        cout << "0. Вихід\n";
        cout << "Оберіть пункт: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0)
        {
            break;
        }

        if (choice == 1)
        {
            char name[50];
            char destination[50];
            float dayPrice;
            float transportCost;
            int days;
            bool food;

            cout << "Назва туру: ";
            cin.getline(name, 50);
            cout << "Напрямок : ";
            cin.getline(destination, 50);
            cout << "Ціна за 1 день: ";
            cin >> dayPrice;
            cout << "Кількість днів: ";
            cin >> days;
            cout << "Чи входить харчування (1 - так / 0 - ні): ";
            cin >> food;
            cout << "Вартість проїзду: ";
            cin >> transportCost;
            cin.ignore();

            agency.addTour(Tour(name, destination, dayPrice, days, food, transportCost));
        }
        else if (choice == 2)
        {
            agency.showInfo();
        }
        else if (choice == 3)
        {
            char name[50];
            cout << "Введіть назву туру для видалення: ";
            cin.getline(name, 50);
            agency.removeTourByName(name);
        }
        else if (choice == 4)
        {
            char dest[50];
            cout << "Введіть країну або місто: ";
            cin.getline(dest, 50);
            agency.searchByDestination(dest);
        }
        else if (choice == 5)
        {
            agency.sortByDestination();
            cout << "Відсортовано! \n";
        }
        else if (choice == 6)
        {
            agency.sortByTransportCost();
            cout << "Відсортовано! \n";
        }
        else
        {
            cout << "error\n";
        }

    }
    return 0;
}
