# Lanzamiento de trabajos en patan
El servidor de cálculo para docencia, patan, controla el acceso a un conjunto de nodos de cálculo, sobre los cuales se pueden realizar las pruebas de rendimiento requeridas en los ejercicios de prácticas. Para este fin, el servidor hace uso del gestor de colas PBS (Portable Batch System), comúnmente utilizado en el ámbito de la Computación de Altas Prestaciones (High Performance Computing). Seguidamente se describen los pasos a seguir para utilizar este servidor.

## Preparación del entorno local
1. Comprueba que tienes lo necesario para, al menos, poder ejecutar proyectos genéricos en tu sistema.

| Sistema | Proyecto genérico    | Proyecto gráfico                    |
| ------- | -------------------- | ----------------------------------- |
| Linux   | Terminal por defecto | Entorno incluido en el sistema      |
| MacOS   | Terminal por defecto | [XQuartz](https://www.xquartz.org/) |
| Windows | [WSL](https://docs.microsoft.com/es-es/windows/wsl) ([guía](docs/wsl.md)) | Entorno incluido según la versión                            |
| Android | [Termux](https://play.google.com/store/apps/details?id=com.termux) | [XServer XSDL](https://play.google.com/store/apps/details?id=x.org.server) |

2. Descarga y guarda el ejecutable en cualquier lugar mediante un navegador web.
<pre><code><a href="https://raw.githubusercontent.com/MAProsper/patan-run/master/patan-run">https://raw.githubusercontent.com/MAProsper/patan-run/master/patan-run</a></code></pre>

3. Instala el ejecutable con el siguiente comando, sustituye la ruta del ejecutable guardado y el usuario por los tuyos concretos.
```bash
bash ./ejecutable alXXXXXX install
```

4. Reinicia el terminal para terminar la instalación.

## Ejecución de pruebas remotas
**Importante**: Si una ejecución no responde, cancélala mediante <kbd>Ctrl</kbd>+<kbd>C</kbd>.

1. Desde un terminal, posiciónate en la raíz del proyecto con el comando `cd`, en este ejemplo sería la carpeta `Proyecto`.
```
Proyecto/
├── Proyecto.iml
├── pom.xml
├── src/
│   ├── main/java/
│   │   └── ejercicio.java
│   └── test/java/
└── target/
```

### Proyectos Java
2. Mira el fichero donde está declarado el método `main` que quieres ejecutar y junta lo que pone en la línea `package` (si hubiera) con el nombre de la clase para obtener el nombre absoluto de la clase, en este ejemplo sería `paquete.subpaquete.Clase`.
```java
package paquete.subpaquete;

public class Clase {
	public static void main(String[] args) {}
}
```

3. Ejecuta el proyecto con el siguiente comando, sustituye el nombre absoluto y los argumentos (si hubiera) por los tuyos concretos.
```bash
patan-run java nombreAbsoluto argumentos…
```

### Proyectos MPI
2. Obtén la ruta relativa del fichero a ejecutar, en este ejemplo sería `./src/main.c`.
```
Proyecto/
├── src/
│   └── main.c
└── target/
```

3. Ejecuta el proyecto con el siguiente comando, sustituye la ruta relativa, el número de nodos y los argumentos (si hubiera) por los tuyos concretos.
```bash
patan-run mpi ruta nodos argumentos…
```

# Más información
- [Historial de ejecuciones](docs/history.md)
- [Crear subcomandos](docs/subcommand.md)
- [Uso avanzado](docs/advanced.md)
- [Guía WSL](docs/wsl.md)