#include <stdio.h>
#include "mpi.h"
main(int argc, char** argv){
int my_PE_num, numbertoreceive; //defining the variables//
MPI_Status status;  //checks the status of  MPI//
MPI_Init(&argc, &argv);  //calling the first routine//
MPI_Comm_rank(MPI_COMM_WORLD, &my_PE_num);  //This routine returns to every PE its rank, or unique address from 0 to PEs-1//
MPI_Barrier(MPI_COMM_WORLD);  //putting barrier to display output in proper order//

	switch (my_PE_num)  //making a switch to perform the operation using case//
	{
		//start of operation//
		case 0:  //Receiving from PE1 and sending to PE7//
			{
				MPI_Recv( &numbertoreceive, 1, MPI_INT,1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  //giving address of PE1//
  				printf("PE %d received: %d\n", my_PE_num,numbertoreceive);  //printing the output//
				MPI_Send( &my_PE_num, 1, MPI_INT, 7, 10, MPI_COMM_WORLD);   //giving address of PE7//
			} 
			
		case 1:  //Receiving from PE2 and sending to PE0//
			{
				MPI_Recv( &numbertoreceive, 1, MPI_INT,my_PE_num+1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  //incrementing PE to +1 to change the receiving PE//
				printf("PE %d received: %d\n", my_PE_num,numbertoreceive);  //printing the output//
				MPI_Send( &my_PE_num, 1, MPI_INT, my_PE_num-1, 10, MPI_COMM_WORLD);  //decrementing PE to -1 to change the semding PE//
			}
			
		case 2:  //Receiving from PE3 and sending to PE1//
			{
				MPI_Recv( &numbertoreceive, 1, MPI_INT,my_PE_num+1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  //incrementing PE to +1 to change the receiving PE//
				printf("PE %d received: %d\n", my_PE_num,numbertoreceive);  //printing the output//
				MPI_Send( &my_PE_num, 1, MPI_INT, my_PE_num-1, 10, MPI_COMM_WORLD);   //decrementing PE to -1 to change the semding PE//
			}
			
		case 3:  //Receiving from PE4 and sending to PE2//
			{
				MPI_Recv( &numbertoreceive, 1, MPI_INT,my_PE_num+1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  //incrementing PE to +1 to change the receiving PE//
				printf("PE %d received: %d\n", my_PE_num,numbertoreceive);  //printing the output//
				MPI_Send( &my_PE_num, 1, MPI_INT, my_PE_num-1, 10, MPI_COMM_WORLD); //decrementing PE to -1 to change the semding PE//
			}
			
		case 4:  //Receiving from PE5 and sending to PE3//
			{
				MPI_Recv( &numbertoreceive, 1, MPI_INT,my_PE_num+1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  //incrementing PE to +1 to change the receiving PE//
				printf("PE %d received: %d\n", my_PE_num,numbertoreceive);  //printing the output//
				MPI_Send( &my_PE_num, 1, MPI_INT, my_PE_num-1, 10, MPI_COMM_WORLD); //decrementing PE to -1 to change the semding PE//
			}
			
		case 5:  //Receiving from PE6 and sending to PE4//
			{
		    	MPI_Recv( &numbertoreceive, 1, MPI_INT,my_PE_num+1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  //incrementing PE to +1 to change the receiving PE//
				printf("PE %d received: %d\n", my_PE_num,numbertoreceive);  //printing the output//
				MPI_Send( &my_PE_num, 1, MPI_INT, my_PE_num-1, 10, MPI_COMM_WORLD); //decrementing PE to -1 to change the semding PE//
			}
			
		case 6:  //Receiving from PE7 and sending to PE5//
			{
				MPI_Recv( &numbertoreceive, 1, MPI_INT,my_PE_num+1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  //incrementing PE to +1 to change the receiving PE//
 				printf("PE %d received: %d\n", my_PE_num,numbertoreceive); //printing the output//
				MPI_Send( &my_PE_num, 1, MPI_INT, my_PE_num-1, 10, MPI_COMM_WORLD); //decrementing PE to -1 to change the semding PE//
			}
		
		default:  //Receiving from PE0 and sending to PE6//
			{
				MPI_Send( &my_PE_num, 1, MPI_INT, 6, 10, MPI_COMM_WORLD); //giving address of PE6//
			}
		
	}
	MPI_Recv( &numbertoreceive, 1, MPI_INT,0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  //giving address of PE0//
	printf("PE %d received: %d\n", my_PE_num,numbertoreceive);  //printing the output//		
    MPI_Finalize(); //This is the companion to MPI_Init//
 }
