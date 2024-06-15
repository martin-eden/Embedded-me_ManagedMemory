// Management of memory segment in dynamic memory

/*
  Author: Martin Eden
  Last mod.: 2024-06-15
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
      ~TManagedMemory() { Release(); };

      void Release() { Data.Release(); };

      TMemorySegment Get() { return Data; };

      TBool Set(TMemorySegment SrcSeg);
      TBool Set(const TChar * Asciiz);
      TBool Set(TManagedMemory * Src);

      void PrintWrappings();
      void Print();
  };
}

/*
  2024-06-02
  2024-06-04
  2024-06-15
*/
