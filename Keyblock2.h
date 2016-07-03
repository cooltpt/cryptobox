#pragma once

#include "Keyblock.h"

class Keyblock2 : public Keyblock
{
   void loadBlock();
public:
   Keyblock2() : Keyblock()
   {
      loadBlock();
   }
};
