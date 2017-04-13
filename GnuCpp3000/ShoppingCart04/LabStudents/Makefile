cpp = c++
base01 = ../../ShoppingCart01
code01 = $(base01)/LabSolutions
opts = -std=c++11 -I../Headers/ -I$(base01)/Headers

all: clean main.run

# Outfile (-o) MUST be specified FIRST to start dependency lookups
main.run: main.o FrankenCart.o libcart.a
	$(cpp) $(opts) -o main.run main.o FrankenCart.o -L. -lcart
	exec "./main.run"

libcart.a: UserData.o Products.o
	ar rcs libcart.a UserData.o Products.o

main.o: main.cpp FrankenCart.o $(base01)/Headers/AbsUserCart1.hpp
	$(cpp) $(opts) -c main.cpp

FrankenCart.o: FrankenCart.cpp ../Headers/FrankenCart3.hpp
	$(cpp) $(opts) -c FrankenCart.cpp

Products.o: Products.cpp ../Headers/Products.hpp
	$(cpp) $(opts) -c Products.cpp

UserData.o: $(code01)/UserData.cpp $(base01)/Headers/UserData.hpp
	$(cpp) $(opts) -c $(code01)/UserData.cpp

list: clean UserData.o
	nm --demangle *.o

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.run
	rm -f *.out
	chmod 666 *.?pp

