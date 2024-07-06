// Management of memory segment in dynamic memory

/*
  Author: Martin Eden
  Last mod.: 2024-07-06
*/

#pragma once

#include <me_MemorySegment.h>
#include <me_BaseTypes.h>

namespace me_ManagedMemory
{
  using
    me_BaseTypes::TBool,
    me_BaseTypes::TChar,
    me_MemorySegment::TMemorySegment;

  /*
    Dynamically allocated memory segment
  */
  class TManagedMemory : public TMemorySegment
  {
    public:
      ~TManagedMemory();

      // Copy memory from another segment
      TBool Set(TMemorySegment SrcSeg);
      // Copy memory from ASCIIZ
      TBool Set(const TChar * Asciiz);

      // [debug] Print state
      void PrintWrappings();
  };
}

/*
  2024-06-02
  2024-06-04
  2024-06-15
  2024-07-06
*/
