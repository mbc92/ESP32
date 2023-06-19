idf_component_register(SRCS  "http_service/http_service.c" "mdns_service/mdns_service.c"
                    INCLUDE_DIRS "http_service/include" "mdns_service/include"
                    REQUIRES esp_netif)
