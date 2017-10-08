all : testEX testSAME testINCR testEMPTY

361hw2.exe: CISC361HW2mcneilea.c
	cc -std=c11 -pedantic -o CISC361HW2mcneilea.exe CISC361HW2mcneilea.c -lpthread

testEX : CISC361HW2mcneilea.c
	./CISC361HW2mcneilea.c 90 81 78 95 79 72 85

testSAME : CISC361HW2mcneilea.c
	./CISC361HW2mcneilea.c 5 5 5 5 5

testINCR : CISC361HW2mcneilea.c
	./CISC361HW2mcneilea.c 1 2 3 4 5 6 7 8 9 10

testEMPTY: CISC361HW2mcneilea.c
	./CISC361HW2mcneilea.c 

clean :
	rm -f *.exe *~ *.o
