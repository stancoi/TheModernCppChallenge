#include <iostream>

int main()
{
    unsigned long long sum = 0;
    unsigned long limit;
    std::cout << "Enter limit: ";
    std::cin >> limit;
    for (unsigned int i = 3; i < limit; ++i)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }
    std::cout << "Sum: " << sum << '\n';
    return 0;
}
