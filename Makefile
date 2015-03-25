main : main.o xxhash.o position.o analyzer.o unbufstdio.o anno.o annodefault.o
	g++ -o main main.o xxhash.o position.o analyzer.o unbufstdio.o anno.o annodefault.o utils/lib/x64/libpthreadGC2.a
	mkdir -p Data
	cp main.exe c:/unzip
	
position.o : position.cpp position.h
	g++ -c position.cpp
	
analyzer.o : analyzer.cpp analyzer.h position.h utils/include/myhash.h setup.h
	g++ -c analyzer.cpp

xxhash.o : utils/include/xxhash.h utils/src/xxhash.c
	g++ -c utils/src/xxhash.c
	
unbufstdio.o : utils/include/unbufstdio.h utils/include/myhash.h utils/src/unbufstdio.cpp
	g++ -c utils/src/unbufstdio.cpp
	
anno.o : anno.h anno.cpp
	g++ -c anno.cpp
	
annodefault.o : anno.h position.h annodefault.cpp
	g++ -c annodefault.cpp

main.o : main.cpp utils/include/myhash.h utils/include/xxhash.h utils/include/unbufstdio.h position.h analyzer.h setup.h
	g++ -c main.cpp
	
clean :
	rm main.o
	rm position.o
	rm analyzer.o
	rm xxhash.o
	rm unbufstdio.o
	rm anno.o
	rm annodefault.o
	rm main.exe