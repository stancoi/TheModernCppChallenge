#include <iostream>

static unsigned int gcd_euclid(unsigned int const a, unsigned int const b)
{
    return b == 0 ? a : gcd_euclid(b, a % b);
}

static unsigned int gcd_euclid2(unsigned int const a, unsigned int const b)
{
    if (a == b)
    {
        return a;
    }
    else if (a > b)
    {
        return gcd_euclid2(a - b, b);
    }
    else
    {
        return gcd_euclid2(a, b - a);
    }
}
int main()
{
    std::cout << "Input numbers: ";
    unsigned int a, b;
    std::cin >> a >> b;

    std::cout << "gcd1(" << a << "," << b << ")=" << gcd_euclid(a, b) << '\n';
    std::cout << "gcd2(" << a << "," << b << ")=" << gcd_euclid2(a, b) << '\n';
    return 0;
}
