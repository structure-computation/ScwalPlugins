

all:
	make -C ../../Soca
	metil_comp -O3 -g3 -I../../Soca/src -IServerPlugin/LMT/include -DQT_THREAD_SUPPORT ServerPlugin/src/main.cpp

gdb:
	metil_comp --gdb -O3 -g3 -I../../Soca/src -IServerPlugin/LMT/include ServerPlugin/src/main.cpp

val:
	metil_comp --valgrind -O3 -g3 -I../../Soca/src -IServerPlugin/LMT/include ServerPlugin/src/main.cpp

