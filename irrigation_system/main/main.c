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
#include "../components/drivers/mdns/include/mdns.h"
#include "../components/drivers/wifi/include/wifi.h"
#include "../components/drivers/http/include/http_server.h"
#include "../components/drivers/flash/include/flash.h"
#include <time.h>
#include <stdlib.h>

// bool g_is_master = false;
// char* node_name = "master";


// void initializeSystem()
// {

//     mdns_result_t results;
//     bool bServiceFound = find_mdns_service("_master", "_tcp", &results);

//     // Check if we found a master node after connecting to the network
//     if (bServiceFound)
//     {
//         ESP_LOGI("TAG", "SLAVE");
//     }
//     else
//     {

//       g_is_master = true;
//       char* ipAddr = wifiDrv_getIpAddr();
//       ESP_LOGI("TAG", "MASTER");
//       add_mdns_services("_master", "_tcp", NULL, 0);

//       if (ipAddr)
//       {
//         ESP_LOGI("TAG", "master ip: %s", ipAddr);
        
//         /* Start the server for the first time */
//         httpd_handle_t server = httpDrv_start_webserver(g_is_master);
//         if (server)
//         {
//            ESP_LOGI("Irrigation system", "HTTP server started");
//         }

//       }else{

//       }
//   }
// }

void app_main(void)
{
    //Initialize NVS
    flashDrv_init();
    ESP_ERROR_CHECK(esp_netif_init());

    //Initialize wifi driver and wifi event handler
    wifiDrv_init();
    mdns_init();



   
}

