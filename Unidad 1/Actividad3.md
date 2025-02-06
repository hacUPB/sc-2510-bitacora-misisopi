# Solución

### ¿Qué son PC, D y A?

PC, D y A son componentes fundamentales en el modelo simplificado del Little Man Computer (LMC) y representan elementos clave del funcionamiento de una CPU real:

#### PC (Program Counter): 

- El contador de programa (Program Counter) almacena la dirección de la próxima instrucción que la CPU debe ejecutar.
- Se utiliza para llevar un seguimiento del flujo de ejecución del programa. Después de cada instrucción ejecutada, el PC se incrementa o se actualiza para apuntar a la siguiente instrucción.

#### D (DATA REGISTRER):

- Es un registro especial que almacena datos temporales durante el procesamiento de cálculos y operaciones lógicas.
- Se utiliza para realizar operaciones matemáticas (como suma o resta) y para transferir datos hacia o desde la memoria.

#### A (ADRESS REGISTRER):

- Es el registro donde se almacena temporalmente la instrucción que se está procesando.
- La CPU toma la instrucción desde la dirección indicada por el PC, la carga en este registro y luego la decodifica para determinar qué acción realizar.

### ¿Para qué los usa la CPU?

- **PC:** La CPU utiliza el PC para saber en qué parte del programa se encuentra y para garantizar que las instrucciones se ejecuten en el orden correcto. En caso de una instrucción de salto (BRP, BRZ, BRA), el valor del PC se actualiza a una dirección específica.

- **D (DATA REGISTRER):** Es la pieza central para manejar los datos durante el procesamiento. Las operaciones matemáticas y lógicas ocurren aquí antes de almacenar el resultado o enviarlo como salida.

- **A (ADRESS REGISTRER):** Permite a la CPU interpretar las instrucciones antes de ejecutarlas. Esto es crucial para seguir el ciclo de instrucción: buscar, decodificar y ejecutar.
