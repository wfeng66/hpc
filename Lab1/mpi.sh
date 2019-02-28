#!/bin/bash

#BATCH --job-name slurm_mpi
#SBATCH --nodes 2
#SBATCH --ntasks 16
#SBATCH --ntasks-per-node 16
#SBATCH --mem 20000
#SBATCH --partition partedu

cd $SLURM_SUBMIT_DIR
echo 0 > cap
mpirun -np 16  ./hello
