#include "plotter.hpp"

#include <cstdlib>
#include <exception>
#include <format>
#include <iostream>
#include <stdexcept>
#include <string>

namespace detail
{
auto create_plotter_from_user_input()
{
    std::cout << "Enter a natural number range, example: 1 100:\n";
    int32_t begin;
    int32_t end;
    std::cin >> begin >> end;
    if(begin > end)
    {
        throw std::invalid_argument(std::format("Invalid arguments, begin {} must be smaller than end {}", begin, end));
    }
    if(begin < 0)
    {
        throw std::invalid_argument(std::format("Supports only positive range. Received negative begin {}", begin));
    }
    std::cout << "Save figures? [y/n]\n";
    char save;
    std::cin >> save;
    auto save_figures = save == 'y';
    return plotter::plot_natural_numbers{ begin, end, save_figures };
}
} // namespace detail

int main()
{
    std::cout << "Creating a polar plot of primes\n";
    try
    {
        auto plotter = detail::create_plotter_from_user_input();
        plotter.plot_all_natural_numbers();
        plotter.plot_all_prime_numbers();
    }
    catch(std::exception& exception)
    {
        std::cerr << std::format("Exception: {}, exiting program\n", exception.what());
        return EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << "Caught unknown exception\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
