# What

(2024-06, 2024-10)

Managing memory segment in dynamic memory. Arduino library.

## Design

It's resizable memory segment in heap memory.

It can load data and return data segment. If fills memory with
zeroes after allocation and before deallocation.

Deallocation is hardwired to class destructor. So be careful
not to pass copy of instance by accident. Memory span in this case
will be the same and the first destructor will zero that memory.

From the other hand, it's useful for creating copies of any
binary data or ASCIIZ in dynamic memory and not worrying about
releasing their memory. Memory will be released when class instance
leave syntax scope.


## Code

* [Interface](src/me_ManagedMemory.h)
* Implementation
  * [Class][TManagedMemory]
  * [Freetown][Freetown]
* [Example](examples/me_ManagedMemory/me_ManagedMemory.ino)


## Requirements

  * arduino-cli
  * bash


## Install

Run [Install.sh](Install.sh).


## Compile

Zero-warnings compilation:

```bash
arduino-cli compile --fqbn arduino:avr:uno --quiet --warnings all . --build-property compiler.cpp.extra_flags="-std=c++1z"
```

## Remove

Run [Remove.sh](Remove.sh).


## See also

* [My other embedded C++ libraries][Embedded]
* [My other repositories][Repos]


[Interface]: src/me_ManagedMemory.h
[TManagedMemory]: src/TManagedMemory.cpp
[Freetown]: src/me_ManagedMemory_Freetown.cpp
[Example]: examples/me_ManagedMemory/me_ManagedMemory.ino

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
