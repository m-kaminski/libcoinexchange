add_executable(hello_exchange hello_exchange.cpp)
target_link_libraries(hello_exchange libcoinexchange  cpr::cpr nlohmann_json::nlohmann_json)
