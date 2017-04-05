link = ld
cpp = c++
base01 = ../../ShoppingCart01
base03 = ../../ShoppingCart03
code01 = $(base01)/LabSolutions
code03 = $(base03)/LabSolutions
opts = -std=c++14 -I../Headers/ -I$(base01)/Headers -I$(base03)/Headers

all: clean main.run

#  Outfile (-o) MUST be specificed FIRST to start dependancy lookups
main.run: main.o FrankenCart.o libcart.a
	$(cpp) $(opts) -o main.run main.o FrankenCart.o -L. -lcart
	exec "./main.run"

libcart.a: UserData.o Products.o
	ar rcs libcart.a UserData.o Products.o

main.o: main.cpp FrankenCart.o
	$(cpp) $(opts) -c main.cpp

FrankenCart.o: FrankenCart.cpp ../Headers/FrankenCart4.hpp
	$(cpp) $(opts) -c FrankenCart.cpp

Products.o: $(code03)/Products.cpp $(base03)/Headers/Products.hpp
	$(cpp) $(opts) -c $(code03)/Products.cpp

UserData.o: $(code01)/UserData.cpp $(base01)/Headers/UserData.hpp
	$(cpp) $(opts) -c $(code01)/UserData.cpp

list: clean FrankenCart.o
	nm --demangle *.o


clean:
	rm -f *.o
	rm -f *.a
	rm -f *.run
	rm -f *.out
	chmod 666 *.?pp

