MACHINE_TYPE = CPU
DIR_SOURCES_COMPUTE = -IServerPlugin/src/GEOMETRY -IServerPlugin/src/UTILS -IServerPlugin/src/UTILS/hdf -IServerPlugin/src/UTILS/xdmf  -IServerPlugin/src/UTILS/json_spirit 
DIM = 2
CFLAGS=`xml2-config --cflags`
LIBS=`xml2-config  --libs`
DIR_SOURCES_LMT =  -I../../LMT -I../../LMT/include -I../../LMT/include/LDL -I../../LMT/include/util -Iusr/include/suitesparse
GLOB_VAR = -D$(MACHINE_TYPE) -DDIM=$(DIM) -DTYPE=float -DTYPEREEL=float -DLDL -DWITH_CHOLMOD -DWITH_UMFPACK



all:
	make -C ../../Soca
	metil_comp -ne -O3 -g3 -I../../LMT/include -I../../Soca/src -DDIM=2 $(GLOB_VAR) $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(CFLAGS) $(LIBS) ServerPlugin/src/main.cpp

old:
	make -C ../../Soca
	metil_comp -O3 -g3 -I../../LMT/include -I../../Soca/src -DDIM=2 $(GLOB_VAR) $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(CFLAGS) $(LIBS) ServerPlugin/src/main_old.cpp

gdb:
	metil_comp --gdb -O3 -g3 -I../../LMT/include -I../../Soca/src ServerPlugin/src/main.cpp

val:
	metil_comp --valgrind -O3 -g3 -I../../LMT/include -I../../Soca/src ServerPlugin/src/main.cpp

