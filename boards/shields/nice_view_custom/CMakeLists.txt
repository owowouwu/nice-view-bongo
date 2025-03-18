if(CONFIG_ZMK_DISPLAY)
    zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)
    
    if(CONFIG_NICE_VIEW_WIDGET_STATUS)
        zephyr_library_sources(
            custom_status_screen.c
            widgets/bolt.c
            widgets/util.c
        )

        if(NOT CONFIG_ZMK_SPLIT OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
            zephyr_library_sources(
                widgets/status.c
                widgets/bongocatart.c
            )
        else()
            zephyr_library_sources(
                widgets/art.c
                widgets/peripheral_status.c
            )
        endif()
    endif()

    # Add modifiers widget sources if enabled
    if(CONFIG_ZMK_WIDGET_MODIFIERS)
        zephyr_library_sources(
            widgets/modifiers.c
            widgets/modifiers_sym.c
        )
    endif()

    target_include_directories(app PRIVATE include)
endif()
