// emu16K.c++
// written by rezoid.

// emu16K is dedicated to the public domain.
// attribution appreciated; not required.


/*
   this C++ file implements the emu16K class and functions
   as specified in the emu16K.h++ file and implements the
   instruction set architecture of the rzd16K here as well.
*/


// definitions & includes =================================
#include "emu16K.h++"

// function implementations ===============================
// ------ private functions -------------------------------
u08 emu16K::chkint ()
{
   u08 status = 0b0000;

   if (sizeof(bit) * 8 != 8)
   {
      status = status | (1 << 4);
   }
   if (sizeof(u08) * 8 != 8)
   {
      status = status | (1 << 5);
   }
   if (sizeof(u16) * 8 != 16)
   {
      status = status | (1 << 6);
   }
   if (sizeof(u32) * 8 != 32)
   {
      status = status | (1 << 7);
   }

   return status;
}

// ------ public functions --------------------------------
nll emu16K::rst ()
{
   /*
      the rzd16K has nine registers in total.
      -	four sixteen-bit general purpose registers:
         A, B, C, and D.
      -	two twenty-four-bit address registers: Y and Z.
      -	a twenty-four-bit instruction pointer: I.
      -	a twenty-four-bit stack pointer: S.
      -	an eight-bit flags register: F.
   */

   A = B = C = D = 0x0000;		// 16-bit registers.
   Y = Z = I = S = 0x000000;	// 24-bit registers.
   F = 0x00; 						//  8-bit registers.
}
