driver : driver.o statemodel.o system.o state.o accepting.o manufacturing.o processing.o shipping.o
     gcc driver.o statemodel.o system.o state.o accepting.o manufacturing.o processing.o shipping.o

driver.o: driver.c system.h statemodel.h
	 gcc -c driver.c

system.o: system.c system.h
	gcc -c system.c -o system.o

statemodel.o: system.h statemodel.h statemodel.c
	gcc -c statemodel.c

state.o: state.h state.c
	gcc -c state.c -o state.o
