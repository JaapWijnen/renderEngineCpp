UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
OPENGL_INC=
OPENGL_LIB= -lGLEW -lGL
endif
ifeq ($(UNAME), Darwin)
OPENGL_INC=
OPENGL_LIB= -lglfw -framework OpenGL
endif

ENGINE_SRC = $(wildcard engine/*.cpp)
ENGINE_OBJS = ${ENGINE_SRC:.cpp=.o}
ENGINE_HEADERS = $(wildcard engine/*.h)

GAME_SRC = $(wildcard main/*.cpp shapes/*.cpp)
GAME_OBJS = ${GAME_SRC:.cpp=.o}
GAME_HEADERS = $(wildcard engine/*.h main/*.h shapes/*.h)

LOC_DIR_INC = -I./engine -I./shapes

ENGINE_NAME = engine
ENGINE_LIB = $(addsuffix .a, $(ENGINE_NAME))
ENGINE_LIB_NAME = $(addprefix lib, $(ENGINE_LIB))
EXEC = render-engine

CC= g++
COMPILER_FLAGS= -g -std=c++11
INCLUDE= $(LOC_DIR_INC) $(OPENGL_INC)
LIBS= $(OPENGL_LIB) -L./lib -l$(ENGINE_NAME)

all: ${EXEC}

run: all
	./${EXEC}

${ENGINE_LIB_NAME}: ${ENGINE_LIB}

${ENGINE_LIB}: ${ENGINE_OBJS}
	ar cr lib/${ENGINE_LIB_NAME} ${ENGINE_OBJS}

${EXEC}: ${GAME_OBJS} ${ENGINE_LIB_NAME}
	${CC} ${COMPILER_FLAGS} -o ${EXEC} ${GAME_OBJS} ${LIBS}

%.o: %.cpp ${ENGINE_HEADERS} ${GAME_HEADERS}
	${CC} -c ${COMPILER_FLAGS} -o $@ $< ${INCLUDE}

clean:
	rm -fr ${EXEC} *.o
	rm -fr main/*.o engine/*.o shapes/*.o
	rm -fr lib/${ENGINE_LIB_NAME}
