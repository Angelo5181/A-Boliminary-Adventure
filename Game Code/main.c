#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MAGICLIST_C
  #define MAGICLIST_C
  #include "magiclist.c"
#endif

#ifndef CHARACTER_C
  #define CHARACTER_C
  #include "character.c"
#endif

#ifndef FIGHT_C
  #define FIGHT_C
  #include "fight.c"
#endif

int main() {
  srand(time(NULL));
  
  char defaultCharacterName[22] = "Sentient Rock";
  signed int health = rand() % 15 + 11;
  signed int maxHealth = health;
  signed int maxMagic = 0;
  signed int magic = maxMagic;
  signed int attackPower = 1;
  bool isPlayer = false;

  struct character enemy = {
    "N/A",
    maxHealth,
    health,
    maxMagic,
    magic,
    attackPower,
    isPlayer
  };
  strcpy(enemy.name, defaultCharacterName);

  maxHealth = 30;
  health = maxHealth;
  maxMagic = 10;
  magic = maxMagic;
  attackPower = 5;
  isPlayer = false;

  struct character player = {
    "Player",
    maxHealth,
    health,
    maxMagic,
    magic,
    attackPower,
    isPlayer
  };

  char name[20];
  printf("Enter a name\n--------------------\n");
  fgets(name, sizeof(name), stdin);
  int nameLength = strlen(name);
  if (name[nameLength - 1] == '\n') name[nameLength - 1] = '\0';
  strcpy(player.name, name);
  printf("\n");

  char illegalName[7] = "Peanut";
  int PeanutNotDetected = strcmp(player.name, illegalName);
  if (!PeanutNotDetected) {
    printf("PEANUT DETECTED!!!\n");
    enemy.atk *= 10;
    strcpy(enemy.name, "Peanut Crusher");
  }

  char legalName[7] = "Walnut";
  int WalnutNotDetected = strcmp(player.name, legalName);
  if (!WalnutNotDetected) { // Geez, really going all in on the double negatives huh?
    printf("Wow... I can't believe it! IT'S A WALNUT!!!\n");
    printf("Rocks must obey the walnut.");
    enemy.hp -= 10;
    strcpy(enemy.name, "Walnut Obeyer");
  }

  fight(player,enemy);

  return 0;
}