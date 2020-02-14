#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <array>

template<class C, class T>
auto contains(C const & c, T const & value)
{
    return std::end(c) != std::find(std::begin(c), std::end(c), value);
}

template<class C, class ...T>
auto contains_any(C const & c, T&&... value)
{
    return (... || contains(c, value));
}

template<class C, class ...T>
auto constains_all(C const & c, T&&... value)
{
    return (... && contains(c, value));
}

template<class C, class ...T>
auto contains_none(C const & c, T&&... value)
{
    return !contains_any(c, std::forward<T>(value)...);
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::array<int, 4> a{1, 2, 3, 4};

    assert(contains(v, 3));
    assert(contains_any(v, 2, 3, 4));
    assert(constains_all(v, 1, 2, 3, 4, 5));

    assert(contains(a, 4));
}

