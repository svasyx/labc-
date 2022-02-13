#include "Place.h"
#include "List.h"
#include "Header.h"
#include "Megapolis.h"
#include "Vilage.h"
#include "City.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    City obj("Україна", "Київ", 100000, 51);

    Place** places = new Place * []
    {
            new City("Чехія", "Прага", 150000, 121),
            new Vilage("Україна", "Козинці", 200, 22),
            new Megapolis("Японія", "Токіо", 30000000, 20),
            new City("Італія", "Рим", 150000, 121)

    };

    List list;
    list + places[0];
    list + places[1];
    list + places[2];
    list + places[3];
    list + &obj;

    list.Print();

    list - places[2];
    list - &obj;


    cout << endl;

    list.Print();

    return 0;
}

