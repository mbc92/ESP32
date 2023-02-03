set(COMPONENT_REQUIRES "json")
idf_component_register(SRCS "http_server.c" "wifi.c" "mdns.c" "mdns_networking.c" "http_server.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_wifi esp_timer esp_eth esp_http_server json)
