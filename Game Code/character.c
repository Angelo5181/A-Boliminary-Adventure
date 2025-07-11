#include <stdbool.h>
#include <stdio.h>

struct character { // create a character, char name[22], int maxhp, int hp, int maxmp, int mp, int atk, bool isplayer
  char name[22];
  signed int maxhp;
  signed int hp;
  signed int maxmp;
  signed int mp;
  signed int atk;
  bool isplayer;
};

void printCharacter(struct character x) {
  // if (x.player) printf("Name: %s", x.name);
  // else printf("Name: %s\n", x.name);

  printf("Name: %s\n", x.name);
  printf("HP: %d/%d\n", x.hp,x.maxhp);
  printf("MP: %d/%d\n", x.mp,x.maxmp);
  printf("ATK: %d\n\n", x.atk);
}

bool isDead(struct character x){
  if (x.hp <= 0) return true;
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