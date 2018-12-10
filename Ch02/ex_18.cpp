#include "../std_lib_facilities.h"

double discr(double a, double b, double c)
{
    return b*b - 4*a*c;
}

int main()
{
    int a, b, c;
    cout << "Решить уравнение вида ax^2 + bx + c = 0" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    
    double d = discr(a, b, c);
    if (a == 0) {
        cout << "Уравнение линейное. Корень: " << -c / b << endl;
    }
    else if (d > 0) {
        double x1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
        double x2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
        cout << "Уравнение имеет 2 корня: " << x1 << " и " << x2 << endl;
    }
    else if (d == 0) {
        cout << "Уравнение имеет один корень: " << -b / (2*a) << endl;
    }
    else {
        cout << "Уравнение не имеет корней" << endl;
    }
    
    return 0;
}