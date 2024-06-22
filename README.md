Tic Tac Toe game made entirely in C.

Algorithm used here is negamax with alpha-beta prunning.

One of the three display systems can be chosen when building:

-SDL2 window

-Text User Interface

-Web (Emscripten compiled SDL2 project)

Please use emsdk version 3.1.53 or older for building web application, as newer ones generate an unknown bug

To build the project using make system, run make command with one of the three sdl2, tui or web arguments in root project directory
