set(COMPONENT_REQUIRES "json" esp_netif)
idf_component_register(SRCS "adc/adc.c" "http/http_server.c" "wifi/wifi.c" "mdns/mdns.c" "mdns/mdns_networking.c" "adc/adc.c" "flash/flash.c"
                    INCLUDE_DIRS "adc/include" "http/include" "wifi/include" "mdns/include" "adc/include" "flash/include" "../config"
                    REQUIRES esp_wifi esp_timer esp_eth esp_http_server json esp_adc nvs_flash esp_netif)
