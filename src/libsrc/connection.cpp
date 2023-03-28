#include "libcoinexchange/connection.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <charconv>
#include <ctime>
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
        tm ts = {0};
        std::string iso_time = j["time"];
        double seconds;
	    sscanf(iso_time.c_str(), "%04d-%02d-%02dT%02d:%02d:%lfdZ",
	           &ts.tm_year, &ts.tm_mon, &ts.tm_mday,
	           &ts.tm_hour, &ts.tm_min,  &seconds);

        ts.tm_sec = (int)seconds;
	    ts.tm_mon  -= 1;
	    ts.tm_year -= 1900;
	    ts.tm_isdst =-1;

        t.ask = stod(j["ask"]);
        t.bid = stod(j["bid"]);
        t.time.tv_sec =  mktime (&ts);
        t.time.tv_usec = (int)(1000000*(seconds - ts.tm_sec));
        return t;
    }

    std::vector<std::string> connection::get_product()
    {
        std::vector<std::string> result(1, "BTC-USD");
        return result;
    }
}
