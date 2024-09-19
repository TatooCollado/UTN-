Algoritmo Ej5Uni4
	
	//Realice un algoritmo que lea en un arreglo las marcas obtenidas por 10 corredores en una carrera e imprimir cuántos tienen una
	//marca mayor, cuántos tienen una marca menor que el promedio y el promedio.
	
	definir arreglo, mayores, menores Como Entero
	Definir  promedio Como Real
	Dimension arreglo[10]
	
	menores = 0
	mayores = 0
	promedio = 0
	
	para i<- 1 hasta 10 con paso 1 Hacer
		
		Escribir "Escribir la marca del corredor " i ":"
		leer arreglo[i]
		promedio = promedio + arreglo[i]
		
		
	FinPara
	
	promedio = promedio / 10
	
	
	para i<- 1 hasta 10 con paso 1 Hacer
		
		si arreglo[i] >= promedio Entonces
			mayores = mayores + 1
			
		SiNo
			
			menores = menores + 1
			
		FinSi
		
		
	FinPara
	
	Escribir "El promedio es de: " promedio
	
	Escribir "Los corredores debajo del promedio son: " menores " y los mayores del promedio son: " mayores
	
	
FinAlgoritmo
