#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef MAGIC_C
  #define MAGIC_C
  #include "magic.c"
#endif//////////magiclist.c

#ifndef MAGICLIST_C
  #define MAGICLIST_C
  #include "magiclist.c"
#endif//////////magiclist.c

#ifndef CHARACTER_C
  #define CHARACTER_C
  #include "character.c"
#endif//////////character.c

int checkDead(struct character player, struct character enemy){
  printf("findVictor():%d\n", findVictor(player, enemy));
  switch (findVictor(player, enemy)) {
    case 1:
      printf("player.hp:%d\n",player.hp);
      if (!strcmp("Peanut", player.name)) printf("You were turned into %s butter by %s.\nYOU...! Lose......", player.name, enemy.name);
      else printf("You felt way too much pain and decided to die to %s.\nYOU...! Lose......", enemy.name);
      return 1;
    case 2:
      printf("%s crumbled into dust!\nYOU WIN!", enemy.name);
      return 2;
    default:
      return 0;
  }
}

//fight() is a battle loop that only ends when one side dies or runs away. (currently works for 1v1 only)
//returns 1 if you lose
//returns 2 if you win
//returns 3 if you run away
int fight(struct character player, struct character enemy){
  while(true) {
    printCharacter(player);
    printCharacter(enemy);

    //switch for checking death was here
    int battlecondition = checkDead(player,enemy);
    printf("battlecondition:%d\n",battlecondition);
    if(battlecondition != 0){
      return battlecondition;
    }

    int damageTaken = 0;
    //prevent infinite mp
    int action = -1;
    int tempenemyatk = enemy.atk;//store enemy attack in case of picking 3 for defend
    printf("Pick an action! (1 for attack, 2 for magic, 3 to defend, 4 to run away): ");
    
    scanf("%d", &action);
    getchar();

    // action switch
    switch (action) {
      case 1: //basic attack
        //printf("fight\n");
        enemy.hp-=player.atk;
        printf("You hit the enemy! %d hp left.\n",enemy.hp);
        break;
      case 2: //magick
        // Inconveniently, my phone died
        //run and debug ok

        //printMagic(action, player, enemy);
        //magic(action, player, enemy);

        int spell = -1;
        printMagic();
        //printf("before loop\n");
        while (spell < 0 || spell > 2) {
          //printf("in loop\n");
          printf("\nspell: %d\n",spell);
          spell = -1;
          printf("Pick a valid spell to use! (0 for Basic Attack, 1 for Fireball, 2 for Heal\n");
          scanf("%d", &spell);
          getchar();
        }
        //printf("after loop\n");
        //check spells
        if (spell == 1) {
          if (player.mp >= 5) {
            printf("You cast fireball!\n");
            player.mp-= 5;
            enemy.hp -= 5;
            printf("player.mp:%d, enemy.hp:%d\n", player.mp, enemy.hp);
          }
          else {
            printf("You don't have enough MP! (%d) your action FAILED!\n", player.mp);
            player.mp += 1;
            if (player.mp>player.maxmp) player.mp = player.maxmp;
          }
        }
        else if (spell == 2) {
          if (player.mp >= 10) {
            player.mp-= 10;
            int healamount = ceil(player.maxhp*0.1)+5;
            player.hp += healamount;
            printf("You healed yourself! by %d\n",healamount);

            if (player.hp > player.maxhp) player.hp = (player.maxhp + 0);

            printf("player.mp:%d, player.hp:%d\n", player.mp, player.hp);
          }
          else {
            printf("You don't have enough MP! (%d) your action FAILED!\n", player.mp);
            player.mp += 1;
            if (player.mp > player.maxmp) player.mp = player.maxmp;
          }
        }
        else if (!spell) {
          enemy.hp -= player.atk;
          printf("player.atk:%d, enemy.hp:%d\n",player.atk,enemy.hp);
        }
        else printf("No spell used");
        break;
      case 3: //defence, take half damage
        damageTaken = floor(enemy.atk * 0.5);
        printf("You defended! Enemy attacks will hurt less for this turn!\n");
        player.mp += 1;
        if(player.mp > player.maxmp) player.mp = player.maxmp;
        break;
      case 4: //run
        printf("you ran away, fight over\n");
        return 3; //3 for ran away
      default:
        action = -1;
        printf("What the heck are you trying to do?!\n");
    }

    //check for a death
    battlecondition = checkDead(player,enemy);
    printf("battlecondition:%d\n",battlecondition);
    if (battlecondition) return battlecondition; //if not 0 return condition

    printf("The rock took action!... It always attacks!.\n");
    player.hp-=damageTaken;
    printf("You took %d damage.\n\n",damageTaken);
    
    enemy.atk = tempenemyatk;
  }
  //end of battle loop
  return 0;
}