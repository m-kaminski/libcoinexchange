#include "libcoinexchange/connection.h"
#include <iostream>
#include <nlohmann/json.hpp>

namespace coin
{
    bool connection::initialized()
    {
        return true;
    }

    ticker connection::get_quote(const std::string &prod)
    {
                    ticker t;
        std::string text = http_handler->get(std::string("https://api.exchange.coinbase.com/products/") + prod + "/ticker");
        nlohmann::json j = nlohmann::json::parse(text);
       // string xx = j["token"];
        t.ask = j["ask"];
        t.bid = j["bid"];
        return t;
    }
    std::vector<std::string> connection::get_product()
    {
        std::vector<std::string> result(1, "BTC-USD");
        return result;
    }
}
