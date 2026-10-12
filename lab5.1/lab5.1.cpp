#include <iostream>
#include <cmath>


using  namespace std;

double g(const double a, const double b, const double c);

int main()
{
	double x, y;

	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	double z = ((g((x * y), pow(x, 2), pow(y, 2)) - (pow(g(1.0, x, y), 2))) / (1.0 + g(sqrt(x), pow(y, 2), 1.0)));

	cout << "z = " << z << endl;
	return 0;
}

double g(const double a, const double b, const double c)
{
	return (pow(a, 2) + pow(b, 2) - pow(c, 2));
}
