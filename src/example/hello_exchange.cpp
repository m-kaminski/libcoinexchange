#include "libcoinexchange/connect_exchange.h"
#include <iostream>


int main() {
    auto connected = coin::connect_exchange();
    if (connected) {
        std::cout << "Hello exchange" << std::endl;
    }

    return 0;   
}