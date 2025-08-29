#include "Move.h"
#pragma once
/*
Move constructer paramaters:
(name, baseDmg, type, pp, accuracy, priority)
*/

Move tackle("Tackle", 40, "Normal", 35, 100, 0, "Physical");
Move VineWhip("Vine Whip", 45, "Grass", 25, 100, 0, "Physical");
Move Ember("Ember", 40, "Fire", 25, 100, 0, "Special");
Move Bubble("Bubble", 40, "Water", 25, 100, 0, "Special");
Move Psybeam("Psybeam", 65, "Psychic", 20, 100, 0, "Special");
Move Crunch("Crunch", 80, "Dark", 15, 100, 0, "Physical");
Move DragonClaw("Dragon Claw", 80, "Dragon", 15, 100, 0, "Physical");
Move Acid("Acid", 40, "Poison",30, 100, 0, "Special");
