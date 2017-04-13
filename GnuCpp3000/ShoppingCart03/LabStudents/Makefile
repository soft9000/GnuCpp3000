cpp = c++
base01 = ../../ShoppingCart01
code01 = $(base01)/LabSolutions
opts = -std=c++11 -I../Headers/ -I$(base01)/Headers

all: clean
	make main.run

main.o: main.cpp FrankenCart2.hpp $(base01)/Headers/AbsUserCart1.hpp
	$(cpp) $(opts) -c main.cpp

Products.o: $(code01)/Products.cpp $(base01)/Headers/Products.hpp
	$(cpp) $(opts) -c $(code01)/Products.cpp

UserData.o: $(code01)/UserData.cpp $(base01)/Headers/UserData.hpp
	$(cpp) $(opts) -c $(code01)/UserData.cpp

#  Outfile (-o) MUST be specificed FIRST to start dependancy lookups
main.run: main.o UserData.o
	$(cpp) $(opts) -o main.run main.o UserData.o
	exec "./main.run"

list: clean UserData.o
	nm --demangle *.o

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.run
	rm -f *.out
	chmod 666 *.?pp

