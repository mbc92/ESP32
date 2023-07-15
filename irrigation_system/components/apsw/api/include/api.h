#include "esp_err.h"
#include <esp_http_server.h>
#include "../../components/services/wifi/include/wifi.h"
#include "../../components/services/http/include/http.h"
#include "../../../services/control/include/control.h"

#define API_ROUTES_LIST         GET_HOME, \
                                GET_MASTER


typedef enum
{
    API_ROUTES_LIST,
    API_ROUTES_NO_ROUTES
}AppApi_ApiRoutesId_ten;

esp_err_t appApi_initApi();
esp_err_t appApi_addNode();