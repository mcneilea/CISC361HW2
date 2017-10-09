all : testEX testSAME testINCR testEMPTY

CISC361HW2mcneilea.exe: CISC361HW2mcneilea.c
	cc -pthread -std=c11 -pedantic -o CISC361HW2mcneilea.exe CISC361HW2mcneilea.c

testEX : CISC361HW2mcneilea.c Makefile
	./CISC361HW2mcneilea.exe 90 81 78 95 79 72 85

testSAME : CISC361HW2mcneilea.c Makefile
	./CISC361HW2mcneilea.exe 5 5 5 5 5

testINCR : CISC361HW2mcneilea.c
	./CISC361HW2mcneilea.exe 1 2 3 4 5 6 7 8 9 10

testEMPTY: CISC361HW2mcneilea.c
	./CISC361HW2mcneilea.exe

clean :
	rm -f *.exe *~ *.o
