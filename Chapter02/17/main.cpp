#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template <class T, std::size_t R, std::size_t C>
class array2d
{
    typedef T                   value_type;
    typedef value_type*         iterator;
    typedef value_type const *  const_iterator;
    typedef value_type&         reference;
    typedef const value_type&   const_reference;

    std::vector<value_type> arr;
public:
    // Constructors
    array2d() : arr(R * C) {}
    explicit array2d(std::initializer_list<value_type> l) : arr(l) {}
    // Element access
    constexpr T* data() noexcept { return arr.data(); }
    constexpr T const * data() const noexcept { return arr.data(); }

    constexpr T& at(std::size_t const r, std::size_t const c)
    {
        return arr.at(r*C + c);
    }

    constexpr T const & at(std::size_t const r, std::size_t const c) const
    {
        return arr.at(r*C + c);
    }

    constexpr T& operator() (std::size_t const r, std::size_t const c)
    {
        return arr[r*C + c];
    }
    constexpr T const & operator() (std::size_t const r, std::size_t const c) const
    {
        return arr[r*C + c];
    }

    // Element manipulation members
    void fill(const value_type& value)
    {
        std::fill(std::begin(arr), std::end(arr), value);
    }

    void swap(array2d& other)
    {
        arr.swap(other.arr);
    }

    //
    constexpr std::size_t size(int const rank) const
    {
        if (1 == rank) return R;
        else if (2 == rank) return C;
        throw std::out_of_range("Rank is out of range!");
    }

    // Iterator members
    iterator        begin ()        { return arr.data(); }
    iterator        end   ()        { return arr.data() + arr.size(); }
    const_iterator  begin () const  { return arr.data(); }
    const_iterator  end   () const  { return arr.data() + arr.size(); }
};
int main()
{
    // Element access
    array2d<std::size_t, 2, 3> a {1, 2, 3, 4, 5, 6};
    for (std::size_t i = 0; i < a.size(1); ++i)
    {
        for (std::size_t j = 0; j < a.size(2); ++j)
        {
            a(i, j) *= 2;
        }
    }

    //iterating
    std::cout << "test iterators\n";
    for (auto const e : a)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    std::copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    //filling
    array2d<std::size_t, 2, 3> b;
    b.fill(1);

    //swapping
    a.swap(b);

    //moving
    array2d<std::size_t, 2, 3> c(std::move(b));
    return 0;
}