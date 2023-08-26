#pragma once

#include <matplot/matplot.h>

#include <array>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <format>
#include <numeric>
#include <ranges>
#include <string_view>
#include <vector>

namespace plotter
{
namespace detail
{
template<std::integral number_t>
bool is_prime(const number_t number, const std::vector<double>& primes_so_far)
{
    if(number == 1)
    {
        return false;
    }
    for(const auto& prime : primes_so_far)
    {
        if(prime * prime > number)
        {
            // no prime divisor between 2...sqrt(number)
            return true;
        }
        if(number % static_cast<number_t>(prime) == 0)
        {
            return false;
        }
    }
    return true;
}

inline void plot_values(const std::vector<double>& radius, const std::vector<double>& angle, std::string_view title)
{
    auto figure = matplot::figure();
    auto axes = figure->current_axes();
    auto plot = matplot::polarscatter(axes, angle, radius, "filled");
    axes->color(matplot::color::black);
    axes->r_axis().tick_values({});
    axes->t_axis().tick_values({});
    axes->box(false);
    plot->marker_color(matplot::color::green);
    axes->title(title);
    axes->title_color(matplot::to_array(matplot::color::white));
    matplot::show();
}
} // namespace detail

template<std::integral number_t>
class plot_natural_numbers
{
public:
    explicit plot_natural_numbers(const number_t begin, const number_t end, const bool save)
        : m_number_range{ begin, end }, m_save{save}
    {}

    void plot_all_natural_numbers() const
    {
        const auto [number_begin, number_end] = m_number_range;
        auto radius = matplot::iota(number_begin, number_end);
        auto angle = matplot::iota(number_begin, number_end);

        detail::plot_values(radius, angle, std::format("Natural numbers {}:{}", number_begin, number_end));
        if (m_save)
        {
            matplot::save("img/all_natural_numbers.svg");
        }
    }

    void plot_all_prime_numbers() const
    {
        const auto [number_begin, number_end] = m_number_range;
        std::vector<double> radius;
        radius.reserve(number_end);
        std::vector<double> angle;
        angle.reserve(number_end);
        for(const auto number : std::views::iota(number_begin, number_end))
        {
            if(detail::is_prime(number, radius))
            {
                radius.push_back(number);
                angle.push_back(number);
            }
        }
        radius.shrink_to_fit();
        angle.shrink_to_fit();
        detail::plot_values(radius, angle, std::format("Prime numbers {}:{}", number_begin, number_end));
        if (m_save)
        {
            matplot::save("img/prime_numbers.svg");
        }
    }

private:
    std::array<number_t, 2> m_number_range;
    bool m_save;
};
} // namespace plotter