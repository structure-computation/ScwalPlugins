#parametres a modifier si necessaire
#nombre de processeurs pour la compilation
NB_COMP_PROC = 3
#dimension du probleme
DIM = 3
# emplacement de la libraire MPI
MPI_LIB = /usr/include/openmpi
# type de machine
ARCHITECTURE = CPU

#dossiers sources pour les client SOCA
DIR_SOURCES_SOCA = -IServerPlugin -IServerPlugin/src  -I../../Soca/src  

#dossiers sources
DIR_SOURCES_SC = -IServerPlugin/build_scills -IServerPlugin/build_scills/problem_pb_elast -IServerPlugin/src_scills -IServerPlugin/src_scills/DEFINITIONS -IServerPlugin/src_scills/FORMULATIONS -IServerPlugin/src_scills/ITERATIONS -IServerPlugin/src_scills/ITERATIONS/LINEAR -IServerPlugin/src_scills/ITERATIONS/LOCAL -IServerPlugin/src_scills/ITERATIONS/ERROR -IServerPlugin/src_scills/MAILLAGE -IServerPlugin/src_scills/MATERIAUX -IServerPlugin/src_scills/MPI -IServerPlugin/src_scills/OPERATEURS -IServerPlugin/src_scills/OPERATEURS/INTER -IServerPlugin/src_scills/OPERATEURS/MACRO -IServerPlugin/src_scills/OPERATEURS/SST -IServerPlugin/src_scills/POSTTRAITEMENTS -IServerPlugin/src_scills/PROBMICRO -IServerPlugin/src_scills/UTILITAIRES 
DIR_SOURCES_GEOMETRY = -IServerPlugin/src_scills -IServerPlugin/src_scills/GEOMETRY -IServerPlugin/src_scills/COMPUTE -IServerPlugin/src_scills/UTILS -IServerPlugin/src_scills/UTILS/hdf -IServerPlugin/src_scills/UTILS/xdmf -IServerPlugin/src_scills/UTILS/json_spirit 

# options communes
GLOB_VAR = -DDIM=$(DIM) -D$(ARCHITECTURE)  -DTYPE=double -DTYPEREEL=double  -DLDL -Dcrout_alain
CFLAGS= -LServerPlugin/UTIL_scills/metis -lmetis -L$(MPI_LIB)/lib -lmpi -lmpi_cxx
DIR_SOURCES_LMT =  -IServerPlugin/LMT -IServerPlugin/LMT/include -Iusr/include/suitesparse
DIR_SOURCES_CUDA = -Iusr/local/cuda/include -Ihome/ubuntu/driver_toolkit/NVIDIA_GPU_Computing_SDK/C/common/inc 

DIR_SOURCES_MPI = -I$(MPI_LIB) -I$(MPI_LIB)/include

# options pour la version release
PRG_multi_release = SC_multi_$(DIM)_$(ARCHITECTURE).exe
DIR_build_release = --comp-dir build/SC_multi_$(DIM)_$(ARCHITECTURE)_release
OPT = -j$(NB_COMP_PROC) -O3 -ffast-math -fexpensive-optimizations


#all:
#	$(LOC_MC)  -o scillsResultClient.exe $(GLOB_VAR) $(DIR_SOURCES_LMT) $(DIR_SOURCES_SC) $(DIR_SOURCES_GEOMETRY) $(DIR_SOURCES_MPI) $(CFLAGS) $(LIBS) $(OPT) $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp

all:
	make -C ../../Soca
	metil_comp -O3 -g3 $(GLOB_VAR) $(DIR_SOURCES_LMT) $(DIR_SOURCES_SC) $(DIR_SOURCES_GEOMETRY) $(DIR_SOURCES_MPI) $(CFLAGS) $(LIBS) $(OPT) $(DIR_SOURCES_SOCA) ServerPlugin/src/main.cpp


