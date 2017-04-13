presto = c++ --std=c++11 -I../Headers

all: main.run  

Order.o : Order.cpp
	$(presto) -c Order.cpp 

Product1.o :  Product1.cpp
	$(presto) -c Product1.cpp 

Product.o :  Product.cpp
	$(presto) -c Product.cpp 

AffiliateProduct.o :  AffiliateProduct.cpp
	$(presto) -c AffiliateProduct.cpp 

CompanyProduct.o :  CompanyProduct.cpp
	$(presto) -c CompanyProduct.cpp 

libco.a :  Order.o Product.o CompanyProduct.o AffiliateProduct.o
	ar rcs libco.a Order.o Product.o CompanyProduct.o AffiliateProduct.o

main.run :  main.cpp libco.a
	$(presto) main.cpp -L. -lco
	exec "./a.out"

clean:
	rm *.o
	rm *.a
	rm *.out


