#dossiers sources pour les client SOCA
DIR_SOURCES_SOCA = -IServerPlugin -IServerPlugin/src  -I../../Soca/src  

# options communes
DIR_SOURCES_LMT =  -IServerPlugin/LMT -IServerPlugin/LMT/include

# options pour la version release
OPT = -O3 -ffast-math -fexpensive-optimizations


all:
	make -C ../../Soca
	metil_comp -ne $(OPT) $(DIR_SOURCES_LMT) $(DIR_SOURCES_SOCA) -lQtCore ServerPlugin/src/main.cpp
