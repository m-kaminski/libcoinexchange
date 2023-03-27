# libcoin
Library to process Bitcoin exchange trade data, first target being coinbase API


Following APIs are handled

https://docs.cloud.coinbase.com/advanced-trade-api/docs/rest-api-overview

https://docs.cloud.coinbase.com/exchange/reference/

https://docs.cloud.coinbase.com/advanced-trade-api/docs/ws-overview



List products
curl -L -X GET 'https://api.exchange.coinbase.com/products' -H 'Content-Type: application/json' > products.json
```
[
    {
        "id": "BTC-USD",
        "base_currency": "BTC",
        "quote_currency": "USD",
        "quote_increment": "0.01",
        "base_increment": "0.00000001",
        "display_name": "BTC/USD",
        "min_market_funds": "1",
        "margin_enabled": false,
        "post_only": false,
        "limit_only": false,
        "cancel_only": false,
        "status": "online",
        "status_message": "",
        "trading_disabled": false,
        "fx_stablecoin": false,
        "max_slippage_percentage": "0.02000000",
        "auction_mode": false,
        "high_bid_limit_percentage": ""
    },
    {
        "id": "AGLD-USD",
        "base_currency": "AGLD",
        "quote_currency": "USD",
...
]
```

Product quote
curl -L -X GET 'https://api.exchange.coinbase.com/products/BTC-USD/ticker' -H 'Content-Type: application/json' > BTC-USD.json

```
{
    "ask": "27856.83",
    "bid": "27853.76",
    "volume": "10215.70314036",
    "trade_id": 514598501,
    "price": "27856.83",
    "size": "0.00535919",
    "time": "2023-03-27T02:33:01.821466Z"
}
```


Reqs

gtest
boost beast
cmake
g++
