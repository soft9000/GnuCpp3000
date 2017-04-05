link = ld
cpp = c++
opts = -std=c++14 -I../Headers/

all: main.run


# Outfile (-o) MUST be specified FIRST to start dependency lookups
main.run: main.o FrankenCart.o UserData.o
	$(cpp) $(opts) -o main.run main.o FrankenCart.o UserData.o
	exec "./main.run"

main.o: main.cpp ../Headers/FrankenCart1.hpp
	$(cpp) $(opts) -c main.cpp

FrankenCart.o: FrankenCart.cpp ../Headers/FrankenCart1.hpp
	$(cpp) $(opts) -c FrankenCart.cpp

UserData.o: UserData.cpp ../Headers/UserData.hpp
	$(cpp) $(opts) -c UserData.cpp

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.run
	rm -f *.out
	chmod 666 *.?pp

