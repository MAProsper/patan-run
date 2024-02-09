# Tests
Must be executed manually with a valid account on the target server.

## Java
Shows a window and after 5s writes `1` to the console (window must be closed manually).
```bash
patan-run java Main 1
```

## MPI
Writes `1` to console (as many as nodes), user writes `2`, writes `2` to the console (as many as nodes).
```bash
patan-run mpi mpi.c 2 1
```

## OMP
Writes `1` to console (as many as threads), user writes `2`, writes `2` to the console (as many as threads).
```bash
patan-run omp omp.c 1
```

## CUDA
Writes usage information to console.
```bash
patan-run cuda -h
```
