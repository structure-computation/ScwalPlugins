DIR_SOURCES_SOCA = -IServerPlugin -IServerPlugin/src  -I../../Soca/src  -IServerPlugin/LMT/include 
CASROOT = /usr/include/opencascade

CPP_FLAGS = -I/usr/include/opencascade -I${CASROOT}/inc -DHAVE_CONFIG_H -DHAVE_LIMITS_H -DHAVE_WOK_CONFIG_H -DOCC_CONVERT_SIGNALS  -DCSFDB
LINK_FLAGS = -L/usr/lib/opencas -L${CASROOT}/lib64 -lTKernel -lTKMath -lTKAdvTools -lTKMesh -lTKIGES -lTKSTEPBase -lTKSTEP209 -lTKSTEP -lstdc++ -lTKBRep -lTKXSBase

all:
	make -C ../../Soca
	metil_comp -ne -j1 -O3 -g3 ${LINK_FLAGS} ${CPP_FLAGS} $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp

gdb:
	metil_comp -ne --gdb -O3 -g3 $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp

val:
	metil_comp -ne --valgrind -O3 -g3 $(DIR_SOURCES_SOCA) src/main.cpp

