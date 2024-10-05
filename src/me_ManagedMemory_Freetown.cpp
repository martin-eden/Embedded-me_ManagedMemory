// Implementation of free functions from [me_ManagedMemory]

/*
  Author: Martin Eden
  Last mod.: 2024-10-05
*/

/*
  Free functions are free to use whatever contracts they please
  as long as they are used by someone.

  -- Martin                                          2024-10-05
*/

#include "me_ManagedMemory.h"

#include <Arduino.h> // "min" macro for "CopyMemTo"

// #include <stdio.h> // [Debug] printf() for Reserve() and Release()

using
  me_MemorySegment::TMemorySegment;

/*
  Reserve block of memory. Zero after allocation

  Implemented as wrapper over malloc().
*/
TBool me_ManagedMemory::Freetown::Reserve(
  TMemorySegment * MemSeg,
  TUint_2 Size
)
{
  // Zero size? Job done!
  if (Size == 0)
    return true;

  TUint_2 MallocAddr = (TUint_2) malloc(Size);

  if (MallocAddr == 0)
    return false;

  MemSeg->Start.Addr = MallocAddr;
  MemSeg->Size = Size;

  ZeroMem(*MemSeg);

  /*
  printf("( Reserve\n");
  me_MemorySegment::PrintWrappings(MemSeg);
  printf(") Reserve\n");
  //*/

  return true;
}

/*
  Release block of memory. Zero before release

  Implemented as wrapper over free().
*/
void me_ManagedMemory::Freetown::Release(
  TMemorySegment * MemSeg
)
{
  /*
  printf("( Release\n");
  me_MemorySegment::PrintWrappings(MemSeg);
  printf(") Release\n");
  //*/

  ZeroMem(*MemSeg);

  // Zero size? Job done!
  if (MemSeg->Size == 0)
    return;

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
*/