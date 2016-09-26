#include <string.h>

// X Macros example


typedef struct
{
    #define PROCESS(type, member) type member;
    #include "components.h"
    #undef PROCESS
} particle_t;

void save(particle_t const *p, unsigned char *data)
{
    #define PROCESS(type, member)                       \
        memmove(data, &(p->member), sizeof(p->member)); \
        data += sizeof(p->member);                      \

    #include "components.h"
    #undef PROCESS
}

int main(int argc, char **argv)
{
    unsigned char data[1024] = {0};
    particle_t particle = {
        #define PROCESS(type, member) .member = 42,
        #include "components.h"
        #undef PROCESS
    };
    save(&particle, data);
    return 0;
}
