#include "./include/http_server.h"

// JSON payload
// static char json[250] = "";
// static char htmlDefaultHomePage[4500] = 
// "<!DOCTYPE html>\n"
// "<html lang=\"en\">\n"
// "<head>\n"
// "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n"
// "<title>Irrigation system</title>\n"
// "<style>\n"
// "html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n"
// "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n"
// "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n"
// ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n"
// ".button-on {background-color: #3498db;}\n"
// "</style>\n"
// "</head>\n"
// "<body>\n"
// "<p>Station 1 soil humidity 44 </p><a class=\"button button-on\" href=\"/station/on\">Hidrate</a>\n"
// "<p>Station 2 soil humidity 12 </p><a class=\"button button-on\" href=\"/station/on\">Hidrate</a>\n"
// "<p>Station 3 soil humidity 32 </p><a class=\"button button-on\" href=\"/station/on\">Hidrate</a>\n"
// "<p>Station 4 soil humidity 92 </p><a class=\"button button-on\" href=\"/station/on\">Hidrate</a>\n"
// "</body>\n"
// "</html>\n";

// /* Handler for route /master */
// esp_err_t get_master_handler(httpd_req_t *req)
// {
//     return httpd_resp_send(req, json, HTTPD_RESP_USE_STRLEN);
// }

// /* Handler for route / */
// esp_err_t get_home_handler(httpd_req_t *req)
// {   
//     //renderStations(4);
//     return httpd_resp_send(req, htmlDefaultHomePage, HTTPD_RESP_USE_STRLEN);
// }


// static const httpd_uri_t getMaster = {
//     .uri       = "/master",
//     .method    = HTTP_GET,
//     .handler   = get_master_handler
// };

// static const httpd_uri_t getHome = {
//     .uri       = "/home",
//     .method    = HTTP_GET,
//     .handler   = get_home_handler
// };

esp_err_t httpDrv_register_uri_handler(httpd_handle_t handle,
                                     const httpd_uri_t *uri_handler)
{
    esp_err_t rVal = ESP_OK;
    rVal = httpd_register_uri_handler(handle, uri_handler);
    return rVal;
}

esp_err_t httpDrv_startWebserver(httpd_handle_t* tServerHandle)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.lru_purge_enable = true;
    return httpd_start(tServerHandle, &config);
}