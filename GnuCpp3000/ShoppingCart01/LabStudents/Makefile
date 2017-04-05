link = ld
cpp = c++
opts = -std=c++14 -I../Headers/

all: main.run


# Outfile (-o) MUST be specified FIRST to start dependency lookups
main.run: main.o UserData.o
	$(cpp) $(opts) -o main.run main.o UserData.o
	exec "./main.run"

main.o: main.cpp UserData.o
	$(cpp) $(opts) -c main.cpp

UserData.o: ../LabSolutions/UserData.cpp ../Headers/UserData.hpp
	$(cpp) $(opts) -c ../LabSolutions/UserData.cpp

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.run
	rm -f *.out
	chmod 666 *.?pp

