#include "./include/mdns_service.h"

esp_err_t mdns_service_lookup_mdns_service(const char* u8ServiceName, const char* u8Proto, bool* bResult)
{
    esp_err_t tRetVal = ESP_OK;
    bool bServiceFound = false;
    if(NULL != u8ServiceName || NULL != u8Proto)
    {
        mdns_result_t results;
        bServiceFound = find_mdns_service(u8ServiceName, u8Proto, &results);
    }
    *bResult = bServiceFoun;
    
    return tRetVal;
}