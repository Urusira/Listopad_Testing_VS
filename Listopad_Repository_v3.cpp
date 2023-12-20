#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Проверка правильности введённой стороны треугольника
bool InputCheck(int num_a)
{
    if (num_a == NULL)
        return false;

    try {
        if (num_a <= 0) 
            return false;
    }
    catch (...) {
        return false;
    }

    return true;
}

// Проверка выбранного пункта меню, не выходит ли за пределы предложенных
bool MenuChecker(int funcSelect) {
    try {
        if (funcSelect < 0 || funcSelect > 3)
            return false;
    }
    catch (...) {
        return false;
    }
    
    return true;
}

// Функция для вывода пунктов меню
void MenuPointsCout() {
    cout << "\n1. Enter a number A (side of equilateral triangle)";
    cout << "\n2. Calculate the area of an equilateral triangle with side A";
    cout << "\n3. Calculate the perimeter of an equilateral triangle with side A" << endl;
    cout << "Please enter the number of the desired function or 0 if you want to close the app: ";
    return;
}

// Функция рассчёта площади треугольника
double CalcArea(int num_a)
{
    return (((num_a * num_a) * sqrt(3)) / 4);
}

// Функция рассчёта периметра треугольника
double CalcPerim(int num_a)
{
    return (num_a * 3);
}

int main()
{
    int funcSelect = 0, num_a = 0; // Инициализация переменной для выбора пункта меню и переменной - длины стороны треугольника
    for (;;)
    {
        MenuPointsCout();// Вывод пунктов меню
        cin >> funcSelect;// Ввод желаемого пунка

        // В цикле проверяем корректность ввода пункта
        while (!MenuChecker(funcSelect)) {
            MenuPointsCout();
            cin >> funcSelect;
        }

        // С свиче выбираем пункт
        switch (funcSelect)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                cout << "\nPlease, enter A: "; // "Пожалуйста, введите А"
                cin >> num_a; // Ввод переменной - стороны треугольника

                // В цикле проверяем корректность ввода
                while (!InputCheck(num_a))
                {
                    cout << "\nPlease, enter A: ";
                    cin >> num_a;
                }
                break;
            }
            case 2:
            {
                // Если сторона не была введена, просим её ввести и блокируем проход дальше
                if (!num_a) {
                    cout << "\nYou need enter the A!\n"; // "Вам нужно ввести А!"
                    break;
                }
                cout << "\nArea of an equilateral triangle with side A: " << CalcArea(num_a) << endl; // Выводм результат рассчёта площади треугольника
                break;
            }
            case 3:
            {
                // Если сторона не была введена, просим её ввести и блокируем проход дальше
                if (!num_a) {
                    cout << "\nYou need enter the A!\n"; // "Вам нужно ввести А!"
                    break;
                }
                cout << "\nPerimeter of an equilateral triangle with side A: " << CalcPerim(num_a) << endl; // Выводм результат рассчёта периметра треугольника
                break;
            }
            default:
            {
                cout << "\nHOW YOU DO THIS?!?!?!?!?" << endl;   // Я реально не понимаю, как ты умудрился получить такой сценарий свича...
                break;
            }
        }
    }
}

