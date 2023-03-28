#ifndef _LINBCOINEXCHANGE_CONNECTION_H
#define _LINBCOINEXCHANGE_CONNECTION_H
#include <vector>
#include <string>
#include <memory>
#include <time.h>

namespace coin {

    struct ticker {
        uint64_t ask;
        uint64_t bid;
        uint64_t volume;
        uint64_t trade_id;
        uint64_t price;
        uint64_t size;
        time_t time;
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
        std::vector<std::string> get_product();
        ticker get_quote(const std::string & prod);
        private:
        connection(std::shared_ptr<i_http_handler> _http_handler)
        : http_handler(_http_handler){}
        std::shared_ptr<i_http_handler> http_handler;
        friend class connection_factory;
    };
}

#endif