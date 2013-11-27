DIR_SOURCES_SOCA = -IServerPlugin -IServerPlugin/src `xml2-config --cflags` -I../../Soca/src  -IServerPlugin/LMT/include -IServerPlugin/dic

all:
	make -C ../../Soca
	metil_comp -ne -j1 -O3 -g3 $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp

mesher:
	make -C ../../Soca
	metil_comp -ne -j1 -O3 -g3 $(DIR_SOURCES_SOCA) ServerPlugin/src/main_gmsh.cpp

gdb:
	metil_comp -ne --gdb -O3 -g3 $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp

val:
	metil_comp -ne --valgrind -O3 -g3 $(DIR_SOURCES_SOCA) src/main.cpp

