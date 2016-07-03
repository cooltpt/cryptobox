#pragma once

#include <vector>
#include <map>
#include <cstdlib>

#define KEYBLOCKLEN 65536

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;

typedef union
{
   uchar     val[8];
   ushort    s  [4];
   uint      i  [2];
   unsigned long int l;
}
keyblock_u;

class Keyblock
{
   uint mult;
   std::map<uint,uint> vals;
   std::vector<uchar> deck;
      
   void init();
   uchar get(size_t idx);
   uchar sig_char(uchar ch);
   uchar crc_char(const uchar* bias, size_t len, uint ctx);

protected:

   uchar* block;
   virtual void loadBlock() = 0;

public:
   
   Keyblock();
   virtual ~Keyblock();
   
   virtual void coder(uchar* dat, size_t len, const char* bias, uint hashSize, uint hashRev, uint algo);
};
