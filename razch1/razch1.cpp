#include <iostream>
#include <bitset>
using namespace std;
unsigned int z1(unsigned int n, unsigned int mask);
unsigned int z2(unsigned int num, unsigned int mask);
unsigned int z3(unsigned int num);
unsigned int z4(unsigned int num);
unsigned int z5(unsigned int num, unsigned int n, unsigned int mask);
void coutp(unsigned int x)
{
    int n = sizeof(int) * 8;
    unsigned  maska = (1 << (n - 1));

    for (int i = 1; i <= n; i++)
    {
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1;
    }
}

int main() {
    cout << "Choose task (1-5): ";
    unsigned int task, num, n, mask, result;
    num = 1;
    cin.unsetf(ios::dec);
    cin.setf(ios::hex);
    cin >> task;
    if (task > 0 and task < 6){
        cout << "Enter number (hex): ";
        cin >> num;
        cout << "Binary number is ";
        coutp(num);
        cout << "\n";
    }
    switch (task) {
    case 1:
        mask = 0b101000000000000010;
        result = z1(num, mask);
        cout << "\nBinary mask is ";
        coutp(mask);
        cout << "\n";
        break;
    case 2:
        mask = 0b111000;
        result = z2(num, mask);
        cout << "\nBinary mask is ";
        coutp(mask);
        cout << "\n";
        break;
    case 3:
        result = z3(num);
        break;
    case 4:
        result = z4(num);
        break;
    case 5:
        cout << "n = ";
        cin >> n;
        mask = 0b10000000000000000000000000000000;
        result = z5(num, n, mask);
        cout << "\nBinary mask is ";
        coutp(mask); 
        cout << "\n";
        break;
    default:
        return 0;
    }
    cout << "\nDecimal result is " << result << "\n";
    cout << "Binary result is ";
    coutp(result);
    cout << "\n\n";
    return main();
}

/*
Определить переменную целого типа, присвоить ей значение, 
используя константу в шестнадцатеричной системе счисления.
Разработать функцию, которое установит заданные в задании 
биты исходного значения переменной в значение 1, используя 
соответствующую маску и поразрядную операцию.
*/
unsigned int z1(unsigned int num, unsigned int mask) {
    return num | mask;
}

/*
Разработать функцию, которая обнуляет заданные в задании 
биты исходного значения целочисленной переменной, введенной 
пользователем, используя соответствующую маску и поразрядную операцию.
*/
unsigned int z2(unsigned int num, unsigned int mask) {
    return num & ~mask;
}

/*
Разработать функцию, которая умножает значение целочисленной переменной, 
введенной пользователем, на множитель, используя соответствующую поразрядную операцию.
*/
unsigned int z3(unsigned int num) {
    return num << 6;
}

/*
Разработать функцию, которая делит значение целочисленной переменной, 
введенной пользователем, на делитель, используя соответствующую поразрядную операцию.
*/
unsigned int z4(unsigned int num) {
    return num >> 6;
}

/*
Разработать функцию, реализующую задание, в которой используются только 
поразрядные операции. В выражении используется маска – переменная. Маска 
инициализируется единицей в младшем разряде (маска 1) или единицей в 
старшем разряде (маска 2). Изменяемое число и n вводится с клавиатуры.
*/
unsigned int z5(unsigned int num, unsigned int n,  unsigned int mask) {
    mask = mask >> 31 << n;
    return num & ~mask;
}
