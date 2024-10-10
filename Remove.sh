#!/bin/bash

# Uninstall library
arduino-cli lib uninstall me_ManagedMemory

# Uninstall dependencies
arduino-cli lib uninstall \
  me_Console \
  me_String \
  me_MemorySegment \
  me_InstallStandardStreams \
  me_UartSpeeds \
  me_BaseTypes
