#ifndef _LINBCOINEXCHANGE_CONNECTION_H
#define _LINBCOINEXCHANGE_CONNECTION_H
#include <vector>
#include <string>

namespace coin {

    struct ticker {
        std::string ask;
        std::string bid;
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
        ticker get_quote(const std::string & prod);

    };
}

#endif