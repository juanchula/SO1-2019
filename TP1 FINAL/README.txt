1. Descomprimir el archivo "TP1_Final.tar.gz" en una carpeta. Puede usar el comando: "tar -xzvf TP1_Final.tar.gz".
2. Ingresar al directorio donde fue descomprimido y abrir una terminal en el mismo.
3. En la terminal ejecutar el comando "make".
4. En la terminal ejecutar el comando requerido para ejecutar el programa:
    Step A  -> "./main".
    Step B  -> "./main -s".
    Step C  -> "./main -l <a> <b>".
    Step D1 -> "./main -p <pid>".
    Step D2 -> "./main -f <pid>".
    Step D3 -> "./main -t <pid>".
    
    Referencias:
            -<a>   : muestra en intervalos de tiempo a.
            -<b>   : durante tiempo b.
            -<pid> : ID del proceso.
            -D1    -> FileDescriptors.
            -D2    -> Limits.
            -D3    -> KernelStackTrace.
