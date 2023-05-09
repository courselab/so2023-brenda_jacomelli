#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *hex_file, *bin_file;
    int val;

    hex_file = fopen("hw.hex", "r");

    if(hex_file == NULL){
        printf("Error opening .hex file");
        return 0;
    }

    bin_file = fopen("hw-hex.bin", "wb");

    if(hex_file == NULL){
        printf("Error opening .bin file");
        return 0;
    }

    while ( fscanf (hex_file, "%2x", &val) >= 0){
        fputc (val, bin_file);
    }
      

    fclose(hex_file);
    fclose(bin_file);

    return 0;
}