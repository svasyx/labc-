#include "Region.h"
#include "List.h"
#include "Place.h"
#include "Node.h"
#include "Header.h"

ostream& operator<<(std::ostream& out, const Place& object)
{
    return out << object._country << " " << object._name << " " << object._population << endl;
}
istream& operator>>(std::istream& in, Place& object)
{
    in >> object._country >> object._name >> object._population;
    if (!in)
    {
        object = Place();
    }
    return in;
}

bool action_pop(Place object, int pop)
{
    if (object.GetPop() == pop)
    {
        return 1;
    }
    return 0;
}

bool action_pop1(Place object, int pop)
{
    if (object.GetPop() >= pop)
    {
        return 1;
    }
    return 0;
}

bool action_country(Place object, string country)
{
    if (object.GetCountry() == country)
    {
        return 1;
    }
    return 0;
}

bool action_name(Place object, string name)
{
    if (object.GetName() == name)
    {
        return 1;
    }
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int option = 0;
    int pop = 0;
    int check = 0;
    string name;
    string country;
    Place c;

    Region rg;

    do {
        cout << "1.Створити об'єкт класу" << endl;
        cout << "2.Показати загальну кількість населення в області" << endl;
        cout << "3.Додати населений пункт до бази даних" << endl;
        cout << "4.Видалити НП(країна, назва, населення)" << endl;
        cout << "5.Вивести дані" << endl;
        cout << "6.Скопіювати дані та вивести їх" << endl;
        cout << "7.Вивести кількість НП із заданим населенням" << endl;
        cout << "8.Вивести НП із заданою країною" << endl;
        cout << "9.Вивести НП із заданою назвою" << endl;
        cout << "10.Завершити роботу програми" << endl;
        do {
            cin >> option;
            if (option <= 0 || option >= 11) {
                cout << "Значення невірне, введіть ще раз: ";
            }
        } while (option <= 0 || option >= 11);
        cout << endl;
        switch (option)
        {
        case 1:
            cout << "Введіть дані(країна, назва, населення) через пробіл: ";
            cin >> c;
            rg + c;
            cout << "Створено!" << endl << endl;
            break;
        case 2:
            cout << "Загальна кількість населення:" << rg.GetAmount() << endl << endl;
            break;
        case 3:
            cout << "Введіть НП, який додати(країна, назва, населення) через пробіл: ";
            cin >> c;
            rg + c;
            cout << "Додано!" << endl;
            break;
        case 4:
            cout << "Введіть НП, який видалити(країна, назва, населення) через пробіл: ";
            cin >> c;
            rg - c;
            cout << "Видалено!" << endl;
            break;
        case 5:
            cout << "НП: " << endl;
            cout << endl << "К-сть населених пунктів: " << rg.GetCount() << endl;
            rg.Print();

            cout << endl;
            break;
        case 7:
        {
            cout << "Введіть населення: " << endl;
            cin >> pop;
            List tmp = rg.Iterator_pop(action_pop, pop);

            for (int i = 0; i < tmp.GetSize(); i++)
            {
                cout << tmp[i] << endl;
            }

            break;
        }
        case 8:
        {
            cout << "Введіть країну: " << endl;
            cin >> country;
            List tmp = rg.Iterator_str(action_country, country);

            for (int i = 0; i < tmp.GetSize(); i++)
            {
                cout << tmp[i] << endl;
            }
            break;
        }
        case 9:
        {
            cout << "Введіть назву: " << endl;
            cin >> name;
            List tmp = rg.Iterator_str(action_name, name);
            for (int i = 0; i < tmp.GetSize(); i++)
            {
                cout << tmp[i] << endl;
            }
            break;
        }
        }
        if (option == 6)
        {
            Region region_tmp(rg);
            cout << "НП: " << endl;
            region_tmp.Print();
            cout << endl;
        }
    } while (option != 10);

    return 0;
}

