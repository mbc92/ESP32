#include "./include/mdns.h"

esp_err_t mdnsService_lookupMdnsService(const char* u8ServiceName, const char* u8Proto, bool* bResult)
{
    // Initialize local variables
    esp_err_t tRetVal = ESP_OK;
    bool bServiceFound = false;

    // Check input parameters 
    if(NULL != u8ServiceName || NULL != u8Proto || NULL != bResult)
    {   
        // Call MDNS driver to lookup service and report back. 
        mdns_result_t results;
        bServiceFound = find_mdns_service(u8ServiceName, u8Proto, &results);
    }

    // Set output parameter
    *bResult = bServiceFound;
    
    return tRetVal;
}