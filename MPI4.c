#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv)  //main function//
{
    int tea, i, function, error; //initialization stage//
	int my_PE_num, numbertoreceive; 

	MPI_Status status;  
    MPI_Init(&argc, &argv);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN); //to set mpi error handler to return error value//

		i = 0;
		tea=0;  //tea = temperary variable//
		while(i!=70) //took a random value of 70 to check the error// 
    	{	     
        	tea+=1;
        	//error=MPI_Send( &function, 1, MPI_INT, i, 10, MPI_COMM_WORLD);
			error=MPI_Bcast(&function, 1, MPI_INT, i, MPI_COMM_WORLD); //to brodcast a function value//
				if(error!=0) //to detect and print the error//				
				{
					printf("\nI am running on %d PEs\n",tea-1);
					MPI_Abort(MPI_COMM_WORLD,error);//to stop the operation//
				}
			i+=1;
   		}
    MPI_Finalize();
    return 0;
}

