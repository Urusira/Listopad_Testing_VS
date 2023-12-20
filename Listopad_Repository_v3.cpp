#include <iostream>
#include <cmath>

using namespace std;

int EnterNumber(int num_a)
{
    cout << "\nPlease, enter A: ";
    cin >> num_a;
    return num_a;
}

void CalcArea(int num_a)
{
    if (num_a > 0)
    {
        cout << "\nArea of an equilateral triangle with side A: " << (((num_a * num_a) * sqrt(3)) / 4) << endl;
    }
    else
    {
        cout << "\nError; enter correct A (side of triangle)";
    }
}

void CalcPerim(int num_a)
{
    cout << "\nPerimeter of an equilateral triangle with side A: " << num_a * 3 << endl;
}

int main()
{
    int funcSelect = 0, num_a = 0;
    for (;;)
    {
        cout << "\n1. Enter a number A (side of equilateral triangle)";
        cout << "\n2. Calculate the area of an equilateral triangle with side A";
        cout << "\n3. Calculate the perimeter of an equilateral triangle with side A" << endl;
        cout << "Please enter the number of the desired function or 0 if you want to close the app: ";
        cin >> funcSelect;
        switch (funcSelect)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                num_a = EnterNumber(num_a);
                break;
            }
            case 2:
            {
                CalcArea(num_a);
                break;
            }
            case 3:
            {
                CalcPerim(num_a);
                break;
            }
            default:
            {
                cout << "\nInvalid input. Please try again." << endl;
                break;
            }
        }
    }
}

