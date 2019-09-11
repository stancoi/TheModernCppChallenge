#include <iostream>
#include <vector>
#include <numeric>

unsigned int gcd_euclid (unsigned int const a, unsigned int const b)
{
    return b == 0 ? a : gcd_euclid(b, a % b);
}

unsigned int lcm (unsigned int const a, unsigned int const b)
{
    unsigned int h = gcd_euclid(a, b);
    return h ? (a * (b / h)) : 0;
}

template<class InputIt>
int lcmr(InputIt first, InputIt last)
{
    return std::accumulate(first, last, 1, lcm);
}

int main()
{
    unsigned int count = 0;
    std::cout << "Input count:";
    std::cin >> count;

    std::vector <unsigned int> number;
    for (unsigned int i = 0; i < count; ++i)
    {
        unsigned int v{0};
        std::cout << "Input element:";
        std::cin >> v;
        number.push_back(v);
    }

    std::cout << "lcm = " << lcmr(std::begin(number), std::end(number)) << '\n';
    return 0;
}
