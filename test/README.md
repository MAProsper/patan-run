# Tests
Must be executed manually with valid account on target server.

## Java
```bash
patan-run java Java 1
```
- System shows window.
- System writes `1` to console (2 times).
- User writes `2` to console.
- System writes `2` to console (2 times).
- User closes window.

## MPI
```bash
patan-run mpi mpi.c 2 1
```
- System writes `1` to console (2 times).
- User writes `2` to console.
- System writes `2` to console (2 times).

## OMP
```bash
patan-run omp omp.c 2 1
```
- System writes `1` to console (2 times).
- User writes `2` to console.
- System writes `2` to console (2 times).

## CUDA
```bash
patan-run cuda cuda.cu 1
```
- System writes `1` to console (4 times).
- User writes `2` to console.
- System writes `2` to console (4 times).
