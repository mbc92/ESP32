idf_component_register(SRCS  "http/http.c" "mdns/mdns.c"
                    INCLUDE_DIRS "http/include" "mdns/include"
                    REQUIRES esp_netif)
