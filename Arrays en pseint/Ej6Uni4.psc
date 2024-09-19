Algoritmo Ej6Uni4
	
	//Realice un algoritmo que lea N elementos y que imprima el número que se repite más veces dentro del arreglo.
	
	Definir n, arreglo, contador, auxiliar, valorI como entero
	
	auxiliar = 0
	
	Escribir "Cuantos elementos vas a ingresar:"
	leer n
	Dimension arreglo[n]
	
	para i<- 1 hasta n con paso 1 Hacer
		
		Escribir "Ingrese un valor: "
		leer arreglo[i]
		
	FinPara
	

	
	
	Para i<- 1 hasta n Con Paso 1 Hacer
	
		
		Para j <- 1 hasta n con paso 1 Hacer
			
			
			
			si arreglo[i] == arreglo[j]
				
			
				
				contador = contador + 1
				
			FinSi
			
			
		FinPara
		
		
		
		si auxiliar < contador Entonces
			
			auxiliar = contador
			valorI = i
			
		FinSi
		contador = 0
		
		
		
	FinPara
	
	
	
	Escribir "El numero que mas se repite es " arreglo[valorI]
	
	
	
FinAlgoritmo
