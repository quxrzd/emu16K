// emu16K.c++
// written by rezoid.

// emu16K is dedicated to the public domain.
// attribution appreciated; not required.


// definitions & includes =================================
#ifndef EMU16K_H
#define EMU16K_H

#define U24 ((1u << 24) - 1)
#define U16 ((1u << 16) - 1)
#define U08 ((1u <<  8) - 1)

#include <stdint.h>

// emu16K class definition ================================
class emu16K
{
private:
      // rzd16K registers:
      uint16_t A, B, C, D;
      uint32_t Q, R, I, S;
      uint8_t  F;
      // emu16K variables:
      uint8_t  µ;

public:
      void		rst (void);
      uint8_t	cyc (void);
      // implemented by the software using emu16K:
      uint8_t	rdb (uint32_t adr);
      void		wrb (uint32_t adr, uint8_t val);
};

#endif
