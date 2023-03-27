#ifndef _LINBCOINEXCHANGE_CONNECT_EXCHANGE_H
#define _LINBCOINEXCHANGE_CONNECT_EXCHANGE_H
#include <memory>

#include "connection.h"

namespace coin {
    class connection_factory {
        public:
        static std::unique_ptr<connection> 
            connect_exchange(std::shared_ptr<i_http_handler> p_handler = nullptr);
    };
}

#endif
