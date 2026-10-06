# Reuse the pinned external GEM module, replacing only its peripheral artwork.
if(CONFIG_ZMK_DISPLAY AND CONFIG_NICE_VIEW_WIDGET_STATUS)
  set(GEM_ROOT "${ZEPHYR_BASE}/../nice-view-gem/boards/shields/nice_view_gem")
  if(NOT EXISTS "${GEM_ROOT}/custom_status_screen.c")
    message(FATAL_ERROR "nice-view-gem v0.3.0 is required; run west update")
  endif()
  zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)
  zephyr_library_sources(
    ${GEM_ROOT}/custom_status_screen.c
    ${GEM_ROOT}/assets/images.c
    ${GEM_ROOT}/widgets/battery.c
    ${GEM_ROOT}/widgets/output.c
    ${GEM_ROOT}/widgets/util.c
    ${GEM_ROOT}/widgets/screen_peripheral.c
    rabbit.c
  )
endif()
