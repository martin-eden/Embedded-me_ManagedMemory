# What

(2024-06 .. )

Arduino library for managing memory segment in dynamic memory.

Experimental. WIP.


## Requirements

  * arduino-cli
  * bash


## Install

Run [Install.sh](Install.sh).


# Compile

Zero-warnings compilation:

```bash
arduino-cli compile --fqbn arduino:avr:uno --quiet --warnings all . --build-property compiler.cpp.extra_flags="-std=c++1z"
```

## Remove

Run [Remove.sh](Remove.sh).


## Code

[Interface](src/me_ManagedMemory.h)

[Implementation](src/me_ManagedMemory.cpp)

[Example](examples/me_ManagedMemory/me_ManagedMemory.ino)


## See also

[My other repositories](https://github.com/martin-eden/contents).
