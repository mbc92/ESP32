#include "./include/wifi.h"

char* wifiService_getIPAddress()
{
    return wifiDrv_getIpAddr();
}