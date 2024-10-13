// Implementation of free functions from [me_ManagedMemory]

/*
  Author: Martin Eden
  Last mod.: 2024-10-12
*/

/*
  Free functions are free to use whatever contracts they please
  as long as they are used by someone.

  -- Martin                                          2024-10-05
*/

#include "me_ManagedMemory.h"

#include <Arduino.h> // "min" macro for "CopyMemTo", PSTR for [Debug]
// #include <me_Heap.h> // Custom memory manager

/*
  #include <stdio.h>

  for printf_P() for possible debug output.

  We can't use [me_Console] because it uses [me_String] which
  uses us.
*/
// #include <stdio.h> // [Debug]

using namespace me_ManagedMemory;

using
  me_MemorySegment::TMemorySegment;

/*
  Reserve block of memory. Zero data after allocation

  Opportunistically calls custom memory manager.
  Uses stock malloc() as fallback option.
*/
TBool me_ManagedMemory::Freetown::Reserve(
  TMemorySegment * MemSeg,
  TUint_2 Size
)
{
  /*
  // Can use custom memory manager?
  if (Heap.IsReady())
  {
    // Let custom manager handle this case
    TBool IsReserved = Heap.Reserve(MemSeg, Size);

    if (IsReserved)
      return true;
  }
  //*/

  /*
    If custom memory manager is not ready or wasn't able
    to handle this request, we're handling it ourselves.
  */

  // Zero size? Job done!
  if (Size == 0)
    return true;

  TUint_2 MallocAddr = (TUint_2) malloc(Size);

  if (MallocAddr == 0)
  {
    // printf_P(PSTR("Failed to reserve %u bytes.\n"), Size);
    return false;
  }

  MemSeg->Start.Addr = MallocAddr;
  MemSeg->Size = Size;

  // Zero memory (contract)
  ZeroMem(*MemSeg);

  /*
  printf_P(PSTR("Reserve ( Addr %05u Size %05u )\n"), MemSeg->Start.Addr, MemSeg->Size);
  //*/

  return true;
}

/*
  Release block of memory. Zero before release

  Opportunistically calls memory manager if it is alive.
  Uses free() as fallback option.
*/
void me_ManagedMemory::Freetown::Release(
  TMemorySegment * MemSeg
)
{
  /*
  // Can use custom memory manager?
  if (Heap.IsReady())
  {
    // Let custom manager handle this case
    TBool IsReleased = Heap.Release(MemSeg);

    if (IsReleased)
      return;
  }
  //*/

  /*
    We're here if custom memory manager is not ready
    or wasn't able to handle this request.
  */

  // Zero size? Job done!
  if (MemSeg->Size == 0)
  {
    MemSeg->Start.Addr = 0;
    return;
  }

  /*
  printf_P(PSTR("Release ( Addr %05u Size %05u )\n"), MemSeg->Start.Addr, MemSeg->Size);
  //*/

  // Zero memory (optional)
  ZeroMem(*MemSeg);

  free((void *) MemSeg->Start.Addr);

  MemSeg->Start.Addr = 0;
  MemSeg->Size = 0;
}

/*
  Fill memory span with zero byte
*/
void me_ManagedMemory::Freetown::ZeroMem(
  TMemorySegment MemSeg
)
{
  for (TUint_2 Offset = 0; Offset < MemSeg.Size; ++Offset)
    MemSeg.Bytes[Offset] = 0;
}

/*
  Copy data to another segment

  If destination segment is larger than source, we don't touch
  tail data.

  If segments do intersect, we return false. We see no practical
  cases for data copy between intersecting segments.
*/
TBool me_ManagedMemory::Freetown::CopyMemTo(
  TMemorySegment Dest,
  TMemorySegment Src
)
{
  if (me_MemorySegment::Freetown::Intersects(Src, Dest))
    return false;

  TUint_2 MinSize = min(Src.Size, Dest.Size);

  // Zero size? Job done!
  if (MinSize == 0)
    return true;

  for (TUint_2 Offset = 0; Offset < MinSize; ++Offset)
    Dest.Bytes[Offset] = Src.Bytes[Offset];

  return true;
}

/*
  2024-05
  2024-06
  2024-10-05
  2024-10-07
  2024-10-08
  2024-10-12 [~] Heap
*/
