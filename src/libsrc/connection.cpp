#include <cpr/cpr.h>
#include "libcoinexchange/connection.h"
#include <iostream>

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

        r.status_code;            // 200
        r.header["content-type"]; // application/json; charset=utf-8
        r.text;                   // JSON text string
        std::cout << r.status_code << std::endl;
        std::cout << r.text << std::endl;
        return t;
    }
    std::vector<std::string> connection::get_product()
    {
        std::vector<std::string> result(1, "BTC-USD");
        return result;
    }
}
