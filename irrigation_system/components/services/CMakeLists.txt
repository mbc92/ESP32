set(COMPONENT_REQUIRES "json" esp_netif)
idf_component_register(SRCS  "http/http.c" "mdns/mdns.c" "control/control.c" "wifi/wifi.c"
                    INCLUDE_DIRS "http/include" "mdns/include" "control/include" "wifi/include"
                    REQUIRES esp_netif esp_http_server json esp_wifi drivers)
