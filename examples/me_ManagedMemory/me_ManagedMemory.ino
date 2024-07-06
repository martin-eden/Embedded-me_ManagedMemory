// [me_ManagedMemory] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-07-06
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
  Test();
  printf("Done.\n");
}

void loop()
{
}

void Test()
{
  using
    me_ManagedMemory::TManagedMemory;

  TManagedMemory Chunk;

  Chunk.PrintWrappings();
  Chunk.Print();
  printf("\n");

  Chunk.Set("Test ABC");

  Chunk.PrintWrappings();
  Chunk.Print();
  printf("\n");

  Chunk.Set("Test 2");

  Chunk.PrintWrappings();
  Chunk.Print();
  printf("\n");

}

/*
  2024-06-02
  2024-07-06
*/
