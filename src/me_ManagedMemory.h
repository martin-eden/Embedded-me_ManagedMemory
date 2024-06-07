// Memory segment in dynamic memory management

/*
  Author: Martin Eden
  Last mod.: 2024-06-04
*/

#pragma once

#include <me_MemorySegment.h>
#include <me_BaseTypes.h>

namespace me_ManagedMemory
{
  using
    me_BaseTypes::TBool,
    me_BaseTypes::TChar;

  class TManagedMemory
  {
    public:
      ~TManagedMemory();

      void PrintTag();
      void PrintWrappings();
      void Print();

      void Release();

      me_MemorySegment::TMemorySegment Get();

      TBool Set(
        me_MemorySegment::TMemorySegment SrcSeg
      );
      TBool Set(
        const TChar * Asciiz
      );
      TBool Set(
        TManagedMemory * Src
      );

    private:
      me_MemorySegment::TMemorySegment Data;
  };
}

/*
  2024-06-02
  2024-06-04
*/
