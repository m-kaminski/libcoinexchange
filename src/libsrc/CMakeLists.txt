add_library (libcoinexchange SHARED connect_exchange.cpp connection.cpp)
target_link_libraries(libcoinexchange PRIVATE nlohmann_json::nlohmann_json)