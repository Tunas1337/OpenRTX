#!/bin/bash

# Make call via lisa easier
rm -rf build; meson setup build; meson compile -C build openrtx_c62