
CXX      := g++  
LD      := ld  
CXXFLAGS  :=  -Wall -c -std=c++11
LIB += -L../
LIB += -lblob

IFLAGS = -I../

main: main.o 
	$(CXX) $(IFLAGS) $(LIB)  -o $@ $^ -Wl,-rpath=../

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< $(IFLAGS)


clean:
	rm *.o -f