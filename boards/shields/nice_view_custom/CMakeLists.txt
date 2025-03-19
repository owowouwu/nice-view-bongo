if(CONFIG_ZMK_DISPLAY)
    zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)
    
    if(CONFIG_NICE_VIEW_WIDGET_STATUS)
        target_sources(app PRIVATE
            widgets/status.c
            widgets/util.c
            widgets/bolt.c
            custom_status_screen.c
        )

        if(NOT CONFIG_ZMK_SPLIT OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
            zephyr_library_sources(
                widgets/bongocatart.c
                widgets/modifiers_sym.c
            )
        else()
            zephyr_library_sources(
                widgets/art.c
                widgets/peripheral_status.c
            )
        endif()
    endif()

    target_include_directories(app PRIVATE include)
endif()
