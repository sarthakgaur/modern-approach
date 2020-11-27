#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n);

int main(void) {
    int n;
    n = line_length("dump/foo.txt", 2);

    printf("len of line 3: %d\n", n);

    return 0;
}

int line_length(const char *filename, int n) {
   int ch, len, i = 1;
   FILE *fp = fopen(filename, "r");

   // forgot about EOF, file null pointer, and n == 0

   if (n == 0)
       return 0;

   if (fp == NULL) {
       printf("Error: could not open %s file.\n");
       exit(EXIT_FAILURE);
   }

   while (i != n) {
       while ((ch = getc(fp)) != '\n')
           if (ch == EOF)
               return 0;
       i++;
   }

   while ((ch = getc(fp)) != '\n' && ch != EOF)
       len++;

   fclose(fp);

   return len;
} 
