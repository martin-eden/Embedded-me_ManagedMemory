// Manager for memory segment in dynamic memory

/*
  Author: Martin Eden
  Last mod.: 2024-10-05
*/

#include "me_ManagedMemory.h"

#include <stdio.h> // printf() for PrintWrappings()

using
  me_ManagedMemory::TManagedMemory,
  me_MemorySegment::TMemorySegment;

/*
  Destructor

  Release memory.
*/
TManagedMemory::~TManagedMemory()
{
  Release();
}

/*
  Return our data segment

  We're not working with data at span. We're managing span.
  Here we're returning data span for processing. We hope they
  won't call free() on it.
*/
TMemorySegment TManagedMemory::GetData()
{
  return DataSeg;
}

/*
  Return data segment size
*/
TUint_2 TManagedMemory::GetSize()
{
  return DataSeg.Size;
}

/*
  Grow or shrink data segment

  In case of shrink, data is truncated. In case of grow,
  it's filled with zero bytes.

  If there's no memory of some other issues, we'll return
  false and try to preserve what we can.
*/
TBool TManagedMemory::ResizeTo(
  TUint_2 NewSize
)
{
  TMemorySegment NewSeg;

  if (!Freetown::Reserve(&NewSeg, NewSize))
    return false;

  if (!Freetown::CopyMemTo(NewSeg, DataSeg))
    return false;

  Freetown::Release(&DataSeg);

  DataSeg = NewSeg;

  return true;
}

/*
  Free data segment memory

  We're just resizing to zero.
*/
void TManagedMemory::Release()
{
  ResizeTo(0);
}

/*
  Load from memory segment
*/
TBool TManagedMemory::LoadFrom(
  TMemorySegment Src
)
{
  if (!ResizeTo(Src.Size))
    return false;

  if (!Freetown::CopyMemTo(DataSeg, Src))
    return false;

  return true;
}

/*
  Load from ASCIIZ
*/
TBool TManagedMemory::LoadFrom(
  const TChar * Asciiz
)
{
  // Cast ASCIIZ to memseg and load
  return LoadFrom(me_MemorySegment::Freetown::FromAsciiz(Asciiz));
}

/*
  Load from our specie
*/
TBool TManagedMemory::LoadFrom(
  TManagedMemory * Src
)
{
  // Get data seg and load
  return LoadFrom(Src->GetData());
}

/*
  2024-06-02
  2024-06-04
  2024-06-15
  2024-07-06
  2024-10-05
  2024-10-07
*/
