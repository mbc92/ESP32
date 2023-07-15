#include "./include/control.h"

static bool g_isMaster = false;

esp_err_t controlService_initializeNode()
{
    bool bResult = false;
    esp_err_t tRetVal = ESP_OK;

    // Lookup MDNS _master service
    tRetVal = mdnsService_lookupMdnsService(MASTER, PROTOCOL, &bResult);
    if(tRetVal == ESP_OK)
    {   
        // If no service exists for _master we initialize this node as master. 
        if(!bResult)
        {          
            tRetVal = add_mdns_services(MASTER, PROTOCOL, NULL, 0);
            if(tRetVal == ESP_OK)
            { 
                ESP_LOGI("TAG", "MASTER");
                g_isMaster = true;

            }else
            {
                 // Misra
            } 
        }else
        {           
            // Node is slave
            ESP_LOGI("TAG", "SLAVE");
        }
    }else
    {
        // Misra
    }

    return tRetVal;
}

bool controlService_getNodeMode()
{
    return g_isMaster;
}