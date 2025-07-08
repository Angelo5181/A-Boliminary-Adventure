#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#ifndef MAGICLIST_C
#define MAGICLIST_C
#include "magiclist.c"
#endif

//if not specified, assume int
//struct character example = {char name[22], maxhp, hp, maxmp, mp, atk, bool player};
#ifndef CHARACTER_C
#define CHARACTER_C
#include "character.c"
#endif

#ifndef FIGHT_C
#define FIGHT_C
#include "fight.c"
#endif

int main() {
  srand(time(NULL));//for randomHealth
  int randomHealth = rand() % 15 + 11;

  //make characters for player and enemy
  struct character player = {"N/A", 30, 30, 10, 10, 5, true};
  char name[20];
  printf("Enter a name\n--------------------\n");
  fgets(name, sizeof(name), stdin);
  int namelength = strlen(name);
  if(name[namelength-1] == '\n'){
    name[namelength-1] = '\0';
  }
  strcpy(player.name, name);
  printf("\n");

  struct character enemy = {"Sentient Rock", randomHealth, randomHealth, 0, 0, 1, false};

  char illegalName[7] = "Peanut";
  int PeanutNotDetected = strcmp(player.name, illegalName);
  if (!PeanutNotDetected) {
    printf("PEANUT DETECTED!!!\n");
    enemy.atk *=10;
    strcpy(enemy.name, "Peanut Crusher");
  }

  char legalName[7] = "Walnut";
  int WalnutNotDetected = strcmp(player.name, legalName);
  if (!WalnutNotDetected) {
    printf("Wow... I can't believe it! IT'S A WALNUT!!!\n");
    printf("Rocks must obey the walnut.");
    enemy.hp -= 10;
    strcpy(enemy.name, "Walnut Obeyer");
  }
  // printf("Enter a name for the enemy: ");
  // fgets(name, sizeof(name), stdin);
  // printf("\n");
  // strcpy(enemy.name, name);
  //
  // Don't want to have to spam "asd" twice now, do we?

  //battle loop
  fight(player,enemy);
  //end of battle loop
  return 0;
}