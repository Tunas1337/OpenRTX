
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_BK4819 bk4819.c)
zephyr_library_sources_ifdef(CONFIG_BK4819 bk4819.h)

# Include the Kconfig file
zephyr_library_include_directories(.)