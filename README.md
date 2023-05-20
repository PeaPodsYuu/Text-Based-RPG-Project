# Text-Based-RPG-Project

A project by:
- Cecan Bogdan-Cosmin (Lead Developer and Testing) // https://github.com/PeaPodsYuu
- Vulpe Maria-Alexandra (Programming, Concepts and Balancing) // https://github.com/Grummeln

______________________INTRODUCTION______________________

This project was created as a university project for the end of year 1. I chose to ignore the aesthetic and graphic side, for a more technical approach, to push my knowledge of the C++ language and Object Oriented Programming capabilities to its limits, which I believe worked quite well for my largest scale project to date.

The main scope of the project was to simulate a MUD / DOS game from the 1980's to early 1990's (most features will be included at the bottom of the document), games that were typically created for fans of board games such as Dungeons & Dragons, from which several naming conventions and the RNG-based combat takes inspiration, along with Action Points that decides how many times the player can act before their turn ends. With the scope of the project in mind, the game requires either old school RPG knowledge or a manual in order to play:

______________________MANUAL______________________

Map movement is done by inputting compass directions (or e/w/s/n) for short.
Map icons:
- "0" is an empty spot in the overworld.
- "1" is an enemy.
- "2" is an elite enemy.
- "3" is an event space.
- "4" is a boss enemy.
- "5" is a rest/meditation spot, for HP, respectively MP regen.
- "7" is the player character.

All player actions are based on 'dice rolls', or random number generator influenced values to simulate a range of possible outcomes / damage outputs / damage taken in regards to a base value that is then modified by random generation. Thus, a regular attack may deal more damage at times.

The player may choose *any nine upgrades* out of the six paths (classes) with five upgrades each. It is highly recommended to finish a path, rather then invests points into all of them, as to achieve a high level attack. The player may invest any way he seems fit, otherwise.

Different statuses:
- Burn will deal no. burn stacks damage per turn, then halve in amount that is currently on the player/enemy.
- Bleed will deal no. bleed stacks damage per turn, then decrement in amount by one.
- Necromantic burn will deal no. stacks damage per turn, not decrement in any way and prevent healing.

______________________CODING FEATURES______________________

- High focus on OOP, from the player code representation, to the enemies and even the maps, classes have been used for nearly everything, as per scope of the project.
- Complete RNG for everything from map generation, to damage counts and event outcomes.
- Carefully structured classes, using useful functions without cluttering the code with too many different ones, nor skimping out on the amount as to create incomprehensibly large ones.
- Efficient use of files in order to preserve a comprehensible coding environment and call any descriptive information, save content and enemy stats from external .txt files.
