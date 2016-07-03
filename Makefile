CFLAGS=-g -Wall
CPPFLAGS=-g -Wall --std=c++11
GFLAGS=`pkg-config --cflags --libs gtk+-2.0` -lm

all: clean dist

blockgen: blockgen.c
	$(CC) $< $(CFLAGS) -o $@

blockgen2: blockgen2.c
	$(CC) $< $(CFLAGS) -o $@

blockgen3: blockgen3.c
	$(CC) $< $(CFLAGS) -o $@

skrypt: skrypt.cpp Keyblock.o Keyblock1.o Keyblock2.o Keyblock3.o
	$(CXX) $^ $(CFLAGS) $(GFLAGS) -o $@

clean:
	rm *.o skrypt skrypt-dist blockgen blockgen2 blockgen3

dist: skrypt
	cp skrypt skrypt-dist
	strip skrypt-dist
