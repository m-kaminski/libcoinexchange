#include "libcoinexchange/connect_exchange.h"
#include <iostream>
#include <iterator>

int main() {
    auto connected = coin::connect_exchange();
    if (connected->initialized()) {
        std::cout << "Hello exchange\ntrading pairs:" << std::endl;
        auto p = connected->get_product();
        std::copy(p.begin(), p.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    }

    return 0;   
}