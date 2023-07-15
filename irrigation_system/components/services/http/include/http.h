#include "../../components/drivers/http/include/http_server.h"
#include "../../components/drivers/wifi/include/wifi.h"
#include "../../control/include/control.h"
#include "esp_err.h"

httpd_handle_t* httpService_getServerHandle();
esp_err_t httpService_respSend(httpd_req_t *r, const char *buf, ssize_t buf_len);
esp_err_t httpService_startWebserver();
esp_err_t httpService_registerUriHandler(httpd_uri_t* tUriHandler);