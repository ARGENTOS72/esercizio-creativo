all: compile link

compile:
	gcc -c main.c -I"C:\CSFML\include" -DCSFML_STATIC

link:
	gcc main.o -o main -L"C:\CSFML\lib\gcc" -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-network -mwin32