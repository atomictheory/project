main : main.o xxhash.o position.o analyzer.o
	g++ -o main main.o xxhash.o position.o analyzer.o utils/lib/x64/libpthreadGC2.a
	mkdir -p Data
	
position.o : position.cpp position.h
	g++ -c position.cpp
	
analyzer.o : analyzer.cpp analyzer.h position.h utils/include/myhash.h
	g++ -c analyzer.cpp

xxhash.o : utils/include/xxhash.h utils/src/xxhash.c
	g++ -c utils/src/xxhash.c

main.o : main.cpp utils/include/myhash.h utils/include/xxhash.h position.h analyzer.h
	g++ -c main.cpp
	
something:
	mkdir Data
	
clean :
	rm main.o
	rm position.o
	rm analyzer.o
	rm xxhash.o
	rm main.exe