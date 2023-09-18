#include "main.h"
#include <stdio.h>
int main()
{
int count = _printf("Hello, %c world! %s %% - NUMBER: %d\n", 'C', "printf", -10123);
printf("\nNumber of characters printed: %d\n", count);
return 0;
}
