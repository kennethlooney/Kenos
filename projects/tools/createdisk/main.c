 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fs/fat.h>

// 16:36 Protective MBR
bool write_mbr(FILE* image) {
    //TODO:
    Mbr mbr = {

    };

    // Write to file
    if(fwrite(&mbr, 1, sizeof mbr, image) != sizeof mbr)
        return false;

    

    return true;
}
char* image_name = "disk.img";
int main(void) {
    FILE *image = fopen(image_name, "wb+");
    if(!image)
    {
        fprintf(stderr,"Error: could not open file %s\n", image_name);
        return EXIT_FAILURE;
    }

    if(!write_mbr(image)) {
        fprintf(stderr,"Error: could not write protected MBR to file %s\n", image_name);
        return EXIT_FAILURE;
    }

    fclose(image);
    return EXIT_SUCCESS;
}