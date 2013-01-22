all:
	make -C ../../Soca
	metil_comp -O3 -g3 -I../../Soca/src -DQT_THREAD_SUPPORT ServerPlugin/src/main.cpp

exec_updater:
	make -C ../../Soca
	metil_comp -ne -O3 -g3 -I../../Soca/src -DQT_THREAD_SUPPORT ServerPlugin/src/exec_updater.cpp

gdb:
	metil_comp --gdb -O3 -g3 -I../../Soca/src ServerPlugin/src/main.cpp

val:
	metil_comp --valgrind -O3 -g3 -I../../Soca/src ServerPlugin/src/main.cpp

