// Have a guard to ensure that we don't include it multiple times.
#ifndef _COOLBEARS_H_
/* checkInput: given the result of scanf check if it 
 * 0 elements read or EOF. If so exit(1) with a warning.
 *
 */
#define _COOLBEARS_H_
struct coolbear_t; // Forward declaration -- I am not sharing details!
typedef struct coolbear_t * CoolBear; // Struct point as type

CoolBear createCoolBear(char * name, float temperature); // a prototype!
void     freeCoolBear(CoolBear coolBear); // a prototype!
char *   getNameCoolBear(CoolBear coolbear); // a prototype!
float    getTemperatureCoolBear(CoolBear coolbear); // a prototype!

#endif
