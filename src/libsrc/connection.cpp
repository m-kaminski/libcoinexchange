#include "libcoinexchange/connection.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <charconv>
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
        
        auto stod = [] (std::string s) {
            auto point =  s.find_first_of('.');
            uint64_t result_whole;
            uint64_t result_decimal;
            
            std::from_chars(s.data()+point+1, s.data()+s.size(), result_decimal);
            std::from_chars(s.data(), s.data()+point, result_whole);
            return 10000*result_whole + result_decimal*100;
        };
        t.ask = stod(j["ask"]);
        t.bid = stod(j["bid"]);
        return t;
    }

    std::vector<std::string> connection::get_product()
    {
        std::vector<std::string> result(1, "BTC-USD");
        return result;
    }
}
