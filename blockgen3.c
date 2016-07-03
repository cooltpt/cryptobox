#include <stdio.h>

/* discerns hidden message.. then $ ./blockgen3 msg.dat > steg.c   .. and edit the file*/

unsigned char msg[128];
void msg_init();

int main(int argc, char* argv[])
{
   FILE* f;
   size_t count, pos;
   unsigned char ch;

   if (argc < 2)
   {
      printf("USAGE: %s <filename>\n", argv[0]);
      return 0;
   }
   
   f = fopen(argv[1], "r");
   if (!f)
   {
      perror(argv[1]);
      return 1;
   }
   
   pos = count = 0;
#if 0  // create msg_init
   while(!feof(f))
   {
      ch = (unsigned char)fgetc(f);      
      if (count % 5 == 0) printf("\n");
      printf("   msg[%5zu] = 0x%02X; ", count++, (int)ch);
   }
#else // gen stego
   msg_init();
   while(1)
   {
      ch = (unsigned char)fgetc(f);
      if (feof(f))
      {
         fseek(f, 0, SEEK_SET);
         printf("SEEK TOP\n");
         pos = 0;
         continue;
      }
      
      if (ch == msg[count])
      {
         printf("   fseek(f, %6zu, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);\n", pos);
         if (++count > 72) break;
      }
      
      pos++;
   }
#endif
   
   fclose(f);
   
   putchar('\n');
      
   return 0;
}

void msg_init()
{
   msg[    0] = 0x04;    msg[    1] = 0xFA;    msg[    2] = 0x29;    msg[    3] = 0x82;    msg[    4] = 0xB0; 
   msg[    5] = 0xED;    msg[    6] = 0x85;    msg[    7] = 0x0B;    msg[    8] = 0x10;    msg[    9] = 0xF7; 
   msg[   10] = 0x62;    msg[   11] = 0xA0;    msg[   12] = 0xC1;    msg[   13] = 0xE3;    msg[   14] = 0x3B; 
   msg[   15] = 0xB5;    msg[   16] = 0x0B;    msg[   17] = 0xA6;    msg[   18] = 0x68;    msg[   19] = 0xA2; 
   msg[   20] = 0xB9;    msg[   21] = 0x15;    msg[   22] = 0x70;    msg[   23] = 0x2A;    msg[   24] = 0xAF; 
   msg[   25] = 0xCD;    msg[   26] = 0x98;    msg[   27] = 0x01;    msg[   28] = 0xA0;    msg[   29] = 0x85; 
   msg[   30] = 0xE2;    msg[   31] = 0xAA;    msg[   32] = 0xBC;    msg[   33] = 0x65;    msg[   34] = 0x70; 
   msg[   35] = 0x02;    msg[   36] = 0x1A;    msg[   37] = 0xC3;    msg[   38] = 0xDE;    msg[   39] = 0x77; 
   msg[   40] = 0xA3;    msg[   41] = 0xAA;    msg[   42] = 0xF4;    msg[   43] = 0x91;    msg[   44] = 0xDE; 
   msg[   45] = 0xBD;    msg[   46] = 0x53;    msg[   47] = 0x05;    msg[   48] = 0x55;    msg[   49] = 0xBD; 
   msg[   50] = 0xC2;    msg[   51] = 0x09;    msg[   52] = 0xAD;    msg[   53] = 0x80;    msg[   54] = 0x69; 
   msg[   55] = 0xAB;    msg[   56] = 0xA2;    msg[   57] = 0xAB;    msg[   58] = 0xC4;    msg[   59] = 0xBD; 
   msg[   60] = 0xB3;    msg[   61] = 0xBC;    msg[   62] = 0xD8;    msg[   63] = 0xBC;    msg[   64] = 0x1E; 
   msg[   65] = 0xB1;    msg[   66] = 0xB3;    msg[   67] = 0xBB;    msg[   68] = 0x29;    msg[   69] = 0xB7; 
   msg[   70] = 0x7A;    msg[   71] = 0x18;    msg[   72] = 0xCD;
}
