#include "esp_wifi.h"
#include "esp_log.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "freertos/event_groups.h"


void wifi_init(void);
void fast_scan(void);


/* The examples use WiFi configuration that you can set via project configuration menu
   If you'd rather not, just change the below entries to strings with
   the config you want - ie #define EXAMPLE_WIFI_SSID "mywifissid"
*/
#define WIFI_SSID      "VillaKunterbunt"
#define WIFI_PASS      "29596524097455572404"
#define MAXIMUM_RETRY  100

/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1
