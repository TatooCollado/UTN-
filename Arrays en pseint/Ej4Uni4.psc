Algoritmo Ej4Uni4
	
	//Escribir un algoritmo que permita ingresar 10 valores numéricos en un arreglo y que como resultado devuelva el mayor de todos
	//los valores ingresados.
	
	Definir arreglo, mayor como entero
	Dimension arreglo[10]
	
	
	para i<- 1 hasta 10 con paso 1 Hacer
		
		Escribir "Ingrese un valor: "
		leer arreglo[i]
		
		si i == 1 Entonces
			
			mayor = arreglo[i]
			
		SiNo
			
			si arreglo[i] > mayor Entonces
				mayor = arreglo[i]
			FinSi
			
			
		FinSi
		
	FinPara
	
	
	Mostrar "El valor mas grande del arreglo es: " mayor
	
	
	
FinAlgoritmo
