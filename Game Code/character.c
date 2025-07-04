#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct character {
  char name[20];
  int hp;
  int mp;
  int atk;
};

int isDead(struct character p, struct character e){
  if (p.hp <= 0) return 1;
  if (e.hp <= 0) return 2;
  return 0;
}

void printCharacter(struct character x) {
  printf("Name: %s", x.name);
  printf("HP: %d\n", x.hp);
  printf("MP: %d\n", x.mp);
  printf("ATK: %d\n\n", x.atk);
}

int main() {
  struct character player = {"N/A", 30, 10, 25};
  char name[20];
  printf("Enter a name: ");
  fgets(name, sizeof(name), stdin);
  printf("\n");
  
  strcpy(player.name, name);
  
  struct character enemy = {"Rock", 100, -1, 0};
  printf("Enter a name for the enemy: ");
  fgets(name, sizeof(name), stdin);
  printf("\n");

  strcpy(enemy.name, name);

  while (true) {
    printCharacter(player);
    printCharacter(enemy);
    switch (isDead(player,enemy)) {
      case 0:
        break;
      case 1:
        printf("You lost! You died to %s\n", enemy.name);
        return 0;
      case 2:
        printf("You win! You killed %s\n", enemy.name);
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
        break;
      case 2:
        printf("not implemented, bozo\n");
        break;
      case 3:
        printf("you DEF went up by 100!, but it does NOTHING!\n");
        break;
      case 4: 
        printf("you ran away, fight over\n");
        return 0;
      default:
        printf("What the heck are you trying to do?!\n");
        break;
    }

    printf("The rock took action!... But it can't move.\n\n");
    
  }
  
  return 0;
}
// git rebase -i -p 8dc0355
// this is a new comment line!!!