prog:main.o image.o text.o music.o
	gcc main.c image.c text.c music.c Functions.c background.c perso.c -o work -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g 
image.o:image.c
	gcc -c image.c -g
text.o:text.c
	gcc -c text.c -g
music.o:music.c
	gcc -c music.c -g
Functions.o:Functions.c
	gcc -c Functions.c -g
background.o:background.c
	gcc -c backgroud.c -g
perso.o:perso.c
	gcc -c perso.c -g
