// Manager for memory segment in dynamic memory

/*
  Author: Martin Eden
  Last mod.: 2024-07-06
*/

#include "me_ManagedMemory.h"

#include <stdio.h> // printf()

using
  me_ManagedMemory::TManagedMemory,
  me_BaseTypes::TUint_2,
  me_BaseTypes::TBool,
  me_BaseTypes::TChar,
  me_MemorySegment::TMemorySegment;

/*
  Destructor

  Release data memory.
*/
TManagedMemory::~TManagedMemory()
{
  Release();
}

/*
  Release data memory
*/
void TManagedMemory::Release()
{
  Data.Release();
}

/*
  Allocate and copy memory from another segment.

  Previously allocated memory (if any) is released.
*/
TBool TManagedMemory::Set(TMemorySegment SrcSeg)
{
  Data.Release();

  if (!Data.Reserve(SrcSeg.Size))
    return false;

  if (!Data.CopyMemFrom(SrcSeg))
  {
    /*
      CopyMemFrom() will fail if our span intersects with <Src>.
      Practically it's unlikely but anyway.
    */
    Data.Release();
    return false;
  }

  return true;
}

/*
  Return data

  If we want to make things real secure, we should return copy of data.
  But as long as users do not call .Release() for that data, we may
  return our real data. Less pointless copies.
*/
TMemorySegment TManagedMemory::Get()
{
  return Data;
}

/*
  Create copy from ASCIIZ
*/
TBool TManagedMemory::Set(const TChar * Asciiz)
{
  return Set(me_MemorySegment::FromAsciiz(Asciiz));
}

/*
  Create copy from our specie
*/
TBool TManagedMemory::Set(TManagedMemory * Src)
{
  return Set(Src->Get());
}

/*
  Print our state to stdout
*/
void TManagedMemory::PrintWrappings()
{
  printf("[TManagedMemory 0x%04X]", (TUint_2) this);
  printf(" ");
  printf("(");
  Data.PrintWrappings();
  printf(")");
}

/*
  Print raw data to stdout
*/
void TManagedMemory::Print()
{
  Data.Print();
}

/*
  2024-06-02
  2024-06-04
  2024-06-15
*/
