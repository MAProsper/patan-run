# Guía WSL
WSL (subsistema de Windows para Linux) permite a los usuarios ejecutar un entorno de Linux, incluyendo la mayoría de herramientas de línea de comandos, utilidades y aplicaciones, directamente en Windows, sin modificar y sin la sobrecarga de una máquina virtual tradicional o una configuración de arranque dual.

## Instalación
Si tienes una instalación de Windows 10 lo suficientemente reciente o una versión posterior puedes utilizar el método sencillo. No pasa nada si lo pruebas y falla, simplemente pasa al método manual.

1. Abre **PowerShell** como Administrador.

### Método sencillo
2. Ejecuta el siguiente comando y espera mientras se instala.
```powershell
wsl --install
```

3. Reinicia el ordenador para terminar la instalación.

### Método manual
2. Ejecuta el siguiente comando para habilitar la instalación de entornos de Linux.
```powershell
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
```

3. Ejecuta el siguiente comando para habilitar máquinas virtuales ligeras.
```powershell
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```

4. Reinicia el ordenador para que los anteriores cambios surtan efecto.

5. Descarga y ejecuta el instalador del núcleo de Linux.
<pre><code><a href="https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi">https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi</a></code></pre>

6. Reinicia el ordenador para que la instalación surta efecto.

7. Ejecuta el siguiente comando para habilitar el uso de máquinas virtuales ligeras para entornos de Linux en su última versión, actualmente la 2.
```powershell
wsl --set-default-version 2
```

8. Descarga e instala un entorno de Linux desde la tienda de Microsoft. Puedes usar cualquiera, aunque esta guía está basada en **Ubuntu**.
<pre><code><a href="https://microsoft.com/store/apps/9nblggh4msv6">https://microsoft.com/store/apps/9nblggh4msv6</a></code></pre>

## Primera ejecución
El entorno de Linux puede que te pregunte por unos datos iniciales, estos a continuación son sugerencias. Si quieres, puedes usar otros que te sean fáciles de recordar.

1. Abre la aplicación de **Ubuntu**.

2. Introduce como usuario Linux el mismo usuario que utilizas en Windows, aunque en minúsculas y sin espacios (si los hubiera).

3. Introduce como contraseña Linux la misma contraseña que utilizas en Windows.

4. Introduce de nuevo la misma contraseña para confirmar.

## Compartición de ficheros
El entorno de Windows y Linux no comparten el mismo sistema de ficheros, sin embargo desde un terminal **WSL** puedes acceder y transferir ficheros entre ambos. Tan solo tienes que acceder al directorio `/mnt/` y allí encontrarás todos tus discos de Windows representados como directorios, en minúsculas y sin los dos puntos.
Si en Windows tu carpeta de usuario estuviera ubicada en `C:\Users\Nombre\`, sustituyendo `Nombre` por tu usuario, en el entorno de Linux estaría ubicada en `/mnt/c/Users/Nombre/`.

## Error de entorno (0x80370102)
Tu BIOS no tiene habilitado la virtualización por hardware (Intel VT-x / AMD-V), es recomendable que lo actives siguiendo una guía. Si no pudieras, puedes probar lo siguiente.

1. Abre **PowerShell** como Administrador.

2. Ejecuta el siguiente comando para deshabilitar máquinas virtuales ligeras.
```powershell
dism.exe /online /disable-feature /featurename:VirtualMachinePlatform /norestart
```

3. Reinicia el ordenador para que el anterior cambio surta efecto.

4. Ejecuta el siguiente comando para deshabilitar el uso de máquinas virtuales ligeras para entornos de Linux.
```powershell
wsl --set-default-version 1
```

## Guía en línea
Más información y documentación actualizada disponible en línea.
<pre><code><a href="https://docs.microsoft.com/es-es/windows/wsl">https://docs.microsoft.com/es-es/windows/wsl</a></code></pre>