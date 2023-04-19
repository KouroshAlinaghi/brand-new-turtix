APP = turtix
SRC_DIR = src
EXE_DIR = bin
OBJ_DIR = obj
CFLAGS = --std=c++11 -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system

all: ${APP}

$(APP): objs
	g++ ${CFLAGS} ${OBJ_DIR}/*.o -o ${EXE_DIR}/$@

objs: make_dirs
	g++ -c ${SRS_DIR}/*.cpp -o ${OBJ_DIR}/

run: all
	${EXE_DIR}/${APP}

make_dirs:
	mkdir -p ${EXE_DIR}
	mkdir -p ${OBJ_DIR}
	mkdir -p ${SRC_DIR}

clean:
	rm -f ${OBJ_DIR}/*.o ${EXE_DIR}/main