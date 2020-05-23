#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char all[49] = "1970\n\nM\n";

    char name[41] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxM^bi$^id$";

    char* gender = (char*) (&name[32]);
    *gender = 'M';

    int* birth = (int*) (&name[33]);
    *birth = 1970;

    int* id = (int*) (&name[37]);
    *id = 13371337;

    for (int i = 0; i < 41; ++i){
        all[8+i] = name[i];
    }

    FILE* file = fopen("w2.txt", "w");
    fwrite(all, sizeof(char), sizeof(all), file);
    fclose(file);

    return 0;
}
