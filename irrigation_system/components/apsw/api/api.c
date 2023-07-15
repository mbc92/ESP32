#include "./include/api.h"
#include "./include/html.h"

static uint8_t u8NodeCount = 0;
static char json[250] = "";

/* Handler for route /master */
static esp_err_t get_master_handler(httpd_req_t *req)
{
    return httpService_respSend(req, json, HTTPD_RESP_USE_STRLEN);
}

/* Handler for route /home */
esp_err_t get_home_handler(httpd_req_t *req)
{   
    return httpd_resp_send(req, htmlDefaultHomePage, HTTPD_RESP_USE_STRLEN);
}

static httpd_uri_t routes[API_ROUTES_NO_ROUTES] = 
{
     {
    .uri       = "/home",
    .method    = HTTP_GET,
    .handler   = get_home_handler
    },
    {
    .uri       = "/master",
    .method    = HTTP_GET,
    .handler   = get_master_handler
    }
};


esp_err_t appApi_initApi()
{
    esp_err_t tRetVal = ESP_OK;

    // If this node has been initialized as master node
    if (controlService_getNodeMode())
        {   
            ESP_LOGI("appAPi:", "Registering /master route");
            char* ipAddr = wifiService_getIPAddress();
            sprintf(json, "{\"ip_address\":\"%s\",\"name\":\"master\"}", ipAddr);

            for(uint8_t i = 0; i < API_ROUTES_NO_ROUTES; ++i)
            {
                //TODO: error is now overwritten
                tRetVal = httpService_registerUriHandler(&routes[i]);
            }
        }
        else
        {
            //TODO: Connect to master and add this node to link.
        }
          
    return tRetVal;
}

esp_err_t appApi_addNode()
{
    esp_err_t tRetVal = ESP_OK;
    return tRetVal;
}