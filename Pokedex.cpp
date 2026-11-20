#include "Pokemon.h"
#include "raylib.h"
#include "Movepool.h"
#include "GetTypeMatchUp.cpp"
/*
Pokemon constructer paramaters:
(name,  type,  level,  exp,  stage, spriteFront,  spriteBack, *moveset[4], stats{})
*/

     Pokemon Bulbasaur("Bulbasaur", Grass, GetRandomValue(5,8), 0, 0, LoadTexture("Assets/Pokemon/Bulbasaur/Bulbasaur_front.png"), LoadTexture("Assets/Pokemon/Bulbasaur/Bulbasaur_back.png"), {new Move(tackle), new Move(VineWhip), NULL, NULL}, {45,49,49,65,65,45});
     Bulbasaur.spriteBack.width = 600;
     Bulbasaur.spriteBack.height = 600;
     Bulbasaur.spriteFront.width = 500;
     Bulbasaur.spriteFront.height = 500;
     
     Pokemon Ivysaur("Ivysaur", Grass, Poison, GetRandomValue(10,12), 0, 0, LoadTexture("Assets/Pokemon/Ivysaur/Ivysaur_front.png"), LoadTexture("Assets/Pokemon/Ivysaur/Ivysaur_back.png"), {new Move(tackle), new Move(VineWhip), NULL, NULL}, {60,62,63,80,80,60});
     Ivysaur.spriteBack.width = 600;
     Ivysaur.spriteBack.height = 600;
     Ivysaur.spriteFront.width = 500;
     Ivysaur.spriteFront.height = 500;
     
     Pokemon Venusaur("Venusaur", Grass, Poison, GetRandomValue(10,12), 0, 0, LoadTexture("Assets/Pokemon/Venusaur/Venusaur_front.png"), LoadTexture("Assets/Pokemon/Venusaur/Venusaur_back.png"), {new Move(tackle), new Move(VineWhip), new Move(Acid), NULL}, {80,82,83,100,100,80});
     Venusaur.spriteBack.width = 600;
     Venusaur.spriteBack.height = 600;
     Venusaur.spriteFront.width = 500;
     Venusaur.spriteFront.height = 500;
     
     Pokemon Charmander("Charmander", Fire, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Charmander/Charmander_front.png"), LoadTexture("Assets/Pokemon/Charmander/Charmander_back.png"), {new Move(tackle), new Move(Ember), new Move(quickAttack), NULL}, {39,52,43,60,50,65});
     Charmander.spriteBack.width = 600;
     Charmander.spriteBack.height = 600;
     Charmander.spriteFront.width = 500;
     Charmander.spriteFront.height = 500;
     
      Pokemon Squirtle("Squirtle", Water, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Squirtle/Squirtle_front.png"), LoadTexture("Assets/Pokemon/Squirtle/Squirtle_back.png"), {new Move(tackle), new Move(Bubble), NULL, NULL},{44,48,65,50,64,43});
     Squirtle.spriteFront.width = 500;
     Squirtle.spriteFront.height = 500;
     Squirtle.spriteBack.width = 600;
     Squirtle.spriteBack.height = 600;
     
      Pokemon Rayquaza("Rayquaza", Dragon, Flying, GetRandomValue(10,12) , 0, 0, LoadTexture("Assets/Pokemon/Rayquaza/Rayquaza_front.png"), LoadTexture("Assets/Pokemon/Rayquaza/Rayquaza_back.png"), {new Move(tackle), new Move(DragonClaw), NULL, NULL},{105,150,90,150,90,95});
     Rayquaza.spriteBack.width = 600;
     Rayquaza.spriteBack.height = 600;
     Rayquaza.spriteFront.width = 500;
     Rayquaza.spriteFront.height = 500;
     
      Pokemon Treecko("Treecko", Grass, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Treecko/Treecko_front.png"), LoadTexture("Assets/Pokemon/Treecko/Treecko_back.png"), {new Move(tackle), new Move(VineWhip), NULL, NULL}, {40,45,35,60,65,70});
     Treecko.spriteBack.width = 600;
     Treecko.spriteBack.height = 600;
     Treecko.spriteFront.width = 500;
     Treecko.spriteFront.height = 500;
     
      Pokemon Mudkip("Mudkip", Water, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Mudkip/Mudkip_front.png"), LoadTexture("Assets/Pokemon/Mudkip/Mudkip_back.png"), {new Move(tackle), new Move(Bubble), NULL, NULL},{50,70,50,50,50,40});
     Mudkip.spriteBack.width = 600;
     Mudkip.spriteBack.height = 600;
     Mudkip.spriteFront.width = 500;
     Mudkip.spriteFront.height = 500;
     
      Pokemon Torchic("Torchic", Fire, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Torchic/Torchic_front.png"), LoadTexture("Assets/Pokemon/Torchic/Torchic_back.png"), {new Move(tackle), new Move(Ember), NULL, NULL},{45,60,40,70,50,45});
     Torchic.spriteBack.width = 600;
     Torchic.spriteBack.height = 600;
     Torchic.spriteFront.width = 500;
     Torchic.spriteFront.height = 500;
     
      Pokemon Absol("Absol", Dark, GetRandomValue(10,12), 0, 0, LoadTexture("Assets/Pokemon/Absol/Absol_front.png"), LoadTexture("Assets/Pokemon/Absol/Absol_back.png"), {new Move(tackle), new Move(Crunch), NULL, NULL},{65,130,60,75,60,75});
     Absol.spriteBack.width = 600;
     Absol.spriteBack.height = 600;
     Absol.spriteFront.width = 500;
     Absol.spriteFront.height = 500;
     
      Pokemon Shroomish("Shroomish", Grass, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Shroomish/Shroomish_front.png"), LoadTexture("Assets/Pokemon/Shroomish/Shroomish_back.png"), {new Move(tackle),  new Move(Acid),  NULL, NULL}, {60,40,60,40,60,35});
     Shroomish.spriteBack.width = 600;
     Shroomish.spriteBack.height = 600;
     Shroomish.spriteFront.width = 500;
     Shroomish.spriteFront.height = 500;
     
     Pokemon Breloom("Breloom", Grass, GetRandomValue(10,12), 0, 0, LoadTexture("Assets/Pokemon/Breloom/Breloom_front.png"), LoadTexture("Assets/Pokemon/Breloom/Breloom_back.png"), {new Move(tackle),  new Move(Acid),  NULL, NULL}, {60,40,60,40,60,35});
     Breloom.spriteBack.width = 600;
     Breloom.spriteBack.height = 600;
     Breloom.spriteFront.width = 500;
     Breloom.spriteFront.height = 500;
     
      Pokemon Raltz("Raltz", Psychic, Fairy, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Raltz/Raltz_front.png"), LoadTexture("Assets/Pokemon/Raltz/Raltz_back.png"), {new Move(tackle), new Move(Psybeam), NULL, NULL}, {28, 25,25, 45,35,40});
     Raltz.spriteBack.width = 600;
     Raltz.spriteBack.height = 600;
     Raltz.spriteFront.width = 500;
     Raltz.spriteFront.height = 500;
     
     Pokemon Rattata("Rattata", Normal, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Rattata/Rattata_front.png"), LoadTexture("Assets/Pokemon/Rattata/Rattata_back.png"), {new Move(tackle), new Move(quickAttack), NULL, NULL}, {30, 56, 35, 25, 35, 72});
     Rattata.spriteBack.width = 600;
     Rattata.spriteBack.height = 600;
     Rattata.spriteFront.width = 500;
     Rattata.spriteFront.height = 500;
     
     Pokemon Pidgey("Pidgey", Normal, Flying, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Pidgey/Pidgey_front.png"), LoadTexture("Assets/Pokemon/Pidgey/Pidgey_back.png"), {new Move(tackle), new Move(gust), new Move(quickAttack), NULL}, {40, 45, 40, 35, 35, 56});
     Pidgey.spriteBack.width = 600;
     Pidgey.spriteBack.height = 600;
     Pidgey.spriteFront.width = 500;
     Pidgey.spriteFront.height = 500;
     
     Pokemon Oddish("Oddish", Grass, Poison, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Oddish/Oddish_front.png"), LoadTexture("Assets/Pokemon/Oddish/Oddish_back.png"), {new Move(Acid), NULL, NULL, NULL}, {45, 50, 55, 75, 65, 30});
     Oddish.spriteBack.width = 600;
     Oddish.spriteBack.height = 600;
     Oddish.spriteFront.width = 500;
     Oddish.spriteFront.height = 500;
     
     Pokemon Weedle("Weedle", Bug, Poison, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Weedle/Weedle_front.png"), LoadTexture("Assets/Pokemon/Weedle/Weedle_back.png"), {new Move(tackle), NULL, NULL, NULL}, {40, 35, 30, 20, 20, 50});
     Weedle.spriteBack.width = 600;
     Weedle.spriteBack.height = 600;
     Weedle.spriteFront.width = 500;
     Weedle.spriteFront.height = 500;
     
     Pokemon Caterpie("Caterpie", Bug, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Caterpie/Caterpie_front.png"), LoadTexture("Assets/Pokemon/Caterpie/Caterpie_back.png"), {new Move(tackle), NULL, NULL, NULL}, {45, 30, 35, 20, 20, 45});
     Caterpie.spriteBack.width = 600;
     Caterpie.spriteBack.height = 600;
     Caterpie.spriteFront.width = 500;
     Caterpie.spriteFront.height = 500;
     
     Pokemon Pikachu("Pikachu", Electric, GetRandomValue(5,7), 0, 0, LoadTexture("Assets/Pokemon/Pikachu/Pikachu_front.png"), LoadTexture("Assets/Pokemon/Pikachu/Pikachu_back.png"), {new Move(thunderShock), new Move(quickAttack), NULL, NULL}, {35, 55, 40, 50, 50, 90});
     Pikachu.spriteBack.width = 600;
     Pikachu.spriteBack.height = 600;
     Pikachu.spriteFront.width = 500;
     Pikachu.spriteFront.height = 500;

Pokemon pokedex[] = {Bulbasaur, Charmander, Squirtle, Treecko, Mudkip, Torchic, Shroomish, Raltz, Rattata, Pidgey, Oddish, Weedle, Caterpie, Pikachu};

/*

Remember to add a function that returns a pokemon searchable by either name or ID (overload)

*/