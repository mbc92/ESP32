/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "freertos/event_groups.h"
#include "nvs_flash.h"
#include "../components/drivers/include/mdns.h"
#include "../components/drivers/include/wifi.h"
#include "../components/drivers/include/http_server.h"
#include <time.h>
#include <stdlib.h>

bool g_is_master = false;
char* node_name = "master";

void app_main(void)
{
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    ESP_ERROR_CHECK(esp_netif_init());

    ESP_LOGI("wifi station", "ESP_WIFI_MODE_STA");

    //Initialize wifi driver and wifi event handler
    wifiDrv_init();
    mdns_init();

   // srand(time(NULL));   // Initialization, should only be called once.
   // int r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.

    mdns_result_t results;
    find_mdns_service("_master", "_tcp", &results);

    // Check if we found a master node after connecting to the network
   if (results.hostname && !results.hostname[0]) 
    {
      // master node detected, connecting this node to the master node.
      ESP_LOGI("TAG", "SLAVE");
    }
    else
    {

      g_is_master = true;
      char* ipAddr = wifiDrv_getIpAddr();
      
      ESP_LOGI("TAG", "MASTER");
      add_mdns_services("_master", "_tcp", NULL, 0);

      if (ipAddr)
      {
        ESP_LOGI("TAG", "master ip: %s", ipAddr);
        /* Start the server for the first time */
        httpd_handle_t server = start_webserver(g_is_master);
        if (server)
        {
           ESP_LOGI("Irrigation system", "HTTP server started");
        }

      }
    }
}
