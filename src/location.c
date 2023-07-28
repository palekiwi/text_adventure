#include "misc.h"
#include "noun.h"
#include "object.h"
#include <stdio.h>
#include <string.h>
#include "location.h"

void executeLook(const char *noun) {
  if (noun != NULL && strcmp(noun, "around") == 0) {
    printf("You are in %s.\n", player->location->description);
    listObjectsAtLocation(player->location);
  } else {
    printf("I don't understand what you want to see.\n");
  }
}

void executeGo(const char *noun) {
  OBJECT *obj = getVisible("where you want to go", noun);

  if (obj->location == NULL && obj != player->location) {
    printf("OK.\n");
    player->location = obj;
  } else {
    printf("I don't know where you want to go.\n");
  }
}
