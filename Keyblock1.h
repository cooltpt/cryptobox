#pragma once

#include "Keyblock.h"

class Keyblock1 : public Keyblock
{
   void loadBlock();
public:
   Keyblock1() : Keyblock()
   {
      loadBlock();
   }
};
