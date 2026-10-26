// emu16K.c++
// written by rezoid.

// emu16K is dedicated to the public domain.
// attribution appreciated; not required.


// definitions & includes =================================
#include "emu16K.h++"

// function implementations ===============================
void emu16K::rst ()
{
   /*
      the rzd16K has nine registers in total.
      -	four sixteen-bit general purpose registers:
         A, B, C, and D.
      -	two twenty-four-bit address registers: Q and R.
      -	a twenty-four-bit instruction pointer: I.
      -	a twenty-four-bit stack pointer: S.
      -	an eight-bit flags register: F.
   */

   A = B = C = D = 0x0000;		// 16-bit registers.
   Q = R = I = S = 0x000000;	// 24-bit registers.
   F = 0x00;						//  8-bit registers.
}
