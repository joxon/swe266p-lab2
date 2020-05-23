#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char all[49] = "1970\n\nM\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxM^bi$^id$";

    char* name = all + 8;

    char* gender = name + 32;
    *gender = 'M';

    int* birth = (int*) (name + 33);
    *birth = 1970;

    int* id = (int*) (name + 37);
    *id = 13371337;

    FILE* file = fopen("w2.txt", "w");
    fwrite(all, sizeof(char), sizeof(all), file);
    fclose(file);

    return 0;
}
