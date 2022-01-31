# Historial de ejecuciones
Toda ejecución que llega al servidor siempre queda registrada para su posterior evaluación por el profesorado.

**Importante**: Eliminar estos ficheros podría acarrear la suspensión de las prácticas.
Cada vez que se ejecuta un proyecto, este queda almacenado en `~/.local/state/patan-run/`. Los proyectos están organizados en directorios, los cuales tienen como nombre la fecha y la hora de su ejecución. Este sería un ejemplo después de ejecutar un proyecto Java.

```
.local/
└── state/
    └── patan-run/
        └── 2021-01-23-20-30-40/
            ├── Proyecto.iml
            ├── pom.xml
            ├── src/
            │   ├── main/java/
            │   │   └── ejercicio.java
            │   └── test/java/
            ├── target/
            └── .patan-run-2021-01-23-20-30-40/
                 └── log
```

Además, tanto la entrada como la salida del terminal también quedan almacenados en el fichero `./.patan-run-fecha-hora/log` (relativo al proyecto), sustituyendo `fecha-hora` por las mismas que el proyecto. Este fichero siempre comienza mostrando una línea con los argumentos pasados al ejecutable, seguido de la fecha y hora de inicio, traza del ejecutable y la fecha y hora de fin. Este sería un ejemplo después de ejecutar un proyecto MPI.

```
patan-run: al386125 mpi src/main.c 2
Script started on Mon 01 Feb 2021 10:20:30 AM CEST
qsub: waiting for job 12345.patan.act.uji.es to start
qsub: job 12345.patan.act.uji.es ready

Escribe un número: 123
Proceso 0 con n = 123
Proceso 1 con n = 123
patan-run: exit code 0


qsub: job 12345.patan.act.uji.es completed
Script done on Mon 01 Feb 2021 10:20:30 AM CEST
```