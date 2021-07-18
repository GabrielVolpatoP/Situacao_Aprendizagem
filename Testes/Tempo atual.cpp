#include <stdio.h>
#include <time.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese"); 
	

    const time_t timer = time(NULL);
    printf("ctime is %s\n", ctime(&timer));
    return 0;
}
