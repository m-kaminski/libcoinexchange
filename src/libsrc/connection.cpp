#include "libcoinexchange/connection.h"

namespace coin
{
    bool connection::initialized()
    {
        return true;
    }

    std::vector<std::string> connection::get_product()
    {
        std::vector<std::string> result(1,"BTC-USD");
        return result;
    }
}
