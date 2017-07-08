/**
*   El siguiente archivo es utilizado para definir los valores booleanos "true" y "false"
*   Estos están definidos en el estándar 'C99' a través de la librería 'stdbool.h', pero
*   por simplicidad en la compilación (académicamente hablando) se utilizará este método
*   alternativo, pero se recomienda utilizar el del estándar.
**/

//el tipo 'bool' se comportará como un entero
typedef int bool;

//siendo 'true' el valor '(int) 1'
#define true 1

//y 'false' '(int) 0'
#define false 0