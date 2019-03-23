# To build a image
docker build -t run-test:0.1 .

../AED/lai-aed/LAI-AED
	|
	| - test
	| 


#Run docker
1.
docker run -ti --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -v $PWD:/AED/lai-aed/LAI-AED  run-test:0.1 bash -c "cd /AED/lai-aed/LAI-AED; make v"      	

1.1
docker run -ti --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -v $PWD:/AED/lai-aed/LAI-AED  run-test:0.1 bash -c "cd /AED/lai-aed/LAI-AED; gcc p2.c -g -o p2 && valgrind --leak-check=full -v ./p2 ./m4x4.txt && make v"

#-------------------------------------- Old execution commands ---------------------------	
# Run 2 src
docker run -ti --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -v $PWD:/AED  memory-test:0.1 bash -c "cd /AED/src ; make  && valgrind --leak-check=full ./newWords ../test/doc.txt INICIO "	

# To run  a docker 
*New 2* - Added gdb debuggin tag " --cap-add=SYS_PTRACE --security-opt seccomp=unconfined "
docker run -ti --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -v $PWD:/AED  memory-test:0.1 bash -c "cd /AED/src ; gcc palTab.c -g -o palTab && valgrind --leak-check=full ./palTab ../test/doc.txt ; make t "

*New* - Added subdirectories: '-v' gives a shared folder - So, is like that docker image doesn't exists
docker run -ti -v $PWD:/AED  memory-test:0.1 bash -c "cd /AED/src ; gcc palTab.c -g -o palTab && valgrind --leak-check=full ./palTab ../test/doc.txt"

*Old*
docker run -ti -v $PWD:/AED  memory-test:0.1 bash -c "cd /AED/ ; gcc palTab.c -g -o palTab && valgrind --leak-check=full ./palTab doc.txt"
