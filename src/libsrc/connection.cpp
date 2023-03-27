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
        
/*
        std::string ask;
        std::string bid;
        std::string volume;
        int32_t trade_id;
        std::string price;
        std::string size;
        std::string time;
    "ask": "27856.83",
    "bid": "27853.76",
    "volume": "10215.70314036",
    "trade_id": 514598501,
    "price": "27856.83",
    "size": "0.00535919",
    "time": "2023-03-27T02:33:01.821466Z"
}        */
        return t;
    }
    std::vector<std::string> connection::get_product()
    {
        std::vector<std::string> result(1, "BTC-USD");
        return result;
    }
}
