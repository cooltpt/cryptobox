#pragma once

#include "Keyblock.h"

class Keyblock3 : public Keyblock
{
   void loadBlock();
public:
   Keyblock3() : Keyblock()
   {
      loadBlock();
   }
};
