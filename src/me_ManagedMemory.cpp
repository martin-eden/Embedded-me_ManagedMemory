// Memory segment in dynamic memory management

/*
  Author: Martin Eden
  Last mod.: 2024-06-02
*/

#include "me_ManagedMemory.h"

#include <stdio.h> // printf()

using
  me_ManagedMemory::TManagedMemory,
  me_BaseTypes::TUint_2;

TManagedMemory::TManagedMemory()
{
  PrintTag();
  printf(" ");
  printf("Constructor.");
  printf("\n");
  MemSeg.PrintWrappings();
  printf("\n");
}

TManagedMemory::~TManagedMemory()
{
  PrintTag();
  printf(" ");
  printf("Destructor.");
  printf("\n");
  MemSeg.PrintWrappings();
  printf("\n");
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
  MemSeg.PrintWrappings();
  printf(")");
}

/*
  2024-06-02
*/
