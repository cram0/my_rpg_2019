#include "int_to_char.h"

int my_strlen(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count += 1;
    }

    return (count);
}

void reverse(char s[])
{
     int i, j;
     char c;

     for (i = 0, j = my_strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}
 
void itoa(int n, char s[])
{
     int i, sign;

     if ((sign = n) < 0)
         n = -n;
     i = 0;
     do {
         s[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
}  