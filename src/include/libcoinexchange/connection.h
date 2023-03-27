#ifndef _LINBCOINEXCHANGE_CONNECTION_H
#define _LINBCOINEXCHANGE_CONNECTION_H
#include <vector>
#include <string>

namespace coin {

    struct ticker {
        double ask;
        double bid;
        double volume;
        int32_t trade_id;
        double price;
        double size;
        std::string time;
    };

    class connection {
        public:
        bool initialized();
        std::vector<std::string> get_product();


    };
}

#endif