#!/bin/bash

# Install dependencies
arduino-cli \
  lib install \
    --git-url \
      https://github.com/martin-eden/Embedded-me_BaseTypes \
      https://github.com/martin-eden/Embedded-me_MemorySegment \
      https://github.com/martin-eden/Embedded-me_Console

# Install library
arduino-cli \
  lib install \
    --git-url \
      https://github.com/martin-eden/Embedded-me_ManagedMemory
