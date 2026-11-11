// emu.c++
// written by rezoid.

// emu16K is dedicated to the public domain.
// attribution appreciated; not required.


/*
   this C++ file checks known-good inputs and compares them
   to what the emulator outputs, acting as a validator for
   the rzd16K architecture and emu16K emulator.
*/


// definitions & includes =================================
#include <stdio.h>
#include "emu16K/emu16K.h++"

u08 men [MAX_u16] = {0x00};


// main function ==========================================
int main ()
{
   u08 s;
   bit c = 0;

   emu16K rzd16K (s);
   s = (s >> 4) & 0x0F;

   if (bitpos_u08 (s, 0))
   {
      puts ("!! \"bit\": type does not equal 8 bits.");
      c = 1;
   }
   if (bitpos_u08 (s, 1))
   {
      puts ("!! \"u08\": type does not equal 8 bits.");
      c = 1;
   }
   if (bitpos_u08 (s, 2))
   {
      puts ("!! \"u16\": type does not equal 16 bits.");
      c = 1;
   }
   if (bitpos_u08 (s, 3))
   {
      puts ("!! \"u32\": type does not equal 32 bits.");
      c = 1;
   }
   if (c != 0)
   {
      puts ("++ exiting...");
      return s;
   }

   rzd16K.rst ();

   puts ("## emu16K VALIDATOR PROGRAM");
   puts ("===========================");
   puts ("");

   return 0;
}
