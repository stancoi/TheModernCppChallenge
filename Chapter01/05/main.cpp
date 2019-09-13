#include <iostream>

bool isPrime(unsigned int n)
{
    if (n <=1)
        return false;

    for (unsigned int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    int limit = 0;
    std::cout << "Enter limit: ";
    std::cin >> limit;

    for (int i = 2; i <= limit; ++i)
    {
        if (isPrime(i) && isPrime(i + 6))
        {
            std::cout << i << ',' << i+6 << '\n';
        }
    }
    return 0;
}
