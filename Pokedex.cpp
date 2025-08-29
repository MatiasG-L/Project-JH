#include "Pokemon.h"
#include "raylib.h"
#include "Movepool.h"

/*
Pokemon constructer paramaters:
(name,  type,  level,  exp,  stage, spriteFront,  spriteBack, *moveset[4], stats{})
*/

     Pokemon Bulbasaur("Bulbasaur", "Grass", GetRandomValue(8,12), 0, 0, LoadTexture("Assets/Pokemon/Bulbasaur/Bulbasaur_front.png"), LoadTexture("Assets/Pokemon/Bulbasaur/Bulbasaur_back.png"), {new Move(tackle), new Move(VineWhip), NULL, NULL}, {45,49,49,65,65,45});
     Bulbasaur.spriteBack.width = 600;
     Bulbasaur.spriteBack.height = 600;
     Bulbasaur.spriteFront.width = 500;
     Bulbasaur.spriteFront.height = 500;
     
      Pokemon Squirtle("Squirtle", "Water", GetRandomValue(8,12), 0, 0, LoadTexture("Assets/Pokemon/Squirtle/Squirtle_front.png"), LoadTexture("Assets/Pokemon/Squirtle/Squirtle_back.png"), {new Move(tackle), new Move(Bubble), NULL, NULL},{44,48,65,50,64,43});
     Squirtle.spriteFront.width = 500;
     Squirtle.spriteFront.height = 500;
     Squirtle.spriteBack.width = 600;
     Squirtle.spriteBack.height = 600;
     
      Pokemon Rayquaza("Rayquaza", "Dragon",GetRandomValue(8,12) , 0, 0, LoadTexture("Assets/Pokemon/Rayquaza/Rayquaza_front.png"), LoadTexture("Assets/Pokemon/Rayquaza/Rayquaza_back.png"), {new Move(tackle), new Move(DragonClaw), NULL, NULL},{105,150,90,150,90,95});
     Rayquaza.spriteBack.width = 600;
     Rayquaza.spriteBack.height = 600;
     Rayquaza.spriteFront.width = 500;
     Rayquaza.spriteFront.height = 500;
     
      Pokemon Treecko("Treecko", "Grass", GetRandomValue(8,12), 0, 0, LoadTexture("Assets/Pokemon/Treecko/Treecko_front.png"), LoadTexture("Assets/Pokemon/Treecko/Treecko_back.png"), {new Move(tackle), new Move(VineWhip), NULL, NULL}, {40,45,35,60,65,70});
     Treecko.spriteBack.width = 600;
     Treecko.spriteBack.height = 600;
     Treecko.spriteFront.width = 500;
     Treecko.spriteFront.height = 500;
     
      Pokemon Mudkip("Mudkip", "Water", GetRandomValue(8,12), 0, 0, LoadTexture("Assets/Pokemon/Mudkip/Mudkip_front.png"), LoadTexture("Assets/Pokemon/Mudkip/Mudkip_back.png"), {new Move(tackle), new Move(Bubble), NULL, NULL},{50,70,50,50,50,40});
     Mudkip.spriteBack.width = 600;
     Mudkip.spriteBack.height = 600;
     Mudkip.spriteFront.width = 500;
     Mudkip.spriteFront.height = 500;
     
      Pokemon Torchic("Torchic", "Fire", GetRandomValue(8,12), 0, 0, LoadTexture("Assets/Pokemon/Torchic/Torchic_front.png"), LoadTexture("Assets/Pokemon/Torchic/Torchic_back.png"), {new Move(tackle), new Move(Ember), NULL, NULL},{45,60,40,70,50,45});
     Torchic.spriteBack.width = 600;
     Torchic.spriteBack.height = 600;
     Torchic.spriteFront.width = 500;
     Torchic.spriteFront.height = 500;
     
      Pokemon Absol("Absol", "Dark", GetRandomValue(8,12), 0, 0, LoadTexture("Assets/Pokemon/Absol/Absol_front.png"), LoadTexture("Assets/Pokemon/Absol/Absol_back.png"), {new Move(tackle), new Move(Crunch), NULL, NULL},{65,130,60,75,60,75});
     Absol.spriteBack.width = 600;
     Absol.spriteBack.height = 600;
     Absol.spriteFront.width = 500;
     Absol.spriteFront.height = 500;
     
      Pokemon Shroomish("Shroomish", "Poison", GetRandomValue(8,12), 0, 0, LoadTexture("Assets/Pokemon/Shroomish/Shroomish_front.png"), LoadTexture("Assets/Pokemon/Shroomish/Shroomish_back.png"), {new Move(tackle),  new Move(Acid),  NULL, NULL}, {60,40,60,40,60,35});
     Shroomish.spriteBack.width = 600;
     Shroomish.spriteBack.height = 600;
     Shroomish.spriteFront.width = 500;
     Shroomish.spriteFront.height = 500;
     
      Pokemon Raltz("Raltz", "Psychic", GetRandomValue(8,12), 0, 0, LoadTexture("Assets/Pokemon/Raltz/Raltz_front.png"), LoadTexture("Assets/Pokemon/Raltz/Raltz_back.png"), {new Move(tackle), new Move(Psybeam), NULL, NULL}, {28, 25,25, 45,35,40});
     Raltz.spriteBack.width = 600;
     Raltz.spriteBack.height = 600;
     Raltz.spriteFront.width = 500;
     Raltz.spriteFront.height = 500;

Pokemon pokedex[] = {Bulbasaur, Squirtle, Rayquaza, Treecko, Mudkip, Torchic, Absol, Shroomish, Raltz};