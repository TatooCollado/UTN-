#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100 // Número máximo de artículos
// Prototipos de funciones
int validarCodigo(char codigo[]);
void cargarArticulos(char codigos[][9], char descripciones[][100], float precios[], int cantidades_existentes[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int *n);
void mostrarListaPorDescripcion(char codigos[][9], char descripciones[][100], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n);
void mostrarListaPorCantidadVendida(char codigos[][9], char descripciones[][100], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n);
void mostrarStockActual(char codigos[][9], char descripciones[][100], int cantidades_existentes[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n);
void buscarArticuloPorCodigo(char codigos[][9], char descripciones[][100], float precios[], int cantidades_existentes[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n);
void mostrarEstadisticas(char codigos[][9], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n);
void ordenarPorDescripcion(char codigos[][9], char descripciones[][100], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n);
void ordenarPorCantidadVendida(char codigos[][9], char descripciones[][100], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n);
int busquedaBinaria(char codigos[][9], int n, char codigo[]);
void mostrarMenu();

// Función para validar el código del artículo
int validarCodigo(char codigo[])
{
    char rubro[4];
    strncpy(rubro, codigo, 3); // Extrae los primeros 3 caracteres
    rubro[3] = '\0';           // Asegura que sea un string válido
    int rubro_num = atoi(rubro);

    if ((rubro_num == 100 || rubro_num == 300 || rubro_num == 450 ||
         rubro_num == 680 || rubro_num == 720) &&
        strlen(codigo) == 8)
    {
        return 1; // Código válido
    }
    return 0; // Código inválido
}

// Función para cargar artículos
void cargarArticulos(char codigos[][9], char descripciones[][100], float precios[], int cantidades_existentes[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int *n)
{
    printf("Ingrese la cantidad de articulos: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++)
    {
        printf("Articulo %d\n", i + 1);
        do
        {
            printf("Ingrese codigo (3 digitos de rubro y 5 digitos de articulo): ");
            scanf("%s", codigos[i]);
            if (!validarCodigo(codigos[i]))
            {
                printf("Codigo invalido. Intente de nuevo.\n");
            }
        } while (!validarCodigo(codigos[i]));

        printf("Ingrese descripcion: ");
        scanf(" %[^\n]", descripciones[i]);
        printf("Ingrese precio de venta: ");
        scanf("%f", &precios[i]);
        printf("Ingrese cantidad existente: ");
        scanf("%d", &cantidades_existentes[i]);
        printf("Ingrese cantidad vendida 1 quincena: ");
        scanf("%d", &cantidades_vendidas_1Q[i]);
        printf("Ingrese cantidad vendida 2 quincena: ");
        scanf("%d", &cantidades_vendidas_2Q[i]);
    }
}

// Función para ordenar la lista de artículos por descripción (Ordenamiento Burbuja)
void ordenarPorDescripcion(char codigos[][9], char descripciones[][100], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(descripciones[j], descripciones[j + 1]) > 0)
            {
                // Intercambiar descripciones
                char temp_desc[100];
                strcpy(temp_desc, descripciones[j]);
                strcpy(descripciones[j], descripciones[j + 1]);
                strcpy(descripciones[j + 1], temp_desc);

                // Intercambiar códigos
                char temp_codigo[9];
                strcpy(temp_codigo, codigos[j]);
                strcpy(codigos[j], codigos[j + 1]);
                strcpy(codigos[j + 1], temp_codigo);

                // Intercambiar precios
                float temp_precio = precios[j];
                precios[j] = precios[j + 1];
                precios[j + 1] = temp_precio;

                // Intercambiar cantidades vendidas
                int temp_vendida_1Q = cantidades_vendidas_1Q[j];
                cantidades_vendidas_1Q[j] = cantidades_vendidas_1Q[j + 1];
                cantidades_vendidas_1Q[j + 1] = temp_vendida_1Q;

                int temp_vendida_2Q = cantidades_vendidas_2Q[j];
                cantidades_vendidas_2Q[j] = cantidades_vendidas_2Q[j + 1];
                cantidades_vendidas_2Q[j + 1] = temp_vendida_2Q;
            }
        }
    }
}

// Función para ordenar la lista de artículos por cantidad vendida (Ordenamiento Burbuja)
void ordenarPorCantidadVendida(char codigos[][9], char descripciones[][100], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int total_vendido_j = cantidades_vendidas_1Q[j] + cantidades_vendidas_2Q[j];
            int total_vendido_j1 = cantidades_vendidas_1Q[j + 1] + cantidades_vendidas_2Q[j + 1];
            if (total_vendido_j < total_vendido_j1)
            {
                // Intercambiar descripciones
                char temp_desc[100];
                strcpy(temp_desc, descripciones[j]);
                strcpy(descripciones[j], descripciones[j + 1]);
                strcpy(descripciones[j + 1], temp_desc);

                // Intercambiar códigos
                char temp_codigo[9];
                strcpy(temp_codigo, codigos[j]);
                strcpy(codigos[j], codigos[j + 1]);
                strcpy(codigos[j + 1], temp_codigo);

                // Intercambiar precios
                float temp_precio = precios[j];
                precios[j] = precios[j + 1];
                precios[j + 1] = temp_precio;

                // Intercambiar cantidades vendidas
                int temp_vendida_1Q = cantidades_vendidas_1Q[j];
                cantidades_vendidas_1Q[j] = cantidades_vendidas_1Q[j + 1];
                cantidades_vendidas_1Q[j + 1] = temp_vendida_1Q;

                int temp_vendida_2Q = cantidades_vendidas_2Q[j];
                cantidades_vendidas_2Q[j] = cantidades_vendidas_2Q[j + 1];
                cantidades_vendidas_2Q[j + 1] = temp_vendida_2Q;
            }
        }
    }
}

// Función para mostrar la lista de artículos ordenada por descripción
void mostrarListaPorDescripcion(char codigos[][9], char descripciones[][100], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n)
{
    ordenarPorDescripcion(codigos, descripciones, precios, cantidades_vendidas_1Q, cantidades_vendidas_2Q, n);

    printf("Lista de articulos ordenada por descripcion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Codigo: %s, Descripcion: %s, Precio: %.2f\n", codigos[i], descripciones[i], precios[i]);
    }
}

// Función para mostrar la lista de artículos ordenada por cantidad vendida
void mostrarListaPorCantidadVendida(char codigos[][9], char descripciones[][100], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n)
{
    ordenarPorCantidadVendida(codigos, descripciones, precios, cantidades_vendidas_1Q, cantidades_vendidas_2Q, n);

    float monto_total = 0;
    printf("Lista de articulos ordenada por cantidad vendida:\n");
    for (int i = 0; i < n; i++)
    {
        int cantidad_total_vendida = cantidades_vendidas_1Q[i] + cantidades_vendidas_2Q[i];
        float importe_total = cantidad_total_vendida * precios[i];
        monto_total += importe_total;
        printf("Codigo: %s, Descripcion: %s, Cantidad total vendida: %d, Importe total: %.2f\n",
               codigos[i], descripciones[i], cantidad_total_vendida, importe_total);
    }
    printf("Monto total de ventas realizadas en el mes: %.2f\n", monto_total);
}

// Función para mostrar el stock actual de los artículos
void mostrarStockActual(char codigos[][9], char descripciones[][100], int cantidades_existentes[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n)
{
    printf("Stock actual de articulos:\n");
    for (int i = 0; i < n; i++)
    {
        int stock_actual = cantidades_existentes[i] - (cantidades_vendidas_1Q[i] + cantidades_vendidas_2Q[i]);
        printf("Codigo: %s, Descripcion: %s, Stock actual: %d\n", codigos[i], descripciones[i], stock_actual);
    }
}

// Función para buscar un artículo por código (Búsqueda Binaria)
int busquedaBinaria(char codigos[][9], int n, char codigo[])
{
    int inicio = 0, fin = n - 1;

    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;
        int comparacion = strcmp(codigos[medio], codigo);

        if (comparacion == 0)
        {
            return medio; // Encontrado
        }
        else if (comparacion < 0)
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }
    return -1; // No encontrado
}

// Función para buscar y mostrar un artículo por su código
void buscarArticuloPorCodigo(char codigos[][9], char descripciones[][100], float precios[], int cantidades_existentes[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n)
{
    char codigo[9];
    printf("Ingrese el codigo del articulo a buscar: ");
    scanf("%s", codigo);

    ordenarPorDescripcion(codigos, descripciones, precios, cantidades_vendidas_1Q, cantidades_vendidas_2Q, n); // Aseguramos que esté ordenado para la búsqueda binaria

    int indice = busquedaBinaria(codigos, n, codigo);
    if (indice != -1)
    {
        printf("Articulo encontrado:\n");
        printf("Codigo: %s, Descripcion: %s, Precio: %.2f, Cantidad existente: %d, Cantidad vendida 1 quincena: %d, Cantidad vendida 2 quincena: %d\n",
               codigos[indice], descripciones[indice], precios[indice], cantidades_existentes[indice],
               cantidades_vendidas_1Q[indice], cantidades_vendidas_2Q[indice]);
    }
    else
    {
        printf("Articulo no encontrado.\n");
    }
}

void mostrarEstadisticas(char codigos[][9], float precios[], int cantidades_vendidas_1Q[], int cantidades_vendidas_2Q[], int n)
{
    int total_vendido_rubro[5] = {0}; // Para los rubros 100, 300, 450, 680, 720
    int total_vendido_1Q[5] = {0}, total_vendido_2Q[5] = {0};
    float total_ventas_rubro_1Q[5] = {0}, total_ventas_rubro_2Q[5] = {0};
    int total_vendido_mes = 0;
    int rubros[] = {100, 300, 450, 680, 720}; // Códigos de rubro
    char rubro_con_mayor_1Q[9], rubro_con_mayor_2Q[9];
    float mayor_importe_1Q = 0, mayor_importe_2Q = 0;

    // Calcular cantidades vendidas por rubro y totales
    for (int i = 0; i < n; i++)
    {
        int rubro;
        sscanf(codigos[i], "%3d", &rubro); // Obtener los primeros 3 dígitos del código

        for (int j = 0; j < 5; j++)
        {
            if (rubro == rubros[j])
            {
                total_vendido_rubro[j] += cantidades_vendidas_1Q[i] + cantidades_vendidas_2Q[i];
                total_vendido_1Q[j] += cantidades_vendidas_1Q[i];
                total_vendido_2Q[j] += cantidades_vendidas_2Q[i];
                total_ventas_rubro_1Q[j] += cantidades_vendidas_1Q[i] * precios[i];
                total_ventas_rubro_2Q[j] += cantidades_vendidas_2Q[i] * precios[i];
                total_vendido_mes += cantidades_vendidas_1Q[i] + cantidades_vendidas_2Q[i];
            }
        }
    }

    // Mostrar porcentaje de artículos vendidos por rubro
    printf("\nPorcentaje de articulos vendidos por rubro:\n");
    for (int i = 0; i < 5; i++)
    {
        if (total_vendido_mes > 0)
        {
            float porcentaje = (total_vendido_rubro[i] / (float)total_vendido_mes) * 100;
            printf("Rubro %d: %.2f%%\n", rubros[i], porcentaje);
        }
    }

    // Mostrar porcentaje de ventas por quincena
    printf("\nPorcentaje de ventas por quincena para cada rubro:\n");
    for (int i = 0; i < 5; i++)
    {
        int total_vendido_rubro_mes = total_vendido_1Q[i] + total_vendido_2Q[i];
        if (total_vendido_rubro_mes > 0)
        {
            float porcentaje_1Q = (total_vendido_1Q[i] / (float)total_vendido_rubro_mes) * 100;
            float porcentaje_2Q = (total_vendido_2Q[i] / (float)total_vendido_rubro_mes) * 100;
            printf("Rubro %d: %.2f%% (1 quincena), %.2f%% (2 quincena)\n", rubros[i], porcentaje_1Q, porcentaje_2Q);
        }
    }

    // Encontrar el rubro con mayor importe de ventas por quincena
    for (int i = 0; i < 5; i++)
    {
        if (total_ventas_rubro_1Q[i] > mayor_importe_1Q)
        {
            mayor_importe_1Q = total_ventas_rubro_1Q[i];
            sprintf(rubro_con_mayor_1Q, "%d", rubros[i]);
        }
        if (total_ventas_rubro_2Q[i] > mayor_importe_2Q)
        {
            mayor_importe_2Q = total_ventas_rubro_2Q[i];
            sprintf(rubro_con_mayor_2Q, "%d", rubros[i]);
        }
    }

    // Mostrar rubro con mayor importe total de ventas
    printf("\nRubro con mayor importe total de ventas:\n");
    printf("1 quincena: Rubro %s con un importe de %.2f\n", rubro_con_mayor_1Q, mayor_importe_1Q);
    printf("2 quincena: Rubro %s con un importe de %.2f\n", rubro_con_mayor_2Q, mayor_importe_2Q);
}

// Función para mostrar el menú
void mostrarMenu()
{
    printf("\nMenu de opciones:\n");
    printf("1. Cargar articulos\n");
    printf("2. Mostrar lista de articulos por descripcion\n");
    printf("3. Mostrar lista de articulos por cantidad vendida\n");
    printf("4. Mostrar stock actual de articulos\n");
    printf("5. Buscar articulo por codigo\n");
    printf("6. Mostrar estadisticas de ventas\n");
    printf("7. Salir\n");
}

int main()
{
    char codigos[N][9], descripciones[N][100];
    float precios[N];
    int cantidades_existentes[N], cantidades_vendidas_1Q[N], cantidades_vendidas_2Q[N];
    int n = 0, opcion;

    do
    {
        mostrarMenu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            cargarArticulos(codigos, descripciones, precios, cantidades_existentes, cantidades_vendidas_1Q, cantidades_vendidas_2Q, &n);
            break;
        case 2:
            mostrarListaPorDescripcion(codigos, descripciones, precios, cantidades_vendidas_1Q, cantidades_vendidas_2Q, n);
            break;
        case 3:
            mostrarListaPorCantidadVendida(codigos, descripciones, precios, cantidades_vendidas_1Q, cantidades_vendidas_2Q, n);
            break;
        case 4:
            mostrarStockActual(codigos, descripciones, cantidades_existentes, cantidades_vendidas_1Q, cantidades_vendidas_2Q, n);
            break;
        case 5:
            buscarArticuloPorCodigo(codigos, descripciones, precios, cantidades_existentes, cantidades_vendidas_1Q, cantidades_vendidas_2Q, n);
            break;
        case 6:
            mostrarEstadisticas(codigos, precios, cantidades_vendidas_1Q, cantidades_vendidas_2Q, n);
            break;

        case 7:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 7);

    return 0;
}
