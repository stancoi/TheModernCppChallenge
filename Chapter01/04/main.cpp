#include <iostream>

static bool isPrime(unsigned int n)
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
    unsigned int limit = 0;
    std::cout << "Enter limit: ";
    std::cin >> limit;

    for (unsigned int i = limit; i > 1; i--)
    {
        if (isPrime(i))
        {
            std::cout << "Largest prime:" << i << '\n';
            return 0;
        }
    }
    return 0;
}
