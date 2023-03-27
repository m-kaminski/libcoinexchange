#ifndef _LINBCOINEXCHANGE_CONNECTION_H
#define _LINBCOINEXCHANGE_CONNECTION_H
#include <vector>
#include <string>
#include <memory>

namespace coin {

    struct ticker {
        std::string ask;
        std::string bid;
        double volume;
        int32_t trade_id;
        double price;
        double size;
        std::string time;
    };

    // Abstract interface for http handler, actual type to be defined
    // in connection_factory
    class i_http_handler {
        public:
        virtual std::string get(std::string addr) = 0;
    };

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