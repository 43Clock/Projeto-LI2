#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    float a, b, c;
    double area, s;
    printf("Intruduzir as dimenções do triangulo:\n");
    scanf("%f %f %f",&a, &b, &c);
    s = (a+b+c)/2;
    area = sqrt(s * (s - a)* (s - b) * (s - c));
    if (a<(b+c) && a>fabs (b-c)) {if (a==b && b == c) printf("Triângulo Equilátero de área:%f\n",area);
                                  else {if (a==b || a == c || b == c) printf("Triângulo Isósceles de área: %f\n",area);
                                        else printf("Triângulo Escaleno de área: %f\n",area);
                                  }
    }
    else {printf ("Dimensões Inválidas\n");
        return 0;}
}