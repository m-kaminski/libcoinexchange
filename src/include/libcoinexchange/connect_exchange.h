#ifndef _LINBCOINEXCHANGE_CONNECT_EXCHANGE_H
#define _LINBCOINEXCHANGE_CONNECT_EXCHANGE_H
#include <memory>

#include "connection.h"

namespace coin {
    std::unique_ptr<connection> connect_exchange();
}

#endif