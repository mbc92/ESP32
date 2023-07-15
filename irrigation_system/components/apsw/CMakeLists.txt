set(COMPONENT_REQUIRES "json" esp_netif)
idf_component_register(SRCS  "api/api.c" 
                    INCLUDE_DIRS "api/include"
                    REQUIRES esp_netif esp_http_server json esp_wifi)
