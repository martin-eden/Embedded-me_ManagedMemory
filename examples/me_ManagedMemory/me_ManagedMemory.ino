// [me_ManagedMemory] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-10-09
*/

#include <me_ManagedMemory.h>

#include <me_BaseTypes.h>
#include <me_UartSpeeds.h>
#include <me_Console.h>

void setup()
{
  Console.Init(me_UartSpeeds::Arduino_Normal_Bps);

  Console.Print("[me_ManagedMemory] Okay, we are here.");
  RunTest();
  Console.Print("[me_ManagedMemory] Done.");
  Console.Flush();
}

void loop()
{
}

// --

void RunTest()
{
  // Two Console.Newline()'s does not produce empty line. Workaround. Sorry.
  printf("\n");

  // Progmem strings are not yet supported by [me_Console], so printf()
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
    )
  );

  using
    me_ManagedMemory::TManagedMemory,
    me_MemorySegment::Freetown::PrintWrappings;

  TManagedMemory Chunk;

  PrintWrappings(Chunk.GetData());
  printf("\n");

  Chunk.LoadFrom("ABC");
  PrintWrappings(Chunk.GetData());
  printf("\n");

  Chunk.LoadFrom("12345");
  PrintWrappings(Chunk.GetData());
  printf("\n");

  Chunk.LoadFrom("ab");
  PrintWrappings(Chunk.GetData());
  printf("\n");
}

/*
  2024-06-02
  2024-07-06
  2024-10-05
  2024-10-09
*/
