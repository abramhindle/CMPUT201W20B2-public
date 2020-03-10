#define _POSIX_C_SOURCE 200809L // <-- needed for strdup
#include "coolbears.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// hiding struct details from other programmers
// I DONT TRUST THEM. Especially Hazel ;-) (don't tell hazel)
struct coolbear_t {
    char * name;
    float temperature;
};

CoolBear createCoolBear(char * name, float temperature) {
    CoolBear coolbear = malloc(sizeof(*coolbear));
    coolbear->name = strdup(name);
    coolbear->temperature = temperature;
    return coolbear;
}
void freeCoolBear(CoolBear coolBear) {
    if (coolBear == NULL) {
        abort();
    }
    if (coolBear->name != NULL) {
        free(coolBear->name);
    }
    free(coolBear);
}
char * getNameCoolBear(CoolBear coolbear) {
    return coolbear->name;
}
float    getTemperatureCoolBear(CoolBear coolbear) {
   return coolbear->temperature;
}
// NO MAIN!
