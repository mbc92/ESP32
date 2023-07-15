#include "./include/http.h"

static httpd_handle_t server;

httpd_handle_t* httpService_getServerHandle()
{
    return &server;
}

esp_err_t httpService_startWebserver()
{
    return httpDrv_startWebserver(&server);
}

esp_err_t httpService_respSend(httpd_req_t *r, const char *buf, ssize_t buf_len)
{
    return httpd_resp_send(r, buf, buf_len);
}

esp_err_t httpService_registerUriHandler(httpd_uri_t* tUriHandler)
{
    esp_err_t tRetVal = ESP_OK;

    if(NULL != tUriHandler)
    {
        // Register new URI with our HTTP server.
        tRetVal = httpd_register_uri_handler(server, tUriHandler);
    }
    else
    {
        tRetVal = ESP_FAIL;
    }

    return tRetVal;
}
