EXEC = prog.exe
CXX = g++
CXX_FLAGS = -I include -Wall -Wextra -pedantic -Wno-unused-parameter -Wno-write-strings -Werror -c
LD_FLAGS = -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

SRC1 = $(wildcard src/*.cpp)
SRC2 = $(wildcard src/*/*.cpp)

OBJ1 = ${SRC1:.cpp=.o}
OBJ2 = ${SRC2:.cpp=.o}


rm : 
	del src\*.o

all : $(EXEC)

$(EXEC) : $(OBJ1) $(OBJ2)
	$(CXX) -o $@ $^ $(LD_FLAGS)


src/%.o : src/%.cpp
	$(CXX) -o $@ $< $(CXX_FLAGS)

src/%/%.o : src/%/%.cpp
	$(CXX) -o $@ $< $(CXX_FLAGS)
