CFLAGS = -I../..
ifeq ($(OS),Windows_NT)
        LDFLAGS = -s -lopengl32 -lgdi32
else
        UNAME_S := $(shell uname -s)
        ifeq ($(UNAME_S),Darwin)
                LDFLAGS = -framework OpenGL -framework Cocoa
        else ifeq ($(UNAME_S),Linux)
                LDFLAGS = -s -lGLU -lGL -lX11
        endif
endif

visorGUI: visorGUI.o guiICONS.o tigr.o guiXML.o xml.o
	gcc -o visorGUI visorGUI.o guiICONS.o tigr.o guiXML.o xml.o $(CFLAGS) $(LDFLAGS)
visorGUI.o: visorGUI.c
	gcc -c visorGUI.c
guiXML.o: guiXML.c
	gcc -c guiXML.c
guiICONS.o: guiICONS.c
	gcc -c guiICONS.c
tigr.o: tigr\tigr.c tigr\tigr.h
	gcc -c tigr\tigr.c
xml.o: xml.c\src\xml.c
	gcc -c xml.c/src/xml.c
clean:
	del icono icono.o parser.o tigr.o xml.o visorGUI.o visorGUI
