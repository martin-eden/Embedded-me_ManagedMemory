// Memory segment in dynamic memory management

/*
  Author: Martin Eden
  Last mod.: 2024-06-02
*/

#include "me_ManagedMemory.h"

#include <stdio.h> // printf()

using
  me_ManagedMemory::TManagedMemory,
  me_BaseTypes::TBool,
  me_BaseTypes::TChar,
  me_BaseTypes::TUint_2,
  me_MemorySegment::TMemorySegment;

TManagedMemory::TManagedMemory()
{
  /*
  PrintTag();
  printf(" ");
  printf("Constructor.");
  printf("\n");
  Data.PrintWrappings();
  printf("\n");
  */
}

TManagedMemory::~TManagedMemory()
{
  /*
  PrintTag();
  printf(" ");
  printf("Destructor.");
  printf("\n");
  */

  Release();

  /*
  Data.PrintWrappings();
  printf("\n");
  */
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

void TManagedMemory::Release()
{
  Data.ReleaseChunk();
}

me_MemorySegment::TMemorySegment TManagedMemory::GetData()
{
  return Data;
}

TBool TManagedMemory::CloneFrom(
  TMemorySegment * SrcSeg
)
{
  return Data.CloneFrom(SrcSeg);
}

TBool TManagedMemory::CloneFrom(
  const TChar * Asciiz
)
{
  TMemorySegment TmpSeg;
  TmpSeg = me_MemorySegment::FromAsciiz(Asciiz);
  return CloneFrom(&TmpSeg);
}

TBool TManagedMemory::CloneFrom(
  TManagedMemory * Src
)
{
  TMemorySegment TmpSeg;
  TmpSeg = Src->GetData();
  return CloneFrom(&TmpSeg);
}

/*
  2024-06-02
*/
