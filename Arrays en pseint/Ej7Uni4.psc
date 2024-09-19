Algoritmo Ej7Uni4
	
	//Escribir un algoritmo que muestre un país y sus ciudades relacionadas. Los países y sus ciudades son:
	
	Definir arreglo Como Caracter
	
	Dimension arreglo[3,4]
	
	arreglo[1,1] = "Argentina"
	arreglo[2,1] = "Colombia"
	arreglo[3,1] =	"Brasil"
	arreglo[1,2] = "Buenos Aires"	
	arreglo[1,3] = "Rosario"
	arreglo[1,4] = "Cordoba"
	arreglo[2,2] = "Cali"
	arreglo[2,3] = "Bogota"
	arreglo[2,4] =	"Santa Marta"
	arreglo[3,2] = "Brasilia"
	arreglo[3,3] = "Rio de janeiro"
	arreglo[3,4] =	"San Pablo"
	
	
	para i <- 1 hasta 3 con paso 1 Hacer
		
		para j  <- 1 hasta 4 con paso 1 Hacer
			
			Escribir Sin Saltar arreglo[i,j] " | "
			
		FinPara
		
		escribir "\n"
		
	FinPara
	
	
	
	
	
FinAlgoritmo
