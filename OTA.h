#ifndef __OTA_H
#define __OTA_H

#include "esp_ota_ops.h" // REQUIRES app_update no CMakeLists
#include "esp_http_server.h"
#include "esp_log.h"

#define MIN(a, b) a < b ? a : b

class OTA
{
private:
    OTA() = default;
    OTA(OTA const &) = delete;
    void operator=(OTA const &) = delete;

public:
    static OTA &getInstance()
    {
        static OTA instance; // Thread-safe
        return instance;
    }
    static void begin();
    static esp_err_t index_get_handler(httpd_req_t *req);
    static esp_err_t ota_update_firmware_post_handler(httpd_req_t *req);
    virtual ~OTA();
};

#endif