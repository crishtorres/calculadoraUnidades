#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int decBinario(int);
int decHexa(int);
int decOctal(int);
int binDecimal(char[]);

int main(){
    int   numero = 0;
    int   opcion = 0;
    int   fEntrada =0;
    int   nDB=0;
    char  nHexa;
    char  nBinario[50];

    printf("Seleccione el formato de entrada : \n1-DECIMAL\n2-BINARIO\n3-HEXADECIMAL\n");
    scanf("%d",&fEntrada);

    switch(fEntrada){
        case 1: //DECIMAL
            printf("Ingrese el numero decimal : \n");
            scanf("%d",&nDB);
            decBinario(nDB);
            decHexa(nDB);
            break;
        case 2: //BINARIO
            printf("Ingrese el numero binario : \n");
            scanf("%s",nBinario);
            printf("Valor ingresado %s \n",nBinario);
            binDecimal(nBinario);
            break;
        case 3: //HEXADECIMAL
            printf("Ingrese el numero hexadecimal : \n");
            scanf("%s",nHexa);
    }


    printf("Seleccione una de las opciones : \n1-DECIMAL a BINARIO\n2-DECIMAL a HEXADECIMAL\n3-DECIMAL a OCTAL\n");
    scanf("%d",&opcion);

    printf("\nIngrese el numero a convertir:\n");
    scanf("%d",&numero);

    switch(opcion){
        case 1: decBinario(numero); break;
        case 2: decHexa(numero); break;
        case 3: decOctal(numero); break;
    }
    //numero = 5137;
    //resultado = 155;
    //decOctal(numero);
}

int binDecimal(char numero[]){
    int i=0, j=0;
    char longitud;
    int nDec=0;

    //OBTENGO EL TAMAÑO DEL VECTOR
    longitud=strlen(numero);

    //RECORRO EL VECTOR EN INVERSA
    for(i=longitud-1;i>=0;i--){
        //SI EL CARACTER ENCONTRADO ES 1, ENTONCES ELEVO 2 A LA POTENCIA DE (LONGITUD-1)-i
        //QUE ME DEVUELVE NUMEROS CONSECUTIVOS DESDE EL 0
        if(numero[i]=='1'){
            nDec+=pow(2,(longitud-1)-i);
        }
    }

    //IMPRIMO EL RESULTADO
    printf("En decimal es %d\n",nDec);
}

int decOctal(int numero){
    int   resto = 0;
    int   resultado = 0;
    char  octal[50];
    char  longitud;
    char  temporal;
    char  tempS[10];
    int i,j;
    resultado = numero;

    //BLANQUEO LA CADENA QUE VA A DEVOLVER EL RESULTADO
    strcpy(octal,"");
    do{
        //OBTENGO EL RESTO
        resto = resultado%8;

        //REALIZO LA DIVISIÓN
        resultado = resultado / 8;

        //BLANQUEO LA CADENA TEMPORAL
        strcpy(tempS,"");

        //CONVIERTO EL RESTO EN UNA CADENA PARA PODER CONCATENARLO
        itoa(resto, tempS, 10);
        strcat(octal,tempS);

        //REPITO EL PROCESO MIENTRAS EL RESULTADO SEA MAYOR A 8
    }while(resultado>8);

    //LIMPIO LA CADENA TEMPORAL, CONVIERTO EL ULTIMO RESULTADO A CADENA PARA CONCATENARLO
    strcpy(tempS,"");
    itoa(resultado, tempS, 10);
    strcat(octal,tempS);

    //INVIERTO EL OCTAL PARA DEVOLVERLO CORRECTAMENTE
    //OBTENGO EL LARGO DE EL NUMERO OCTAL
    longitud=strlen(octal);

    //RECORRO EL NUMERO OCTAL HASTA LA LONGITUD, Y A LA VEZ LO RECORRO DE ATRAS
    //HACIA ADELANTE, INTERCAMBIANDO LOS VALORES, ULTIMO POR PRIMERO Y VICEVERSA
    //Y ASI CON LOS SIGUIENTES
    for (i=0,j=longitud-1; i<longitud/2; i++,j--){
        temporal=octal[i];
        octal[i]=octal[j];
        octal[j]=temporal;
    }

    printf("El numero %d en octal es %s\n",numero,octal);
}

int decHexa(int numero){
    int resultado;
    float resDecimal;
    char  hexa[50];
    int temp=0;
    char tempS[10];
    char  longitud;
    char  temporal;
    int i,j;

    resultado = numero;
    strcpy(hexa,"");
    strcpy(tempS,"");
    do{
        resDecimal = (resultado+0.0) / 16;
        resultado = resultado / 16;
        resDecimal = resDecimal-resultado;
        temp = resDecimal*16;

        strcpy(tempS,"");
        if(temp<10){
            itoa(temp, tempS, 10);
            strcat(hexa,tempS);
        }else if(temp==10){
            strcat(hexa,"A");
        }else if(temp==11){
            strcat(hexa,"B");
        }else if(temp==12){
            strcat(hexa,"C");
        }else if(temp==13){
            strcat(hexa,"D");
        }else if(temp==14){
            strcat(hexa,"E");
        }else if(temp==15){
            strcat(hexa,"F");
        }

        //printf("Resultado %d , Resultado Decimal %.3f, Temporal %d, Temp String %s\n",resultado,resDecimal,temp,tempS);

    }while(resultado>16);

    strcpy(tempS,"");
    if(resultado<10){
        itoa(resultado, tempS, 10);
        strcat(hexa,tempS);
    }else if(resultado==10){
        strcat(hexa,"A");
    }else if(resultado==11){
        strcat(hexa,"B");
    }else if(resultado==12){
        strcat(hexa,"C");
    }else if(resultado==13){
        strcat(hexa,"D");
    }else if(resultado==14){
        strcat(hexa,"E");
    }else if(resultado==15){
        strcat(hexa,"F");
    }
    longitud=strlen(hexa);

    for (i=0,j=longitud-1; i<longitud/2; i++,j--){
        temporal=hexa[i];
        hexa[i]=hexa[j];
        hexa[j]=temporal;
    }

    printf("El numero %d en hexadecimal es %s\n",numero,hexa);
}

int decBinario(int numero){
    int   resto = 0;
    int   resultado = 0;
    char  binario[50];
    char  longitud;
    char  temporal;
    int i,j;
    resultado = numero;

    //BLANQUEO LA CADENA QUE VA A DEVOLVER EL RESULTADO
    strcpy(binario,"");
    do{
        //OBTENGO EL RESTO
        resto = resultado%2;

        //REALIZO LA DIVISIÓN
        resultado = resultado / 2;
        //printf("Resto %d , Resultado %d\n",resto,resultado);

        //EVALUO EL RESTO PARA DETERMINAR SI ES 1 O 0 Y LUEGO CONCATENARLO A LA VARIABLE A IMPRIMIR
        if(resto==1){
            strcat(binario,"1");
        }else{
            strcat(binario,"0");
        }
        //REPITO EL PROCESO MIENTRAS EL RESULTADO SEA MAYOR A 1
    }while(resultado>1);

    //EVALUO EL RESULTADO PARA DETERMINAR SI ES 1 O 0 Y LUEGO CONCATENARLO A LA VARIABLE A IMPRIMIR
    if(resultado==1){
        strcat(binario,"1");
    }else{
        strcat(binario,"0");
    }

    //INVIERTO EL BINARIO PARA DEVOLVERLO CORRECTAMENTE
    //OBTENGO EL LARGO DE EL NUMERO BINARIO
    longitud=strlen(binario);

    //RECORRO EL NUMERO BINARIO HASTA LA LONGITUD, Y A LA VEZ LO RECORRO DE ATRAS
    //HACIA ADELANTE, INTERCAMBIANDO LOS VALORES, ULTIMO POR PRIMERO Y VICEVERSA
    //Y ASI CON LOS SIGUIENTES
    for (i=0,j=longitud-1; i<longitud/2; i++,j--){
        temporal=binario[i];
        binario[i]=binario[j];
        binario[j]=temporal;
    }

    printf("El numero %d en binario es %s\n",numero,binario);

}
