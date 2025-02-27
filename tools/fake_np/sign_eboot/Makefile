
all:
	gcc -Wall -g -o seboot sign_eboot.c -I../kirk -L../kirk -lkirk -lcrypto

clean:
	rm -f *.exe

install:
	cp -Rp seboot $(PSPDEV)/bin/seboot
