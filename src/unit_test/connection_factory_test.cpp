#include "gtest/gtest.h"

#include "libcoinexchange/connection_factory.h"

namespace coin
{

    class connect_exchange_test : public ::testing::Test
    {
    };

    TEST_F(connect_exchange_test, connect_exchange)
    {
        EXPECT_TRUE(connection_factory::connect_exchange()->initialized());
    }
    

    TEST_F(connect_exchange_test, connected_pairs)
    {
        auto conn = connection_factory::connect_exchange();
        EXPECT_EQ(conn->get_product().size(),1);
        EXPECT_EQ(conn->get_product()[0], "BTC-USD");
    }
    
    class htto_handler_mock : public i_http_handler
    {
        public:
        virtual std::string get(std::string addr)
        {
            std::string response = "{\"ask\":\"21.37\",\"bid\":\"21.38\",\"volume\":"
                                    "\"10615.98057785\",\"trade_id\":514624546,"
                                    "\"price\":\"27877.66\",\"size\":\"0.00316582\","
                                    "\"time\":\"2023-03-28T16:58:42.085703Z\"}";
            return response;
        }
    };

    TEST_F(connect_exchange_test, parse_json_bidask)
    {
        auto conn = connection_factory::connect_exchange(std::shared_ptr<i_http_handler>(new htto_handler_mock));
        ticker q = conn->get_quote("BTC-USD");
        EXPECT_EQ(q.bid, 213800);
        EXPECT_EQ(q.ask, 213700);
    }

    TEST_F(connect_exchange_test, parse_json_time)
    {
        auto conn = connection_factory::connect_exchange(std::shared_ptr<i_http_handler>(new htto_handler_mock));
        ticker q = conn->get_quote("BTC-USD");
        // convert time to epoch: https://epochtimestamp.com/
        EXPECT_EQ(q.time.tv_sec, 1680040722);
        EXPECT_EQ(q.time.tv_usec, 85703);
    }
    

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
