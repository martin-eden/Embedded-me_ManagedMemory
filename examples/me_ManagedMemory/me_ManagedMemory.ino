// [me_ManagedMemory] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-10-10
*/

#include <me_ManagedMemory.h>

#include <me_BaseTypes.h>
#include <me_UartSpeeds.h>
#include <me_Console.h>
#include <me_InstallStandardStreams.h>

void setup()
{
  InstallStandardStreams();
  Console.Init(me_UartSpeeds::Arduino_Normal_Bps);

  Console.Print("[me_ManagedMemory] Okay, we are here.");
  Console.Indent();
  RunTest();
  Console.Unindent();
  Console.Print("[me_ManagedMemory] Done.");
  Console.Flush();
}

void loop()
{
}

// --

void RunTest()
{
  Console.Print("");

  Console.Print("This library manages heap span.");
  Console.Print("");
  Console.Print("Class manages loading data and resizing. Free functions");
  Console.Print("handle heap memory allocations, zeroing and copying.");
  Console.Print("");
  Console.Print("In this example we'll use one instance with different");
  Console.Print("values. Idea is to demonstrate that memory span for data");
  Console.Print("is reused.");
  Console.Print("");

  using
    me_ManagedMemory::TManagedMemory,
    me_MemorySegment::Freetown::PrintWrappings;

  TManagedMemory Chunk;

  PrintWrappings(Chunk.GetData());
  Console.Print("");

  Chunk.LoadFrom("ABC");
  PrintWrappings(Chunk.GetData());
  Console.Print("");

  Chunk.LoadFrom("12345");
  PrintWrappings(Chunk.GetData());
  Console.Print("");

  Chunk.LoadFrom("ab");
  PrintWrappings(Chunk.GetData());
  Console.Print("");
}

/*
  2024-06-02
  2024-07-06
  2024-10-05
  2024-10-09
*/
