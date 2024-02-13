# Tests
Must execute manually with valid account in target server.

## Java
```bash
patan-run java Java 1
```
- System shows window.
- System writes `1` to terminal (2 times).
- User writes `2` to terminal.
- System writes `2` to terminal (2 times).
- User closes window.

## MPI
```bash
patan-run mpi mpi.c 2 1
```
- System writes `1` to terminal (2 times).
- User writes `2` to terminal.
- System writes `2` to terminal (2 times).

## OMP
```bash
patan-run omp omp.c 2 1
```
- System writes `1` to terminal (2 times).
- User writes `2` to terminal.
- System writes `2` to terminal (2 times).

## CUDA
```bash
patan-run cuda cuda.cu 1
```
- System writes `1` to terminal (4 times).
- User writes `2` to terminal.
- System writes `2` to terminal (4 times).
