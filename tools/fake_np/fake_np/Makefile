
all:
	gcc -Wall -g -o fake_np fake_np.c amctrl.c  libkirk.a -lcrypto

clean:
	rm -f *.exe *.exe.stackdump

install:
	cp -Rp fake_np $(PSPDEV)/bin/fake_np
