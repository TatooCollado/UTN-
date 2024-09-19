Algoritmo Ej8Uni4
	
	//Realizar un programa que permita almacenar números reales en una matriz de orden 4×3, cuatro filas y tres columnas. Además,
	//calcular e imprimir la suma de cada uno de los números ingresados.

	Definir arreglo, suma Como real
	Dimension arreglo[4,3]
	
	
	
	para i<- 1 hasta 4 con paso 1 Hacer
		
		para j <- 1 hasta 3 con paso 1 Hacer
			
			Escribir "Ingrese un valor real"
			
			leer arreglo[i,j]
			
			suma = suma + arreglo[i,j]
			
			
		FinPara
		
	FinPara
	
	
	para i<- 1 hasta 4 con paso 1 Hacer
		
		para j <- 1 hasta 3 con paso 1 Hacer
			
			Escribir sin saltar arreglo[i,j] " " 
			
			
		FinPara
		
		Escribir ""
		
	FinPara
	
	Escribir "La suma de los valores es de " suma
	
FinAlgoritmo
