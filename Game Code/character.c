#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#include "delay.h"

struct character {
  char name[22];
  signed int hp;
  unsigned int mp;
  signed int atk;
  boolean player;
};

const unsigned int delay = 17; // in milliseconds

void printCharacter(struct character x) {
  if (x.player) printf("Name: %s", x.name);
  else printf("Name: %s\n", x.name);

  printf("HP: %d\n", x.hp);
  printf("MP: %d\n", x.mp);
  printf("ATK: %d\n\n", x.atk);
}

int isDead(struct character p, struct character e){
  if (p.hp <= 0) return 1;
  if (e.hp <= 0) return 2;
  return 0;
}

void typeWriter(char* text[15], unsigned int delay) {
  static int currentIndex = 0;

  if (currentIndex < strlen(*text)) {
    printf("%s", *(text + currentIndex));
    currentIndex++;
    setTimeout(typeWriter, delay);
  }

  else {
    currentIndex = 0;
    printf("\n");
    printf("Task successfully completed.\n");
  }
    
}

void printMagic() {
  char selectMagic[15] = "Select a magic.";
  printf("%s", selectMagic);
  char* text = selectMagic;
  strcpy(text, selectMagic);
  typeWriter(text[15], delay);
  Sleep(strlen(selectMagic) * delay);
} 


int main() {
  srand(time(NULL));

  struct character player = {"N/A", 30, 10, 25, true};
  char name[20];
  printf("Enter a name\n--------------------\n");
  fgets(name, sizeof(name), stdin);
  strcpy(player.name, name);
  printf("\n");
  
  int randomHealth = rand() % 15 + 101;

  struct character enemy = {"Rock", randomHealth, 0, 0, false};
  // printf("Enter a name for the enemy: ");
  // fgets(name, sizeof(name), stdin);
  // printf("\n");
  // strcpy(enemy.name, name);
  //
  // Don't want to have to spam "asd" twice now, do we?

  while (true) {
    printCharacter(player);
    printCharacter(enemy);
    switch (isDead(player, enemy)) {
      case 0:
        break;
      case 1:
        printf("You felt way too much pain and decided to die to %s.\nYOU...! Lose......", enemy.name);
        return 0;
      case 2:
        printf("%s crumbled into dust!\nYOU WIN!", enemy.name);
        return 0;
    }

    int action;
    printf("Pick an action! (1 for attack, 2 for magic, 3 to defend, 4 to run away): ");
    
    scanf("%d", &action);
    getchar();

    // action switch
    switch (action) {
      case 1:
        printf("You hurt the enemy!\n");
        enemy.hp -= player.atk;
        if (enemy.hp < 0) enemy.hp = 0;
        break;
      case 2:
        printMagic();
        break;
      case 3:
        printf("you DEF went up by 100!, but it does NOTHING!\n");
        break;
      case 4: 
        printf("you ran away, fight over\n");
        return 0;
      default:
        printf("What the heck are you trying to do?!\n");
    }

    printf("The rock took action!... But it can't move.\n\n");
    
  }
  
  return 0;
}
// git rebase -i -p 8dc0355
// this is a new comment line!!!
//test