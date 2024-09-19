Algoritmo Ej3Uni4
	
	//Desarrollar un algoritmo que permita ingresar 5 datos numéricos en un arreglo y que luego los sume a todos y muestre el resultado
	//en pantalla.
	
	Definir arreglo, suma Como Entero
	
	Dimension arreglo[5]
	
	para i<- 1 hasta 5 con paso 1 Hacer
		
		Escribir "Ingrresar un numero"
		Leer arreglo[i]
		
	FinPara
	
	para i<- 1 hasta 5 con paso 1 Hacer
		
		suma = suma + arreglo[i]
		
	FinPara
	
	Escribir "La suma de todos los valores ingresados es de: "  suma;
	
FinAlgoritmo
