#ifdef _WIN32
#include <windows.h>
#else
using HANDLE = void*;
constexpr unsigned long GENERIC_READ             = 0x80000000L;
constexpr unsigned long GENERIC_WRITE            = 0x40000000L;
constexpr unsigned long CREATE_NEW               = 1;
constexpr unsigned long CREATE_ALWAYS            = 2;
constexpr unsigned long OPEN_EXISTING            = 3;
constexpr unsigned long OPEN_ALWAYS              = 4;
constexpr unsigned long TRUNCATE_EXISTING        = 5;
constexpr unsigned long FILE_SHARE_READ          = 1;
constexpr unsigned long FILE_ATTRIBUTE_NORMAL    = 0x00000080;

constexpr long long INVALID_HANDLE_VALUE = -1;

int CloseHandle(HANDLE hObject) {return 0;}

HANDLE CreateFileW(char const *, unsigned long, unsigned long, void*,
                    unsigned long, unsigned long, HANDLE)
{
    return INVALID_HANDLE_VALUE;
}

int ReadFile(HANDLE, void*, unsigned long, unsigned long, void*)
{
    return 0;
}
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