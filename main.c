#include <stdio.h>
#include "c_uuidv4.h"

int main(int argc, const char *argv[])
{
    uuid_t binuuid;
    int num = 1;
    char *uuid = malloc(37);     //UUID of 36 length hence allocation 37 for 36 + '\0' 
    if (uuid == NULL)
    {
        fprintf(stderr, "Failed to provide memory for UUID\n");
    }
    __uuid_generate_random(binuuid, &num);                    //calling function to generate GUID
    uuid_unparse_lower(binuuid, uuid);
    printf("UUID -> %s\n", uuid);
    free(uuid);

    return 0;
}