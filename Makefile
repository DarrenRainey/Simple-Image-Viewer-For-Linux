viewer: viewer.c
	gcc -Wall viewer.c -o Image-Viewer `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
