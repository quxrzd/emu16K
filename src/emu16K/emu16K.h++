// emu16K.c++
// written by rezoid.

// emu16K is dedicated to the public domain.
// attribution appreciated; not required.


/*
   this H++ file defines functions associated with the
   emu16K class, whom of which is also defined here. it
   also defines constants like maximum integer values.
*/


// definitions & includes =================================
#ifndef EMU16K_H
#define EMU16K_H

// macros:
#define MAX_u24 ((1u << 24) - 1)
#define MAX_u16 ((1u << 16) - 1)
#define MAX_u08 ((1u <<  8) - 1)
#define MAX_i24 ((1u << 23) - 1)
#define MAX_i16 ((1u << 15) - 1)
#define MAX_i08 ((1u <<  7) - 1)

// these typedefs look better in my opinion:
typedef unsigned char	u08;
typedef unsigned short	u16;
typedef unsigned int		u32;
typedef char				i08;
typedef short				i16;
typedef int					i32;
typedef bool				bit;
typedef void				nll;

// helper functions:
inline u08 bitpos_u08 (u08 byt, u08 loc)
{
   return (byt & (1 << loc));
}
inline u16 bitpos_u16 (u16 wrd, u16 loc)
{
   return (wrd & (1 << loc));
}
inline u32 bitpos_u32 (u32 dwd, u32 loc)
{
   return (dwd & (1 << loc));
}


// emu16K class definition ================================
class emu16K
{
   private:
   // rzd16K registers:
   u16 A, B, C, D;
   u32 Y, Z, I, S;
   u08 F;
   // emu16K variables:
   u08 µ;
   // emu16K functions:
   u08 chkint ();

public:
   emu16K (u08 &status)
   {
      status = chkint ();
   }
   // functions used by the program using emu16K:
   nll rst (nll);
   u08 cyc (nll);

   // implemented by the program using emu16K:
   u08 rdb (u32 adr);
   nll wrb (u32 adr, u08 val);
};

#endif
