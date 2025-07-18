#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef TYPEWRITER_C
#define TYPEWRITER_C
#include "typewriter.c"
#endif

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

  //get amount of players
  int playerCount = -1;
  while(playerCount < 1 || playerCount > 5){
    printf("Enter player count: (At least 1, max 5)\n");
    scanf("%d",&playerCount);
    getchar();
  }
  printf("playerCount:%d\n",playerCount);

  //get amount of enemies
  int enemyCount = -1;
  while(enemyCount < 1 || enemyCount > 5){
    printf("Enter enemy count: (At least 1, max 5)\n");
    scanf("%d",&enemyCount);
    getchar();
  }
  printf("enemyCount:%d\n",enemyCount);

  //make characters for player
  int maxHealth = 30;
  int health = maxHealth;
  int maxMagicPoints = 10;
  int magicPoints = maxMagicPoints;
  int attack = 5;
  bool isPlayer = true;
  for(int i = 0; i < playerCount; i++){
    struct character player = {"N/A", maxHealth, health, maxMagicPoints, magicPoints, attack, isPlayer};
    char name[20];
    printf("Enter a name for player %d\n--------------------\n",(i+1));
    fgets(name, sizeof(name), stdin);
    int namelength = strlen(name);
    if(name[namelength-1] == '\n'){
      name[namelength-1] = '\0';
    }
    strcpy(player.name, name);
    printf("\n");
    characterList[i] = player;
  }

  for(int i = 0; i < enemyCount; i++){
    struct character enemy = {"Sentient Rock", randomHealth, randomHealth, maxMagicPoints, magicPoints, attack, isPlayer};
    randomHealth = rand() % 15 + 11;
    enemyList[i] = enemy;
  }
  // printf("Enter a name for the enemy: ");
  // fgets(name, sizeof(name), stdin);
  // printf("\n");
  // strcpy(enemy.name, name);
  //
  // Don't want to have to spam "asd" twice now, do we?

  //funny name: "peanut"
  char illegalName[7] = "peanut";
  int PeanutNotDetected;
  int peanutCount = 0;
  for(int i = 0; i < playerCount; i++){

    PeanutNotDetected = strcmp(characterList[i].name, illegalName);
    if (!PeanutNotDetected) {
      peanutCount++;
      printf("PEANUT DETECTED!!! (%d)\n",peanutCount);
      for(int e = 0; e < enemyCount; e++){
        enemyList[e].atk *= 2;
        enemyList[e].hp += 15;
      strcpy(enemyList[e].name, "Peanut Crusher");
      }
    }
  }
  if(peanutCount > 4){
    for(int e = 0; e < enemyCount; e++){
      strcpy(enemyList[e].name, "Peanut Obliterator");
      enemyList[e].atk = 999;
      enemyList[e].hp = 999999;
    }
  }
  //funny name: "Walnut"
  char legalName[7] = "walnut";
  int WalnutNotDetected;
  for(int i = 0; i < playerCount; i++){
    WalnutNotDetected = strcmp(characterList[i].name, legalName);
      if (!WalnutNotDetected) {
      printf("Wow... I can't believe it! IT'S A WALNUT!!!\n");
      printf("Rocks fear the walnut.\n");
      for(int e = 0; e < enemyCount; e++){
        enemyList[e].hp -= 10;
        strcpy(enemyList[i].name, "Scared of Walnuts");
      }
      break;
    }
  }

  //battle loop
  if (playerCount == 1 && enemyCount == 1){
    fight(characterList[0],enemyList[0]);
  }
  else {
    teamFight(playerCount,enemyCount,characterList,enemyList);
  }
  //end of battle loop
  return 0;
}