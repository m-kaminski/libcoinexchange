#ifndef _LINBCOINEXCHANGE_CONNECTION_H
#define _LINBCOINEXCHANGE_CONNECTION_H
#include <vector>
#include <string>
#include <memory>
#include <time.h>
        #include <sys/time.h>

namespace coin {

    struct ticker {
        uint64_t ask;
        uint64_t bid;
        uint64_t volume;
        uint64_t trade_id;
        uint64_t price;
        uint64_t size;
        timeval time;

    };

    struct product {
        std::string id;
        std::string base_currency;
        std::string quote_currency;
        int quote_increment; // number of decimal places
        int base_increment; // number of decimal places
    };

    // Abstract interface for http handler, actual type to be defined
    // in connection_factory
    class i_http_handler {
        public:
        virtual std::string get(std::string addr) = 0;
    };

    // constructor is hidden as private, meant to only be called from
    // an appropriate factory class
    class connection {
        public:
        bool initialized();
        std::vector<product> get_products();
        ticker get_quote(const std::string & prod);
        private:
        connection(std::shared_ptr<i_http_handler> _http_handler)
        : http_handler(_http_handler){}
        std::shared_ptr<i_http_handler> http_handler;
        friend class connection_factory;
    };
}

#endif