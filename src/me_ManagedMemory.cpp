// Manager for memory segment in dynamic memory

/*
  Author: Martin Eden
  Last mod.: 2024-10-04
*/

#include "me_ManagedMemory.h"

#include <stdio.h> // printf()

using
  me_ManagedMemory::TManagedMemory,
  me_MemorySegment::TMemorySegment;

/*
  Destructor

  Release memory.
*/
TManagedMemory::~TManagedMemory()
{
  // printf("( ~TManagedMemory\n");

  Release();

  // printf(") ~TManagedMemory\n");
}

/*
  Copy memory from another segment
*/
TBool TManagedMemory::Set(TMemorySegment Src)
{
  Release();

  if (!Reserve(Src.Size))
    return false;

  if (!CopyMemFrom(Src))
  {
    /*
      CopyMemFrom() will fail if our span intersects with <Src>.

      This case will happen if Reserve()'s allocated segment
      intersects with <Src> segment.

      Release() will zero part of <Src> segment in this case.
    */
    Release();
    return false;
  }

  return true;
}

/*
  Create copy from ASCIIZ
*/
TBool TManagedMemory::Set(const TChar * Asciiz)
{
  return Set(me_MemorySegment::FromAsciiz(Asciiz));
}

/*
  Print our state to stdout
*/
void TManagedMemory::PrintWrappings()
{
  printf("[TManagedMemory 0x%04X] (\n", (TUint_2) this);

  TMemorySegment::PrintWrappings();

  printf(")\n");
}

/*
  2024-06-02
  2024-06-04
  2024-06-15
  2024-07-06
*/
