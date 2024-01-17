idf_component_register(SRCS "OTA.cpp"
                    INCLUDE_DIRS "." "web"
                    REQUIRES app_update esp_http_server
                    EMBED_TXTFILES web/index.html)