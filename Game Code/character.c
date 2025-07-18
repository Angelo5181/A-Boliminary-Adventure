#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

struct character {
  char name[22];
  signed int maxhp;
  signed int hp;
  signed int maxmp;
  signed int mp;
  signed int atk;
  bool player;
};

struct character characterList[5];
struct character enemyList[5];

const int CHARACTER_LIST_SIZE = sizeof(characterList)/sizeof(characterList[0]);

void printCharacter(struct character x) {
  // if (x.player) printf("Name: %s", x.name);
  // else printf("Name: %s\n", x.name);

  printf("Name: %s\n", x.name);
  printf("HP: %d/%d\n", x.hp,x.maxhp);
  printf("MP: %d/%d\n", x.mp,x.maxmp);
  printf("ATK: %d\n\n", x.atk);
}

bool isDead(struct character x){
  //printf("x.hp:%d\n",x.hp);
  if(x.hp<=0){
    //printf("%s is dead.\n",x.name);
    return true;
  }
  //printf("%s is not dead.\n",x.name);
  return false;
}

int findVictor(struct character p, struct character e){
  if (isDead(p)) return 1;
  if (isDead(e)) return 2;
  return 0;
}

void limitStats(struct character x) {
  if (x.hp > x.maxhp) x.hp = x.maxhp;
  if (x.mp > x.maxmp) x.mp = x.maxmp;
}
