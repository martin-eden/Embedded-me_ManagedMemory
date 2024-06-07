// Memory segment in dynamic memory management

/*
  Author: Martin Eden
  Last mod.: 2024-06-04
*/

#include "me_ManagedMemory.h"

#include <stdio.h> // printf()

using
  me_ManagedMemory::TManagedMemory,
  me_BaseTypes::TUint_2,
  me_BaseTypes::TBool,
  me_BaseTypes::TChar,
  me_MemorySegment::TMemorySegment;

TManagedMemory::~TManagedMemory()
{
  Release();
}

// Print our address to stdout
void TManagedMemory::PrintTag()
{
  printf("[TManagedMemory 0x%04X]", (TUint_2) this);
}

// Print our data to stdout
void TManagedMemory::PrintWrappings()
{
  printf("(");
  Data.PrintWrappings();
  printf(")");
}

// Print raw data to stdout
void TManagedMemory::Print()
{
  Data.Print();
}

// Release memory. We are relying on idempotence of implementation.
void TManagedMemory::Release()
{
  /*
  printf("TManagedMemory::Release()\n");
  Data.PrintWrappings();
  printf("\n");
  */

  Data.Release();
}

me_MemorySegment::TMemorySegment TManagedMemory::Get()
{
  return Data;
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
      Theoretically CopyMemFrom() fails when our span intersects with
      <Src>. Practically it's unlikely but anyway.
    */
    Data.Release();
    return false;
  }

  return true;
}

// Create copy from ASCIIZ
TBool TManagedMemory::Set(const TChar * Asciiz)
{
  using me_MemorySegment::FromAsciiz;
  return Set(FromAsciiz(Asciiz));
}

// Create copy from our specie
TBool TManagedMemory::Set(TManagedMemory * Src)
{
  return Set(Src->Get());
}

/*
  2024-06-02
  2024-06-04
*/
