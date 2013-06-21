sheep_vs_wolf
=============

Game in sfml 2 and tmx for map tiles

```
for compile

cd src/
g++  main.cpp -o game  -lsfml-graphics -lsfml-window -lsfml-system -std=c++11 -ltinyxml -lz -ltmxparser
./game



libraries used
sfml 2.0  	      http://www.sfml-dev.org/index.php
tiled map editor  http://www.mapeditor.org/
tmx parser 		  https://code.google.com/p/tmx-parser/


libraries for Archlinux

pacman -S sfml tiled-qt
yaourt -S tmx-parser-svn 
```
