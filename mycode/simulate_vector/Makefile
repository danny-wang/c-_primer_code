#  
# Simple .so Makefile  
#  
  
CXX      := g++  
LD      := ld  
CXXFLAGS  :=   -std=c++11
LDFLAGS := -shared -fPIC 
#SOURCE  := $(wildcard *.cpp)  
SOURCE  := Blob.cpp BlobPtr.cpp
OBJS    := $(patsubst %.cpp,%.o,$(SOURCE))  
TARGET_LIB := libblob.so  
  
all:$(OBJS)  
	@echo $(OBJS)   
	$(LD) $(LDFLAGS) -o $(TARGET_LIB) $(OBJS)   
  
%.o:%.cpp  
	@echo Compiling $< ...  
	$(CXX) -c $(CXXFLAGS)  $< -o $*.o  
  
.PHONY: clean  
  
clean:  
	rm *.so *.o -rf  