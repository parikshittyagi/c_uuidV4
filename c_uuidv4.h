#ifndef __C_UUIDV4_H
#define __C_UUIDV4_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>


//Declaring GUID 16 octects according to RFC4122 https://tools.ietf.org/html/rfc4122
typedef unsigned char uuid_t[16];

//UUID structure defined as mentioned in RFC4122
struct uuid
{
    uint32_t     time_low;
    uint16_t     time_mid;
    uint16_t     time_hi_and_version;
    uint16_t     clock_seq;
    uint8_t      node[6];
};

//UUID comes in lower and upper cases, to convert the GUID returned and changing it to lower format
static const char *fmt_lower =
	"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x";

/**
 * Fucntion prototypes defined here
*/
static int random_get_fd(void);
static void random_get_bytes(void *buf, size_t nbytes);
void __uuid_generate_random(uuid_t out, int *num);
static void uuid_unpack(const uuid_t in, struct uuid *uu);
static void uuid_pack(const struct uuid *uu, uuid_t ptr);
void uuid_unparse_lower(const uuid_t uu, char *out);
static void uuid_unparse_x(const uuid_t uu, char *out, const char *fmt);

#endif