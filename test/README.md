# Tests
Must be executed manually with a valid account on the target server.

## Java
Shows a window, writes `1` to console (as many as threads), user writes `2`, writes `2` to the console (as many as threads), user closes window.
```bash
patan-run java Java 1
```

## MPI
Writes `1` to console (as many as nodes), user writes `2`, writes `2` to the console (as many as nodes).
```bash
patan-run mpi mpi.c 2 1
```

## OMP
Writes `1` to console (as many as threads), user writes `2`, writes `2` to the console (as many as threads).
```bash
patan-run omp omp.c 2 1
```

## CUDA
Writes `1` to console (as many as kernel), user writes `2`, writes `2` to the console (as many as kernel).
```bash
patan-run cuda cuda.cu 1
```
