#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *id;
    char birth[] = "1970";
    char gender = 'M';
    char name[41] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    
    id = (int*) (&name[37]);
    *id = 13371337;
    
    printf("%s\n", name);
    printf("%s\n", birth);
    printf("\n%c\n", gender);
    
    return 0;
}
