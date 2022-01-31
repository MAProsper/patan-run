# Subcomandos adicionales
## Desinstalación
```bash
patan-run remove
```

## Terminal remota
```bash
patan-run ssh [args...]
```

## Ayuda con el subcomado
```bash
patan-run [java|...]
```

## Información de la herramienta actual
```bash
patan-run version
```

# Modificaciones de comportamiento
Mediante variables de entorno uno puede moficiar el comportamiento de la herramienta ante ciertos subcomandos.

## `ID`
Indentificador de ejecucion, utilizado en el historial.
- Por defecto: fecha y hora en formato ISO 8601
- Ejemplo: `2021-01-23-20-30-40`
- Historial deshabilitado: `0`

## `TMOUT`
Tiempo de inactividad en segundos, cuando se supera se pediran de nuevo las credenciales.
- Por defecto: `256`
- Minimo: `1`

## `PROXY`
Nombre de cuenta para usar en el proxy.
- Por defecto: `$USER`
- Ejemplo: `al386125`

## `ENV`
Ruta al fichero de configuracion del shell.
- Por defecto: `~/.${SHELL}rc`
- Ejemplo: `~/.bashrc`