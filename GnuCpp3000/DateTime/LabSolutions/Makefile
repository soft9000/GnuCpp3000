link = ld
cpp = c++
opts = -std=c++14 -I../Headers/

all: main.run

main.run: main.o libera.a
	$(cpp) $(opts) -o main.run main.o -L. -lera
	exec "./main.run"

libera.a: TimeInfo.o TimeStruct.o TimeFormat.o LogEntry.o File.o
	ar rcs libera.a TimeInfo.o TimeStruct.o TimeFormat.o LogEntry.o File.o

main.o: main.cpp
	$(cpp) $(opts) -c main.cpp

File.o: File.cpp ../Headers/File.hpp
	$(cpp) $(opts) -c File.cpp

LogEntry.o: LogEntry.cpp ../Headers/LogEntry.hpp
	$(cpp) $(opts) -c LogEntry.cpp

TimeFormat.o: TimeFormat.cpp ../Headers/TimeFormat.hpp
	$(cpp) $(opts) -c TimeFormat.cpp

TimeInfo.o: TimeInfo.cpp ../Headers/TimeInfo.hpp
	$(cpp) $(opts) -c TimeInfo.cpp

TimeStruct.o: TimeStruct.cpp ../Headers/TimeStruct.hpp
	$(cpp) $(opts) -c TimeStruct.cpp

# sudo apt-get install clang-format
format:
	find .. -type f -name "*.hpp" -exec clang-format -style=Chromium -i "{}" ";"
	find .. -type f -name "*.cpp" -exec clang-format -style=Chromium -i "{}" ";"


clean:
	rm -f *.o
	rm -f *.a
	rm -f *.run
	rm -f *.out
	rm -f *.log
	chmod 666 *.?pp

