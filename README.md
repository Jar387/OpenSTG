# OpenSTG basic document
## part1: building
### linux
basic c building tool is required to build
for debain users, you can run '$(sudo) apt-get install build-essential'  
otherwise, you need libSDL2, libSDL2-image, libSDL2-mixer and libcrypto(included in openssl-devel)  
### windows(using msys)
install msys2 and run 'pacman -Syu && pacman -S gcc cmake make && pacman -S mingw-w64-x86_64(or i686)-SDL(-image,-mixer)'  
pure mingw or cygwin is not tested  
### do after environment building(for every platform)
get into the project root directory   
run 'mkdir build && cd build && cmake .. && make'   
binary called 'openstg' is the target program   
to run the program, copy it to the same directory that contains "data/"   
## part2: ECL script programming
## part3: core hacking
