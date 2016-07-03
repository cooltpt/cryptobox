#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* uuidgen | sed 's/[^a-zA-Z0-9]//g' */
/* .. or .. uuidgen | tr "[:lower:]" "[:upper:]" | sed 's/[^A-Z0-9]//g' */
/* results in a base-36 char */

#define KEYBLOCKLEN 65536  // 2^16

int main(int argc, char* argv[])
{
   size_t i, count;
   char buf[128];
   
   count = 0;
   
   while (count < KEYBLOCKLEN)
   {
      FILE* pipe = popen("uuidgen | sed \'s/[^a-zA-Z0-9]//g\'", "r");
      if (!pipe) break;
      
      while (fgets(buf, sizeof(buf), pipe))
      {
         buf[strlen(buf)-1] = 0;
         printf("\n\n/* %s */\n", buf);
         
         for (i = 0; i < strlen(buf) && count < KEYBLOCKLEN; i++)
         {
            if (i % 5 == 0) printf("\n    ");
            printf("keyblock[%5zu] = 0x%02X; ", count++, buf[i]);
         }
      }
      
      pclose(pipe);
   }
   
   return 0;
}
