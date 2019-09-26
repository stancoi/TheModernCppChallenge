#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <numeric>
#include <assert.h>

bool validate_isbn_10(std::string_view isbn)
{
    auto valid = false;

    if (isbn.size() == 10 && std::count_if(isbn.cbegin(), isbn.cend(), isdigit) == 10)
    {
        auto sum = 0;
        auto weight = 10;
        for (auto it = isbn.begin(); it != isbn.end(); ++it)
        {
            sum += (*it - '0') * weight;
            weight--;
        }
        
        valid = !(sum % 11);
    }
    return valid;
}

bool validate_isbn_10_lambda(std::string_view isbn)
{
    auto valid = false;

    if (isbn.size() == 10 && std::count_if(isbn.cbegin(), isbn.cend(), isdigit) == 10)
    {
        auto weight = 10;
        auto sum = std::accumulate(isbn.begin(), isbn.end(), 0,
        [&weight](int const total, char const c)
        {
            return total + weight-- * (c - '0');
        }
        );
        valid = !(sum % 11);
    }
    return valid;
}
int main()
{
    std::string isbn;
    std::cout << "Enter ISBN number:";
    std::cin >> isbn;

    std::cout << "valid: " << validate_isbn_10(isbn) << '\n';
    std::cout << "valid: " << validate_isbn_10_lambda(isbn) << '\n';
    return 0;
}
