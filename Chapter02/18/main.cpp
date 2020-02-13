#include <iostream>
#include <functional>

template<typename T1, typename T2>
constexpr auto minimum(T1 const a, T2 const b)
{
    return a < b ? a : b;
}

template<typename T3, typename ...T>
constexpr auto minimum(T3 const a, T... args)
{
    return minimum(a, minimum(args...));
}

template<class Compare, typename T>
constexpr auto minimumc(Compare comp, T const a, T const b) { return comp(a, b) ? a : b; }

template<class Compare, typename T1, typename ...T>
constexpr auto minimumc(Compare comp, T1 const a, T... args)
{
    return minimumc(comp, a , minimumc(comp, args...));
}
int main()
{
    auto x = minimum(1,3,4,5);
    std::cout << x << '\n';

    auto y = minimumc(std::less<>(), 3, 2);
    std::cout << y << '\n';
    return 0;
}

