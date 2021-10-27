# so_long


 
## :video_game: Description

A simple 2D game coded in C that uses the minilibX graphic library.

The player has to collect all the items scattered around the map and exit the level in as few moves as possible.

This project is part of the common core at 42 Madrid Coding School and serves as an introduction to the minilibX.

## :nut_and_bolt: How it works

This project has two main parts: a map parser and the game engine.

### Map parser

The program receives a text file representing the game map which is then rendered using sprites. In order for the map to be valid it must abide by the following rules:

- The map can only be composed of 5 type of characters: 0 for empty spaces, 1 for walls, C for collectible items, E for the level's exit and P for the player's initial position.
- The map must be enclosed by walls.
- The map must contain at least one exit, one collectible and one starting position for the player.
- The map must be rectangular.
- The map file must use .ber extension.

#### Example of a valid map 
![](https://i.imgur.com/6CaX20E.png)

### Game engine

Once the map is checked and parsed, the minilibX loads the sprites, does the first render and the main game loop is started. The game is not in real-time and renders occur when the player moves.

Use the arrow keys or WASD to move and ESC to exit the game.

## How to use

1. Open terminal inside the repo
2. $ make
3. $ ./so_long map.ber
4. Enjoy! 




**Thanks to 0x72 for the lovely sprites!!**
https://0x72.itch.io/dungeontileset-ii


---