DIR_SOURCES_SOCA = -IServerPlugin -IServerPlugin/src  -I../../Soca/src  -IServerPlugin/LMT/include 


all:
	make -C ../../Soca
	metil_comp -ne -j1 -O3 -g3 $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp

exec:
	metil_comp -O3 -g3 $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp


gdb:
	metil_comp -ne --gdb -O3 -g3 $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp

val:
	metil_comp -ne --valgrind -O3 -g3 $(DIR_SOURCES_SOCA) src/main.cpp

