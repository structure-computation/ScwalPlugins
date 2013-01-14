DIR_SOURCES_SOCA = -IServerPlugin -IServerPlugin/src  -I../../Soca/src  -IServerPlugin/LMT/include -IServerPlugin/dic
DIR_SOURCES_DIC = -IServerPlugin -IServerPlugin/LMT/include  -I../../Soca/src 

all:
	make -C ../../Soca
	metil_comp -j1 -O3 -g3 $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp

gdb:
	metil_comp --gdb -O3 -g3 $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp

val:
	metil_comp --valgrind -O3 -g3 $(DIR_SOURCES_SOCA) src/main.cpp

