
#include "list.h"
#include "Header.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List list;
    char sym;
    char add_sym;
    int menu = 0;

    do {

        cout << "Виберіть пункт меню:" << endl << "1)Додати елементи до списку з масиву(що задано в коді)" << endl << "2)Ввести елементи вручну" << endl;
        cout << "3)Порівняти 2 списки" << endl << "4)Видалити елементи з початку списку" << endl << "5)Видалити певний символ" << endl;
        cout << "6)Скопіювати список та вивести скопійований" << endl << "7)Додати елементи за допомогою перевантаженої опе-ції + " << endl << "8)Вивести список та його розмір" << endl;
        cout << "9)Завершити програму" << endl;

        cin >> menu;
        if (menu < 0 || menu >9)
        {
            cout << "bad" << endl;
            return 0;
        }

        if (menu == 1)
        {
            char mas[] = { 'a','b','c','d' };
            list.MassiveAdd(mas);
            cout << "Додано!" << endl;
        }


        else if (menu == 2)
        {
            cout << "Введіть символ: ";
            list.Input();
            cout << "Done!" << endl;
        }

        else  if (menu == 3)
        {

            char array[] = "abcdы";
            List list_second(array, strlen(array));
            bool check = (list == list_second);

            if (check == true)
            {
                cout << "Списки рівні " << endl;
            }
            cout << "Done!" << endl;
        }
        else  if (menu == 4) {
            cout << "Скільки ел-тів ви хочете видалити" << endl;
            int delc;
            cin >> delc;
            if (delc >= list.GetSize())
            {

                cout << "Недопустима к-сть елементів" << endl;
                return 0;

            }

            for (int j = 0; j < delc; j++)
            {
                list.DeleteFirst();
            }
            cout << "Done!" << endl;
        }
        else if (menu == 5)
        {
            cout << "Введіть символ: ";
            cin >> sym;
            list - sym;
            cout << "Done!" << endl;
        }

        else  if (menu == 6)
        {
            List copy_list(list);
            cout << "Список скопійований" << endl;
            for (int i = 0; i < copy_list.GetSize(); i++)
            {
                cout << copy_list[i] << endl;
        
            }
            cout << "Done!" << endl;
        }

        else   if (menu == 7)
        {
            cout << "Введіть символ: ";
            cin >> add_sym;
            list + add_sym;
            cout << "Done!" << endl;
        }
        else   if (menu == 8)
        {
            cout << "Довжина списку:" << list.GetSize() << endl;
            for (int i = 0; i < list.GetSize(); i++)
            {
                cout << list[i] << endl;
            }
            cout << "Done!" << endl;

        }
        else    if (menu == 9)
        {
            return 0;
        }

    } while (menu != 9);
    
        
    return 0;
}
