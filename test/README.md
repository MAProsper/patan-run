# Tests
- Clone repository and set working directory to `test`.
- Execute manually with valid account in target server.
- Prefix all commands with `HIST=.cache/patan-test` (isolate remote environment).

## patan-run
**Important**: Modifies software installation. Replace user appropriately.
```sh
bash -i install.sh ../patan-run alXXXXXX
```
- System writes `1` to terminal.
- System writes `0` to terminal.
- System writes `1` to terminal.
- System writes `0` to terminal.
---
```sh
patan-run report version
```
- System creates `patan-run-XXXXXX` report file.
- System writes version to terminal.

## Java
```sh
patan-run java Java 1
```
- System shows window.
- System writes `1` to terminal (2 times).
- User writes `2` to terminal.
- System writes `2` to terminal (2 times).
- User closes window.

## MPI
```sh
patan-run mpi mpi.c 2 1
```
- System writes `1` to terminal (2 times).
- User writes `2` to terminal.
- System writes `2` to terminal (2 times).

## OMP
```sh
patan-run omp omp.c 2 1
```
- System writes `1` to terminal (2 times).
- User writes `2` to terminal.
- System writes `2` to terminal (2 times).

## CUDA
```sh
patan-run cuda cuda.cu 1
```
- System writes `1` to terminal (4 times).
- User writes `2` to terminal.
- System writes `2` to terminal (4 times).

## PBS
```sh
patan-run pbs pbs.pbs 1
```
- System writes `patan-test:1` to terminal.
- System writes `1` to terminal.
- User writes `2` to terminal.
- System writes `2` to terminal.
