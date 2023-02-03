#include "http_server.h"

// static const httpd_uri_t hello = {
//     .uri       = "/hello",
//     .method    = HTTP_GET,
//     .handler   = hello_get_handler,
//     /* Let's pass response string in user
//      * context to demonstrate it's usage */
//     .user_ctx  = "Hello World!"
// };
static char json[250] = "";

/* Our URI handler function to be called during GET /uri request */
esp_err_t get_handler(httpd_req_t *req)
{
    httpd_resp_send(req, json, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}


static const httpd_uri_t master = {
    .uri       = "/master",
    .method    = HTTP_GET,
    .handler   = get_handler,
    /* Let's pass response string in user
     * context to demonstrate it's usage */
    .user_ctx  = "Hello World!"
};


httpd_handle_t start_webserver(bool isMaster)
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.lru_purge_enable = true;

    // Start the httpd server
    if (httpd_start(&server, &config) == ESP_OK) {
        // Set URI handlers
        ESP_LOGI("http_server", "Registering URI handlers");
        if (isMaster)
        {   char* ipAddr = wifiDrv_getIpAddr();
            sprintf(json, "{\"ip_address\":\"%s\",\"name\":\"master\"}", ipAddr);
            httpd_register_uri_handler(server, &master);
        }
        //httpd_register_uri_handler(server, &hello);
        return server;
    }

    ESP_LOGI("http_server", "Error starting server!");
    return NULL;
}