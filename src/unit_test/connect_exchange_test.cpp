#include "gtest/gtest.h"

#include "libcoinexchange/connect_exchange.h"

namespace coin
{

    class connect_exchange_test : public ::testing::Test
    {
    };

    TEST_F(connect_exchange_test, connect_exchange)
    {
        EXPECT_TRUE(connect_exchange()->initialized());
    }
    

    TEST_F(connect_exchange_test, connected_pairs)
    {
        auto conn = connect_exchange();
        EXPECT_EQ(conn->get_product().size(),1);
        EXPECT_EQ(conn->get_product()[0], "BTC-USD");
    }
    
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
