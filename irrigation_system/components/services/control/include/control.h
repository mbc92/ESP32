#include "../../mdns/include./mdns.h"
#include "../../../drivers/mdns/include/mdns.h"
#include "esp_err.h"
#include "esp_log.h"

#define MASTER "_master"
#define PROTOCOL "_tcp"

esp_err_t controlService_initializeNode();

bool controlService_getNodeMode();