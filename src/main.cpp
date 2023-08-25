#include "matplot/freestanding/plot.h"
#include "matplot/util/colors.h"
#include "matplot/util/common.h"
#include <matplot/freestanding/axes_functions.h>
#include <matplot/util/keywords.h>
#include <matplot/matplot.h>

#include <cmath>
#include <iostream>

int main()
{
    std::cout << "Creating a polar plot of primes\n";
    using namespace matplot;

    std::vector<double> rho = iota(1, 100);
    std::vector<double> theta = rho;
    
    auto ps = polarscatter(theta, rho, "filled");
    gca()->color(color::black);
    gca()->r_axis().tick_values({});
    gca()->t_axis().tick_values({});
    gca()->box(false);
    ps->marker_color(color::green);

    show();
    return 0;
}
