prog:main.o image.o text.o music.o
	gcc main.c image.c text.c music.c -o work -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g 
image.o:image.c
	gcc -c image.c -g
text.o:text.c
	gcc -c text.c -g
music.o:music.c
	gcc -c music.c -g
