#include <stdio.h>
#include <stdlib.h>

// Definindo o tipo de dado para representar os pontos (x, y)
typedef struct {
    float x;
    float y;
} Point;

// Função para calcular a média de uma lista de números
float mean(float *array, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Função para calcular o coeficiente angular (slope) da regressão linear
float slope(Point *points, int size) {
    float sumXY = 0.0;
    float sumX = 0.0;
    float sumY = 0.0;
    float sumX2 = 0.0;

    for (int i = 0; i < size; i++) {
        sumXY += points[i].x * points[i].y;
        sumX += points[i].x;
        sumY += points[i].y;
        sumX2 += points[i].x * points[i].x;
    }

    float n = (float)size;
    return (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
}

// Função para calcular o coeficiente linear (intercept) da regressão linear
float intercept(Point *points, int size, float slopeVal) {
    float meanX = mean(&points->x, size);
    float meanY = mean(&points->y, size);
    return meanY - slopeVal * meanX;
}

// Função principal para realizar a regressão linear e imprimir a equação da reta
void linearRegression(Point *points, int size) {
    float m = slope(points, size);
    float b = intercept(points, size, m);

    printf("Equação da reta: y = %.2fx + %.2f\n", m, b);
}

int main() {
    Point data[] = { {1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}, {5.0, 6.0} };
    int dataSize = sizeof(data) / sizeof(data[0]);

    linearRegression(data, dataSize);

    return 0;
}