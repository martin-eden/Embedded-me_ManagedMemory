#!/bin/bash

# Uninstall library
arduino-cli lib uninstall me_ManagedMemory

# Uninstall dependencies
arduino-cli lib uninstall \
  me_Console \
  me_MemorySegment \
  me_BaseTypes
