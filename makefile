tsp: testpermut_tsp.o sort.o result.o generateAdjMatrix.o fact.o
	gcc -g -o tsp testpermut_tsp.o sort.o result.o generateAdjMatrix.o fact.o


testpermut_tsp.o: testpermut_tsp.c tsp.h
	gcc -g -c testpermut_tsp.c

sort.o: tsp.h
	gcc -g -c sort.c 

result.o: tsp.h
	gcc -g -c result.c

fact.o: tsp.h
	gcc -g -c fact.c

generateAdjMatrix.o: tsp.h
	gcc -g -c generateAdjMatrix.c

clean: 
	rm tsp *.o