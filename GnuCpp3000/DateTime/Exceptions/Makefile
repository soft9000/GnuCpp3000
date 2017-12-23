link = ld
cpp = c++
opts = -std=c++14 -I../Headers/

all: ex345.run

ex345.run: ex345.cpp
	$(cpp) $(opts) -o ex345.run  ex345.cpp -L. -lera
	exec "./ex345.run"


# sudo apt-get install clang-format
format:
	find . -type f -name "*.hpp" -exec clang-format -style=Chromium -i "{}" ";"
	find . -type f -name "*.cpp" -exec clang-format -style=Chromium -i "{}" ";"

clean:
	rm -f *.o
	rm -f *.run
	rm -f *.out
	rm -f *.log
	chmod 666 *.?pp

