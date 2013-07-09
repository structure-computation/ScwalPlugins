DIR_SOURCES_SOCA = -IServerPlugin -IServerPlugin/src  -I../../Soca/src  -IServerPlugin/LMT/include  -I../../software_library/scilab-5.4.1/include 


# PATH_SCILAB = /home/ubuntu/scilab-5.4.0
# PATH_TO_LIB_SCILAB = $(PATH_SCILAB)/lib/scilab
# PATH_TO_LIB_CALL_SCILAB = $(PATH_SCILAB)/lib/thirdparty 
# 
# SCILAB_CFLAGS = -I$(PATH_SCILAB)/include/scilab
# SCILAB_LDFLAGS = -lscilab -lscicall_scilab -ltk8.5 -ltcl8.5 -lfftw3 -lscigraphic_objects  -lscilab-cli 



all:
	make -C ../../Soca
# 	export LD_LIBRARY_PATH=$(PATH_TO_LIB_SCILAB):$(PATH_TO_LIB_CALL_SCILAB)
# 	metil_comp -ne -j1 -O3 -g3 $(DIR_SOURCES_SOCA) $(SCILAB_LDFLAGS) -L$(PATH_TO_LIB_SCILAB) -L$(PATH_TO_LIB_CALL_SCILAB) $(SCILAB_CFLAGS) -Wl,-rpath $(PATH_TO_LIB_SCILAB) -Wl,-rpath $(PATH_TO_LIB_CALL_SCILAB) ServerPlugin/src/main.cpp
# 	metil_comp -ne -j1 -O3 -g3 $(DIR_SOURCES_SOCA) $(SCILAB_LDFLAGS) -L$(PATH_TO_LIB_SCILAB) -L$(PATH_TO_LIB_CALL_SCILAB) $(SCILAB_CFLAGS) ServerPlugin/src/main.cpp
	metil_comp -ne -j1 -O3 -g3 $(DIR_SOURCES_SOCA)  ServerPlugin/src/main.cpp

gdb:
	export LD_LIBRARY_PATH=$(PATH_TO_LIB_SCILAB):$(PATH_TO_LIB_CALL_SCILAB)
	metil_comp -ne --gdb -O3 -g3 $(DIR_SOURCES_SOCA) $(SCILAB_LDFLAGS) -L$(PATH_TO_LIB_SCILAB) -L$(PATH_TO_LIB_CALL_SCILAB) $(SCILAB_CFLAGS) -Wl,-rpath $(PATH_TO_LIB_SCILAB) -Wl,-rpath $(PATH_TO_LIB_CALL_SCILAB) ServerPlugin/src/main.cpp

val:
	export LD_LIBRARY_PATH=$(PATH_TO_LIB_SCILAB):$(PATH_TO_LIB_CALL_SCILAB)
	metil_comp -ne --valgrind -O3 -g3 $(DIR_SOURCES_SOCA) $(SCILAB_LDFLAGS) -L$(PATH_TO_LIB_SCILAB) -L$(PATH_TO_LIB_CALL_SCILAB) $(SCILAB_CFLAGS) -Wl,-rpath $(PATH_TO_LIB_SCILAB) -Wl,-rpath $(PATH_TO_LIB_CALL_SCILAB) src/main.cpp

