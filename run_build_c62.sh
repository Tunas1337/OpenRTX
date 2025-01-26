#!/bin/bash

# Call this file with lisa "zep exec ./run_build_c62.sh"

# Make call via lisa easier
rm -rf build; meson setup build; meson compile -C build openrtx_c62