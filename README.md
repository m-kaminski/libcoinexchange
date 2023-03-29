# libcoin
Library to process Bitcoin exchange trade data, first target being coinbase API (other exchanges coming soon)



Following APIs are handled

https://docs.cloud.coinbase.com/advanced-trade-api/docs/rest-api-overview

https://docs.cloud.coinbase.com/exchange/reference/

https://docs.cloud.coinbase.com/advanced-trade-api/docs/ws-overview



certain datasets are stored in ```sample_data``` directory
List products
```curl -L -X GET 'https://api.exchange.coinbase.com/products' -H 'Content-Type: application/json' > products.json```

Product quote
```curl -L -X GET 'https://api.exchange.coinbase.com/products/BTC-USD/ticker' -H 'Content-Type: application/json' > BTC-USD.json```






# build dependencies
gtest
boost beast
cmake
g++
openssl openssl-devel
libcurl libcurl-devel


Repos used:
1. https://github.com/nlohmann/json
2. https://github.com/libcpr/cpr

