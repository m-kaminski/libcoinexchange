#include "libcoinexchange/connect_exchange.h"


namespace coin {
    std::unique_ptr<connection> connect_exchange() {

        return std::unique_ptr<connection>(new connection());
    }
}
