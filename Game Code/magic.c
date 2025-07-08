#include <stdbool.h>
#include <stdio.h>

#ifndef TYPEWRITER_C
#define TYPEWRITER_C
#include "typewriter.c"
#endif

#ifndef MAGICLIST_C
#define MAGICLIST_C
#include "magiclist.c"
#endif//////////magiclist.c

#ifndef CHARACTER_C
#define CHARACTER_C
#include "character.c"
#endif//////////character.c

void printMagic(int action, struct character player, struct character enemy) {
  char selectMagic[100] = "Select a magic.";
  char* text = selectMagic;
  strcpy(text, selectMagic);
  typeWriter(text);
  char ba[100] = "0: Basic Attack";
  strcpy(text, ba);
  typeWriter(text);
  char f[100] = "1: Fireball";
  strcpy(text, f);
  typeWriter(text);
  char h[100] = "2: Heal";
  strcpy(text, h);
  typeWriter(text);
}

int magic(int action, struct character player, struct character enemy) {
  int spell = -1;
  while (spell != 0 && spell != 1 && spell != 2){
    printf("\nspell: %d\n",spell);
    spell = -1;
    printf("Pick a valid spell to use! (0 for Basic Attack, 1 for Fireball, 2 for Heal\n");
    scanf("%d", &spell);
    getchar();
  }
  //check spells
  if(spell == 1){
    if(player.mp>=5){
      printf("You cast fireball!\n");
      player.mp-= 5;
      enemy.hp -= 5;
      printf("player.mp:%d, enemy.hp:%d\n",player.mp,enemy.hp);
      return 0;
    } else{
      printf("You don't have enough MP! (%d) your action FAILED!\n",player.mp);
      player.mp+=1;
      return 0;
      //break;
    }
  } else if(spell == 2){
    if(player.mp>=10){
      printf("You healed yourself! (You can get really high numbers since there is no HP cap yet)\n");
      player.mp-= 10;
      player.hp += ceil(player.hp*0.1)+5;
      if(player.hp>player.maxhp){
        player.hp = (player.maxhp+0);
      }
      printf("player.mp:%d, player.hp:%d\n",player.mp,player.hp);
      return 0;
    }
    else{
      printf("You don't have enough MP! (%d) your action FAILED!\n",player.mp);
      player.mp+=1;
      return 0;
      //break;
    }
  } else if(spell == 0){
    enemy.hp-=player.atk;
    printf("player.atk:%d, enemy.hp:%d\n",player.atk,enemy.hp);
    //break;
  }
}