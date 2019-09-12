1. Descomprimir el archivo "TP1_Final.tar.gz" en una carpeta. Puede usar el comando: "tar -xzvf TP1_Final.tar.gz".
2. Ingresar al directorio donde fue descomprimido y abrir una terminal en el mismo.
3. En la terminal ejecutar el comando "make".
4. En la terminal ejecutar el comando requerido para ejecutar el programa:
    Step A  -> "./rdproc".
    Step B  -> "./rdproc -s".
    Step C  -> "./rdproc -l <a> <b>".
    Step D1 -> "./rdproc -p <pid>".
    Step D2 -> "./rdproc -f <pid>".
    Step D3 -> "./rdproc -t <pid>".
    
    Referencias:
            -<a>   : muestra en intervalos de tiempo a.
            -<b>   : durante tiempo b.
            -<pid> : ID del proceso.
            -D1    -> FileDescriptors.
            -D2    -> Limits.
            -D3    -> KernelStackTrace.

Observaciones: -Todos los comandos presentados en este txt estan encerrados en comillas pero estas no deben ser ingresadas en la terminal.
             -En donde haya <x> se debera reemplazar por una variable.
