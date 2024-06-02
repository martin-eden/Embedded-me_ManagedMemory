// Memory segment in dynamic memory management

/*
  Author: Martin Eden
  Last mod.: 2024-06-02
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
      TManagedMemory();
      ~TManagedMemory();

      void PrintTag();
      void PrintWrappings();
      void Print();

      void Release();

      me_MemorySegment::TMemorySegment GetData();

      TBool CloneFrom(
        me_MemorySegment::TMemorySegment * SrcSeg
      );
      TBool CloneFrom(
        const TChar * Asciiz
      );
      TBool CloneFrom(
        TManagedMemory * Src
      );

    private:
      me_MemorySegment::TMemorySegment Data;
  };
}

/*
  2025-06-02
*/
