#include <esp_http_server.h>
#include "esp_log.h"
#include <cJSON.h>
#include "../../wifi/include/wifi.h"

esp_err_t httpDrv_startWebserver(httpd_handle_t* tServerHandle);

esp_err_t httpDrv_register_uri_handler(httpd_handle_t handle,
                                     const httpd_uri_t *uri_handler);