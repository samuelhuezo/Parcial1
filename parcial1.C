#include <stdio.h>

typedef struct {
    int codigo;
    float nota;
} Estudiante;

// Datos predefinidos
#define N 5
Estudiante estudiantes[N] = {
    {100736289, 4.5},
    {2024102, 3.2},
    {2024103, 5.0},
    {2024104, 2.8},
    {2024105, 4.0}
};

// Función recursiva para encontrar la nota máxima
float notaMaximaRec(Estudiante arr[], int n) {
    if (n == 1) return arr[0].nota;
    float max_rest = notaMaximaRec(arr + 1, n - 1);
    return (arr[0].nota > max_rest) ? arr[0].nota : max_rest;
}

// Función recursiva para calcular la suma de notas
float sumaNotasRec(Estudiante arr[], int n) {
    if (n == 0) return 0.0f;
    return arr[0].nota + sumaNotasRec(arr + 1, n - 1);
}

// Función recursiva para encontrar el índice del mínimo código desde start hasta end
int indiceMinCodigoRec(Estudiante arr[], int start, int end) {
    if (start == end) return start;
    int min_rest = indiceMinCodigoRec(arr, start + 1, end);
    return (arr[start].codigo < arr[min_rest].codigo) ? start : min_rest;
}

// Función recursiva para ordenar con Selection Sort por código
void selectionSortRec(Estudiante arr[], int start, int n) {
    if (start >= n - 1) return;
    int min_idx = indiceMinCodigoRec(arr, start, n - 1);
    if (min_idx != start) {
        Estudiante temp = arr[start];
        arr[start] = arr[min_idx];
        arr[min_idx] = temp;
    }
    selectionSortRec(arr, start + 1, n);
}

// Función para mostrar la lista de estudiantes
void mostrarEstudiantes(Estudiante arr[], int n) {
    printf("Codigo\tNota\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.2f\n", arr[i].codigo, arr[i].nota);
    }
}

int main() {
    int opcion;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Buscar la Nota Maxima del Curso (Recursivo)\n");
        printf("2. Calcular el Promedio del Curso (Recursivo)\n");
        printf("3. Ordenar Codigos de Estudiantes (Selection Sort Recursivo)\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                float maxNota = notaMaximaRec(estudiantes, N);
                printf("La nota maxima del curso es: %.2f\n", maxNota);
                break;
            }
            case 2: {
                float suma = sumaNotasRec(estudiantes, N);
                float promedio = suma / N;
                printf("El promedio del curso es: %.2f\n", promedio);
                break;
            }
            case 3: {
                selectionSortRec(estudiantes, 0, N);
                printf("Lista ordenada por codigo:\n");
                mostrarEstudiantes(estudiantes, N);
                break;
            }
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
