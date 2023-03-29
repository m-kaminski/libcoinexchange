#include "libcoinexchange/connection_factory.h"
#include <iostream>
#include <iterator>

int main() {
    auto conn = coin::connection_factory::connect_exchange();
    if (conn->initialized()) {
        std::cout << "Hello exchange\ntrading pairs:" << std::endl;
        auto pv = conn->get_products();

        for (auto & p : pv) {
            std::cout << p.id << std::endl;
        }
        auto q = conn->get_quote("BTC-USD");
        std::cout << "BID/ASK" << q.bid << "/" << q.ask << std::endl;
    }

    return 0;   
}