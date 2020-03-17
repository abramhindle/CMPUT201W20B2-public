#include "coolbears.h"
#include <stdio.h>

int main() {
  CoolBear ziggy = createCoolBear("Ziggy",-23.0 /* C */);
  CoolBear kevin = createCoolBear("Kevin",-32.0 /* C */);
  CoolBear coolest = (getTemperatureCoolBear(ziggy) < 
                      getTemperatureCoolBear(kevin))? ziggy : kevin;
  printf("The coolest bear is %s\n", getNameCoolBear( coolest ));
  // // we actually don't know about name so we can't reference it below
  // printf("The coolest bear is %s\n", getNameCoolBear( coolest->name ));
  freeCoolBear(ziggy);
  freeCoolBear(kevin);
}
