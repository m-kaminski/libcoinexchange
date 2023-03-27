#include <cpr/cpr.h>
#include <iostream>
#include "libcoinexchange/connection_factory.h"

namespace coin
{

    class htto_handler_cpr : public i_http_handler
    {
        public:
        virtual std::string get(std::string addr)
        {
            cpr::Response r = cpr::Get(cpr::Url{addr});
            r.status_code;
            // assume code is 200 for now .. if it's not, throw
            std::cout << r.status_code << std::endl;
            std::cout << r.text << std::endl;

            return r.text;
        }
    };

    std::unique_ptr<connection> connection_factory::connect_exchange(std::shared_ptr<i_http_handler> p_handler)
    {
        if (p_handler != nullptr) {
            return std::unique_ptr<connection>(new connection(p_handler));
        } else {
            std::shared_ptr<i_http_handler> handler(new htto_handler_cpr);
            return std::unique_ptr<connection>(new connection(handler));
        }
    }
}
