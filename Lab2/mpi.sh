#!/bin/bash

#BATCH --job-name slurm_mpi 
#SBATCH --nodes 2
#SBATCH --ntasks 10
#SBATCH --ntasks-per-node 16
#SBATCH --mem 20000
#SBATCH --partition partedu 

cd $SLURM_SUBMIT_DIR
echo 0 > cap
/opt/openmpi/bin/mpirun -np 10 ./parallelSum
