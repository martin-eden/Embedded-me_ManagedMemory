// Management of memory segment in dynamic memory

/*
  Author: Martin Eden
  Last mod.: 2024-10-05
*/

/*
  Central part of this module is allocated memory segment.

  It manages memory, and guarantee it will release it upon death.

  It can't be safe and useful at the same time. So it sacrifices safety
  and provides data addresses.
*/

#pragma once

#include <me_MemorySegment.h>
#include <me_BaseTypes.h>

namespace me_ManagedMemory
{
  /*
    Allocated memory segment
  */
  class TManagedMemory
  {
    public:
      // Freeing destructor
      ~TManagedMemory();

      // Return data segment
      me_MemorySegment::TMemorySegment GetData();

      // Return data segment size
      TUint_2 GetSize();
      // Resize data segment
      TBool ResizeTo(TUint_2 NewSize);
      // [Handy] Release data segment
      void Release();

      // Load from arbitrary span
      TBool LoadFrom(me_MemorySegment::TMemorySegment SrcSeg);
      // Load from ASCIIZ
      TBool LoadFrom(const TChar * Asciiz);
      // Load from our specie
      TBool LoadFrom(TManagedMemory * Src);

      // [Debug] Print state and data to stdout
      void PrintWrappings();

    private:
      me_MemorySegment::TMemorySegment DataSeg;
  };

  namespace Freetown
  {
    // Reserve block of memory. Zero after allocation
    TBool Reserve(
      me_MemorySegment::TMemorySegment * MemSeg,
      TUint_2 Size
    );

    // Release block of memory. Zero before release
    void Release(
      me_MemorySegment::TMemorySegment * MemSeg
    );

    // Fill memory span with zero byte
    void ZeroMem(
      me_MemorySegment::TMemorySegment MemSeg
    );

    // Copy data to another segment
    TBool CopyMemTo(
      me_MemorySegment::TMemorySegment Dest,
      me_MemorySegment::TMemorySegment Src
    );
  }
}

/*
  2024-06-02
  2024-06-04
  2024-06-15
  2024-07-06
  2024-10-05
*/
