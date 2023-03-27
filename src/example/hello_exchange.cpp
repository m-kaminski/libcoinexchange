#include "libcoinexchange/connection_factory.h"
#include <iostream>
#include <iterator>

int main() {
    auto conn = coin::connection_factory::connect_exchange();
    if (conn->initialized()) {
        std::cout << "Hello exchange\ntrading pairs:" << std::endl;
        auto p = conn->get_product();
        std::copy(p.begin(), p.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        auto q = conn->get_quote("BTC-USD");
        std::cout << "BID/ASK" << q.bid << "/" << q.ask << std::endl;
    }

    return 0;   
}