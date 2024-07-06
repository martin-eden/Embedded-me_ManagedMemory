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
  class TManagedMemory
  {
    TMemorySegment Data;

    public:
      ~TManagedMemory();

      void Release();

      TBool Set(TMemorySegment SrcSeg);
      TBool Set(const TChar * Asciiz);
      TBool Set(TManagedMemory * Src);

      TMemorySegment Get();

      // Print raw data
      void Print();
      // [debug] Print state
      void PrintWrappings();
  };
}

/*
  2024-06-02
  2024-06-04
  2024-06-15
*/
