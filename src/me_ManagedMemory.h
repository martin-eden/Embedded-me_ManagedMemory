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
  class TManagedMemory
  {
    public:
      TManagedMemory();
      ~TManagedMemory();
      void PrintTag();
      void PrintWrappings();
    private:
      me_MemorySegment::TMemorySegment MemSeg;
  };
}

/*
  2025-06-02
*/
