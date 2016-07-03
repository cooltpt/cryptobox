#include <stdio.h>

int main(int argc, char* argv[])
{
   FILE* f;
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
   
   fseek(f,    580, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,    687, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   1221, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   1284, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   1298, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   1395, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   1604, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   1608, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   2000, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   2017, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   2174, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   2561, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   3110, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   3632, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4192, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4202, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4363, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4390, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4610, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4678, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4806, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4840, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4866, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   4881, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5041, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5048, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5107, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5181, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5281, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5443, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5491, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5547, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5581, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   5837, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   6337, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   6637, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   6827, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   6888, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   6907, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   7356, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   7611, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   7650, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   8249, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   8303, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   9120, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   9325, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   9418, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   9631, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   9737, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   9823, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,   9872, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  10293, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  10412, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  10933, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  11015, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  11515, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  11523, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  11697, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  12009, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  12097, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  12125, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  12505, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  12511, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  12545, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  13158, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  13390, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  13404, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  14479, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  14588, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  14797, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  15300, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  15341, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);
   fseek(f,  15359, SEEK_SET); ch = (unsigned char)fgetc(f); putchar(ch);

   return 0;
}

