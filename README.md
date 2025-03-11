Sorry about the zip files but I am far to lazy to maintain a proper git repository, I have far too many things going on to fight with commandline git. I don't really care
if this code gets into the real PSPDEVSDK or not lol. Ransack and pillage it all and put your name on it. Whatever I could care less.

A whole pile of function prototypes added to headers and nids added to stub libraries. roughly 1/3 more sdk to work with.

*CHANGES*
There have been a couple of other changes along the way trying to clean up naming convention in the headers. This part is a work in progress and is not entirely complete. You may run into issues when compiling where some cdef or macro's name is incorrect, gcc should give you the answer but you may need to check the headers too. There is a lot more information in a wide range of headers.

*NEW*
A more complete version of the network API. Now libcglue is no longer required for networking. Berkley sockets will still work I've not removed that, it saves porting code but now if users want to program their code in the proper way they can.

Runtime libraries!    
    libadler
    libbase64
    libccc
    libdeflt
    libfont
    libmd5
    libmpeg
    libmt19937
    libpsmf
    libqpcode
    libsas
    libsha1
    libsha224
    libsha256
    libsha512
    libsndp
    libfpu
    libvfpu
    libwave
    ...and more!
