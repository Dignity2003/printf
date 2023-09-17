#include "main.h"
#include <stdio.h>
int main()
{
int count = _printf("Hello, %c world! %s %%\n", 'C', "printf");
printf("\nNumber of characters printed: %d\n", count);
return 0;
}
