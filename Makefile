main : main.o xxhash.o position.o analyzer.o unbufstdio.o
	g++ -o main main.o xxhash.o position.o analyzer.o unbufstdio.o utils/lib/x64/libpthreadGC2.a
	mkdir -p Data
	cp main.exe c:/unzip
	
position.o : position.cpp position.h
	g++ -c position.cpp
	
analyzer.o : analyzer.cpp analyzer.h position.h utils/include/myhash.h
	g++ -c analyzer.cpp

xxhash.o : utils/include/xxhash.h utils/src/xxhash.c
	g++ -c utils/src/xxhash.c
	
unbufstdio.o : utils/include/unbufstdio.h utils/include/myhash.h utils/src/unbufstdio.cpp
	g++ -c utils/src/unbufstdio.cpp

main.o : main.cpp utils/include/myhash.h utils/include/xxhash.h utils/include/unbufstdio.h position.h analyzer.h
	g++ -c main.cpp
	
clean :
	rm main.o
	rm position.o
	rm analyzer.o
	rm xxhash.o
	rm unbufstdio.o
	rm main.exe