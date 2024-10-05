// [me_ManagedMemory] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-10-05
*/

#include <me_ManagedMemory.h>

#include <me_UartSpeeds.h>
#include <me_InstallStandardStreams.h>
#include <me_BaseTypes.h>

void setup()
{
  Serial.begin(me_UartSpeeds::Arduino_Normal_Bps);
  InstallStandardStreams();
  printf("[me_ManagedMemory] Okay, we are here.\n");
  RunTest();
  printf("[me_ManagedMemory] Done.\n");
}

void loop()
{
}

// --

void RunTest()
{
  printf(
    PSTR(
      "This library manages heap span.\n"
      "\n"
      "Class manages loading data, resizing and debug print.\n"
      "Free functions handle heap memory allocations, zeroing\n"
      "and copying.\n"
      "\n"
      "In this example we'll use one instance with different\n"
      "values. Idea is to demonstrate that memory span for data\n"
      "is reused.\n"
      "\n"
    )
  );

  using
    me_ManagedMemory::TManagedMemory,
    me_MemorySegment::Freetown::Print;

  TManagedMemory Chunk;

  Chunk.PrintWrappings();
  printf("\n");

  Chunk.LoadFrom("ABC");
  Chunk.PrintWrappings();
  printf("\n");

  Chunk.LoadFrom("12345");
  Chunk.PrintWrappings();
  printf("\n");

  Chunk.LoadFrom("ab");
  Chunk.PrintWrappings();
  printf("\n");
}

/*
  2024-06-02
  2024-07-06
  2024-10-05
*/
