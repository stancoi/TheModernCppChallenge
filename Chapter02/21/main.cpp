#ifdef _WIN32
#include <windows.h>
#else
using HANDLE = void*;
#endif
#include <iostream>
#include <vector>

void function_that_throws()
{
    throw std::runtime_error("an error has occurred");
}

void bad_handle_example()
{
    constexpr bool condition1 = false;
    constexpr bool condition2 = false;

    HANDLE handle = CreateFileW(L"sample.txt", GENERIC_READ, FILE_SHARE_READ,
                                nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
                                nullptr);

    if (INVALID_HANDLE_VALUE == handle)
        return;

    if (condition1)
    {
        CloseHandle(handle);
        return;
    }

    std::vector<char> buffer(1024);
    unsigned long bytesRead = 0;
    ReadFile(handle, buffer.data(), buffer.size(), &bytesRead, nullptr);

    if (condition2)
    {
        //oops, forgot to close handle
        return;
    }

    // throws exception; the next line will not execute
    function_that_throws();

    CloseHandle(handle);
}

void good_handle_example()
{}

int main()
{
    try
    {
        bad_handle_example();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        good_handle_example();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}