#!/usr/bin/env bash

print_error() {
  echo -e "\e[41m\e[97mError: $1\e[0m"
}

if ! command -v qemu-system-x86_64 &>/dev/null; then
  print_error "qemu-system-x86_64 not found. Please install qemu-system-x86_64 before running this script."
  exit 1
fi

Kernel="build/FKernel.bin"

qemu-system-x86_64 -kernel "$Kernel" -m 512M -machine type=pc-i440fx-3.1
