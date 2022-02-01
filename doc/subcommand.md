# Creación de subcomandos propios
Todo subcomando siempre se divide en cuatro secciones; se mostrará como ejemplo ilustrativo la implementación del subcomando `mpi`.

Todas las secciones siempre han de empezar por la siguiente línea:
```bash
#!/sección/subcomando
```

Durante todas las secciones siempre se cumplira y ha de mantener lo siguiente:
- Directorio de trabajo actual: Raíz del proyecto
- Argumentos del ejecutable: Pasados por el usuario
- Comandos de información: `info` y `err` (termina la ejecución)
- Variable TMP: Directorio temporal de ejecución

## Especificación de secciones
### `man`: Ayuda del usuario en caso de sintaxis incorrecta
Cada una de las líneas en este bloque siempre ha de comenzar por una almohadilla seguida de un espacio. La primera es la sintaxis esperada y las siguientes, indentadas con un tabulador, son la especificación del argumento; estas últimas líneas suelen ser el nombre, un ejemplo y su descripción separados por tabuladores.
```bash
#!/man/mpi
# main nodes [args...]
# 	main	main.c		(main file's relative path)
# 	nodes	16		(number of nodes to utilise)
# 	args	...		(program arguments)
```

### `usr`: Verificación local de los argumentos antes de conectar
La primera línea es la verificación del número de argumentos; si no se cumple, se debe ejecutar el método man para mostrar la sección anterior. Las siguientes líneas verifican cada argumento; si no se cumple alguno, se debe ejecutar el método `err` dando una explicación.
```bash
#!/usr/mpi
[ $# -ge 4 ]			|| man
[ -f "$3" ]			|| err 'main file not found'
[[ "$4" =~ ^[0-9]+$ ]]	|| err 'nodes must be positive integer'
```

### `srv`: Lanzamiento a la cola PBS del servidor
Aquí hay que definir las opciones que se usarán para el comando `qsub` mediante el comando `job`; si no se quiere ninguna, se debe ejecutar sin argumentos.
```bash
#!/srv/mpi
job -q 'bi' -l "nodes=$4:ppn=4"
```

### `job`: Tarea PBS a ejecutar en el servidor
```bash
#!/job/mpi
EXE="$TMP/exe"; NODE="$TMP/node"
uniq "$PBS_NODEFILE" >"$NODE"; mpicc "$3" -o "$EXE"
mpirun -mca 'btl_tcp_if_include' 'eth0' -np "$4" -machinefile "$NODE" "$EXE" "${@:5}"
```