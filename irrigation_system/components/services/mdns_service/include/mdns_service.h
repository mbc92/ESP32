#include "esp_err.h"
#include "../../components/drivers/mdns/include/mdns.h"

#define MASTER "_master"
#define PROTOCOL "_tcp"

esp_err_t mdns_service_lookup_mdns_service(const char* u8ServiceName, const char* u8Proto, bool* bResult);