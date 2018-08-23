#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//ALUMNO : CRISTIAN TORRES
void decBinario(char[],char *);
void decHexa(int);
void binDecimal(char[],char *);
void binHexa(char[],char *);
void digitoHexa(int,char *);
void digitoBinario(char,char *);
void hexaBinario(char[],char *);
void borrarPantalla();

int main(){
    int   fEntrada =0;
    char  nValor[50];
    char res[50];
    char res2[50];
    int ret=0;
    char respuesta[1];

    do{
        borrarPantalla();
        printf("Seleccione el formato de entrada : \n[1]-DECIMAL\n[2]-BINARIO\n[3]-HEXADECIMAL\n");
        scanf("%d",&fEntrada);
        borrarPantalla();

        switch(fEntrada){
            case 1: //DECIMAL
                printf("Ingrese el numero decimal : \n");
                scanf("%s",nValor);

                decBinario(nValor,res);
                printf("El numero %s en Binario es %s \n",nValor,res);
                binHexa(res,res2);
                printf("El numero %s en Hexadecimal es %s \n",nValor,res2);
                break;
            case 2: //BINARIO
                printf("Ingrese el numero binario : \n");
                scanf("%s",nValor);

                binDecimal(nValor,res2);
                printf("El numero %s en Decimal es %s \n",nValor,res2);
                binHexa(nValor,res2);
                printf("El numero %s en Hexadecimal es %s \n",nValor,res2);
                break;
            case 3: //HEXADECIMAL
                printf("Ingrese el numero hexadecimal : \n");
                scanf("%s",nValor);

                hexaBinario(nValor,res);
                printf("El numero %s en Binario es %s \n",nValor,res);
                binDecimal(res,res2);
                printf("El numero %s en Decimal es %s \n",nValor,res2);
        }

        printf("\nSi desea realizar otra conversion, ingrese s, de lo contrario ingrese n.\n");
        scanf("%s",respuesta);

        ret = strncmp("s",respuesta,1);
    }while(ret==0);
}

void hexaBinario(char numero[],char *pRes){
    int i=0;
    char longitud;
    int paso=0;
    //BLANQUEO LA VARIABLE
    strcpy(pRes,"");
    //OBTENGO LA LONGITUD DEL NÚMERO
    longitud=strlen(numero);
    //RECORRO EL NÚMERO Y LLAMO A LA FUNCION QUE DEVUELVE EL VALOR BINARIO DE CADA DIGITO
    for(i=0;i<=longitud-1;i++){
        if(numero[i]=='0'){
            if(paso==1){
                digitoBinario(numero[i],pRes);
            }
        }else{
            //CUANDO TOMO EL PRIMER VALOR DISTINTO DE 0, INICIALIZO LA VARIABLE PASO PARA QUE
            //NO ME AGREGUE LOS 0 A LA IZQUIERDA INNECESARIOS
            paso=1;
            digitoBinario(numero[i],pRes);
        }
    }
}

void binHexa(char numero[],char *pRes){
    int i=0, j=0;
    char longitud;
    int nDec=0;
    int resto=0;
    char nHexa[30];
    //BLANQUEO LA VARIABLE
    strcpy(nHexa,"");
    //OBTENGO EL TAMAÑO DEL VECTOR
    longitud=strlen(numero);

    //OBTENGO EL RESTO DE LA LONGITUD/4 PARA SABER SI TENGO QUE AGREGAR 0 PARA COMPLETAR
    //Y PODER AGRUPAR DE A 4 SIN PROBLEMAS
    resto = longitud%4;
    if(resto>0){
        //DECLARO UNA VARIABLE TEMPORAL DEL TAMAÑO DEL RESTO
        char tmp[resto];
        //BLANQUEO LA VARIABLE
        strcpy(tmp,"");
        //J TOMA EL VALOR DE LOS 0 QUE TENGO QUE AGREGAR A LA IZQUIERDA
        j=4-resto;
        //RECORRO LA CANTIDAD DE 0 Y LOS AGREGO EN LA VARIABLE TEMPORAL
        for(i=0;i<j;i++){
            strcat(tmp,"0");
        }
        //CONCATENO EN LA VARIABLE TMP EL NUMERO ORIGINAL MÁS LOS 0
        strcat(tmp,numero);
        //OBTENGO LA NUEVA LONGITUD
        longitud=strlen(tmp);
        //COPIO EL NÚMERO EN LA VARIABLE ORIGINAL
        strcpy(numero,tmp);
    }

    //RECORRO LA VARIABLE DE 4 EN 4
    for(i=0;i<=longitud-1;i+=4){
        //TOMO EL PRIMERO DE LOS 4 DIGITOS, SI ES 1 SUMO EN UNA VARIABLE LA POTENCIA DE 2 EN LA POSICIÓN DEL NÚMERO
        //Y HAGO LO MISMO CON LOS SIGUIENTES
        if(numero[i]=='1'){ nDec+=pow(2,3); }
        if(numero[i+1]=='1'){ nDec+=pow(2,2); }
        if(numero[i+2]=='1'){ nDec+=pow(2,1); }
        if(numero[i+3]=='1'){ nDec+=pow(2,0); }

        //ENVIO A ESTA FUNCIÓN EL NÚMERO OBTENIDO DE LA SUMA Y EL VECTOR DONDE GUARDO EL RESULTADO
        //Y DEVUELVE EL VALOR HEXADECIMAL DEL MISMO
        digitoHexa(nDec,nHexa);
        //REINICIO EL ENTERO PARA PODER USARLO EN LOS PROXIMOS 4 DIGITOS
        nDec=0;
    }
    //IMPRIMO EL RESULTADO
    strcpy(pRes,nHexa);
}

void digitoHexa(int num,char *nHexa){

    switch(num){
        case 0: strcat(nHexa,"0");break;
        case 1: strcat(nHexa,"1");break;
        case 2: strcat(nHexa,"2");break;
        case 3: strcat(nHexa,"3");break;
        case 4: strcat(nHexa,"4");break;
        case 5: strcat(nHexa,"5");break;
        case 6: strcat(nHexa,"6");break;
        case 7: strcat(nHexa,"7");break;
        case 8: strcat(nHexa,"8");break;
        case 9: strcat(nHexa,"9");break;
        case 10: strcat(nHexa,"A");break;
        case 11: strcat(nHexa,"B");break;
        case 12: strcat(nHexa,"C");break;
        case 13: strcat(nHexa,"D");break;
        case 14: strcat(nHexa,"E");break;
        case 15: strcat(nHexa,"F");break;
    }

}

void digitoBinario(char digito,char *pRes){
    switch(digito){
        case '0': strcat(pRes,"0000"); break;
        case '1': strcat(pRes,"0001"); break;
        case '2': strcat(pRes,"0010"); break;
        case '3': strcat(pRes,"0011"); break;
        case '4': strcat(pRes,"0100"); break;
        case '5': strcat(pRes,"0101"); break;
        case '6': strcat(pRes,"0110"); break;
        case '7': strcat(pRes,"0111"); break;
        case '8': strcat(pRes,"1000"); break;
        case '9': strcat(pRes,"1001"); break;
        case 'a':
        case 'A': strcat(pRes,"1010"); break;
        case 'b':
        case 'B': strcat(pRes,"1011"); break;
        case 'c':
        case 'C': strcat(pRes,"1100"); break;
        case 'd':
        case 'D': strcat(pRes,"1101"); break;
        case 'e':
        case 'E': strcat(pRes,"1110"); break;
        case 'f':
        case 'F': strcat(pRes,"1111"); break;
    }
}

void binDecimal(char numero[],char *pRes){
    int i=0;
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
    //DECLARO UNA VARIABLE TEMPORAL
    char str[50];
    //CONVIERTO EL ENTERO EN TEXTO, PARA PODER DEVOLVERLO EN EL PUNTERO
    //QUE ES TIPO CHAR
    sprintf(str, "%d", nDec);
    strcpy(pRes,str);
}

void decBinario(char numero[],char *pRes){
    char longitud;
    char cadena[50];
    int i=0, num=0, paso=0, potencia=0;

    //BLANQUEO LA VARIABLE
    strcpy(cadena,"");
    //OBTENGO LOS DIGITOS DEL NUMERO A CONVERTIR, PARA EVITAR RECORRER TANTAS OPCIONES SI NO SON NECESARIAS
    //POR EJ. SI SE INGRESA UN NUMERO DE 2 DIGITOS,SE QUE NO VA A SER MAYOR A 2^7=128
    //ENTONCES LE ASIGNO A I EL VALOR MAXIMO DESDE EL CUAL COMIENZA A RECORRER
    longitud = strlen(numero);
    switch(longitud){
        case 1:i=4; break;
        case 2:i=7; break;
        case 3:i=10; break;
        case 4:i=14; break;
        case 5:i=17;break;
        default:i=40; break;
    }

    //CONVIERTO LA CADENA A ENTERO PARA PODER APLICARLE OPERACIONES
    num = atoi(numero);
    //RECORRO LAS POTENCIAS DE 2, ARRANCANDO DESDE EL LIMITE QUE ESTABLECI CON I
    //OBTENGO EL VALOR DE LA POTENCIA EN ESA POSICION, LA COMPARO CON EL NUMERO Y SI ES MENOR, ENTONCES PONGO UN 1
    //EN LA VARIABLE CADENA, E INICIALIZO PASO, PARA SABER QUE PUEDO COMENZAR A PONER 0 EN CASO DE NO CUMPLIR LA CONDICION
    //Y ASI EVITAR LOS 0 A LA IZQUIERDA. LUEGO RESTO AL NUMERO EL VALOR DE LA POTENCIA, Y REPITO EL PROCESO.
    for(i=i;i>=0;i--){
        potencia=pow(2,i);
        if(potencia>num){
            if(paso==1){
                strcat(cadena,"0");
            }
        }else{
            paso=1;
            num-=potencia;
            strcat(cadena,"1");
        }
    }
    //COPIO EN UNA VARIABLE EL RESULTADO PARA PODER USARLO DESDE OTRA FUNCION
    strcpy(pRes,cadena);
}

void borrarPantalla(){
	system("cls");
}
