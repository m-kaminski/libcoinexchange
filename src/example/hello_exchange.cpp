#include "libcoinexchange/connect_exchange.h"
#include <iostream>
#include <iterator>

int main() {
    auto conn = coin::connect_exchange();
    if (conn->initialized()) {
        std::cout << "Hello exchange\ntrading pairs:" << std::endl;
        auto p = conn->get_product();
        std::copy(p.begin(), p.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        conn->get_quote("BTC-USD");
    }

    return 0;   
}