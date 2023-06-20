#include "esp_err.h"
#include "../../components/drivers/mdns/include/mdns.h"

#define MASTER "_master"
#define PROTOCOL "_tcp"

/**
 * \brief Lookup a MDNS service.
 *
 * This function will lookup a MDNS service on the given protocol, 
 * when its found bResult will be TRUE, otherwise FALSE.
 * 
 * \param u8ServiceName mdns service name to lookup
 * \param u8Proto Service protocol.
 * \param bResult bool to indicate if MDNS service has been found
 * \return esp_err_t to indicate success.
 */
esp_err_t mdnsService_lookupMdnsService(const char* u8ServiceName, const char* u8Proto, bool* bResult);