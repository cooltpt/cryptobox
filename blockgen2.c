#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* base-256 */

#define KEYBLOCKLEN 65536  // 2^16

int main(int argc, char* argv[])
{
   size_t count;
   unsigned char ch, *p;
   
   count = 0;
   
   srand(time(0));
   
   while (count < KEYBLOCKLEN)
   {
      int rnd = rand();
      p = (unsigned char*)&rnd;
            
      printf("\n\n   /* %u */\n", rnd);
      ch = *p++; printf("   keyblock[%5zu] = 0x%02X; ", count++, (int)ch);
      ch = *p++; printf("   keyblock[%5zu] = 0x%02X; ", count++, (int)ch);
      ch = *p++; printf("   keyblock[%5zu] = 0x%02X; ", count++, (int)ch);
      ch = *p++; printf("   keyblock[%5zu] = 0x%02X; ", count++, (int)ch);
   }
   
   return 0;
}
