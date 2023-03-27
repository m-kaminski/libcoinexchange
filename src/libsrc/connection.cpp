#include <cpr/cpr.h>
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
        cpr::Response r = cpr::Get(cpr::Url{std::string("https://api.exchange.coinbase.com/products/")+prod+"/ticker"});
        
        ticker t;
        r.status_code;            
        // assume code is 200 for now
        std::cout << r.status_code << std::endl;
        std::cout << r.text << std::endl;
        nlohmann::json j = nlohmann::json::parse(r.text);
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
