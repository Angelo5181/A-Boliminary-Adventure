#include <stdio.h>
#include <stdbool.h>

struct spell{
  char name[30];
  int damage;
  int mpcost;
  bool inflictstatus;
  bool weatherchange;
  bool duration; //how many turns it takes effect in
};

struct magic {
  char name[30];
  int type;
  struct spell spell1;
  struct spell spell2;
  struct spell spell3;
  struct spell spell4;
  struct spell spell5;
};

struct magic magicHolder[20];

int makeMagics(){
  struct spell fire1 = {"Fireball",5,5,false,false,1};
  struct spell fire2 = {"Embers",0,5,true,false,1};
  struct spell fire3 = {"Heatstroke",0,5,false,true,3};
  struct spell fire4 = {"Pillar of Flame",60,5,false,false,3};

  struct magic physical = {"physical",0}; // valve pls fix
  struct magic fire = {"fire",1,fire1,fire2,fire3,fire4};

  magicHolder[0] = physical;
  magicHolder[1] = fire;
  return 0;
}

void printMagics(){
  int size = sizeof(magicHolder)/sizeof(magicHolder[0]);
  printf("printMagic()'s size variable:%d\n",size);
  int i = 0;
  for(i = 0; i < size; i++){
    
  }
  printf("%s: type:%d",magicHolder[0].name,magicHolder[0].type);
}



//magicks:
//type:
// 0 - physical
// 1 - fire
// 2 - water
// 3 - grass
// 4 - electric
// 5 - earth
// 6 - air
// 7 - poison
// 8 - psychic
// 9 - heal
// 10 - ice
// 11 - light
// 12 - dark