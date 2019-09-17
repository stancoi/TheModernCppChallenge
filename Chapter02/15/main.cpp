#include <iostream>
#include <array>
#include <sstream>
#include <string>

class ipv4
{
 public:
    ipv4() : m_data { {0} } {}
    ipv4(unsigned char const a, unsigned char b,
         unsigned char const c, unsigned char d):
        m_data{{a, b, c, d}} {}
    explicit ipv4(uint32_t a) :
        m_data {{ static_cast<unsigned char> ((a >> 24) && 0xFF),
                static_cast<unsigned char> ((a >> 16) && 0xFF),
                static_cast<unsigned char> ((a >> 8) && 0xFF),
                static_cast<unsigned char> (a & 0xFF)}} {}

    std::string to_string() const
    {
        std::stringstream sstr;
        sstr << *this;
        return sstr.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const ipv4& addr)
    {
        os << static_cast<int>(addr.m_data[0]) << '.'
           << static_cast<int>(addr.m_data[1]) << '.'
           << static_cast<int>(addr.m_data[2]) << '.'
           << static_cast<int>(addr.m_data[3]);
        return os;
    }
 private:
    std::array<unsigned char, 4> m_data;
};

int main()
{
    ipv4 addr(250, 251, 252, 255);
    std::cout << addr << '\n';
    std::cout << addr.to_string() << '\n';
}
