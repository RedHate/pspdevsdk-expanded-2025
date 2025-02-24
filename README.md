sorry about the zip file, git was being a jerk so i just zipped it and dropped it in.

A whole pile of function prototypes added to headers and nids added to stub libraries. Noticed somethings that were only being linked in kernel space that are avaiable in both kernel and userspace and added the stubs to the libpspuser.a, userspace module loading works without and "pspsdk" hackery. The method for loading from userspace is the same as the sample within the kernel directory relating to module loading, just change the module attriubutes.

There have been a couple of other changes along the way trying to clean up naming convention in the headers. This part is a work in progress and is not entirely complete. You may run into issues when compiling where some cdef or macro's name is incorrect, gcc should give you the answer but you may need to check the headers too. There is a lot more information in a wide range of headers.

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

