//
//  main.c
//  Traccia 3 - Prova all'impronta Programmazione I
//
//  Created by Roberto Vecchio on 10/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef struct point{
    double x;
    double y;
}point_struct;

point_struct points[] = {
    {2,3},
    {3,4},
    {1,3},
    {1,8},
    {5,6},
    {9,6}
};

double calculateDistance(point_struct,point_struct);
double maximumDistance(point_struct *, int);

int main(int argc, const char * argv[]) {
    int array_size = sizeof(points) / sizeof(points[0]);
    double max_distance = maximumDistance(points, array_size);
    printf("max distance = %f\n", max_distance);
    return 0;
}





double calculateDistance(point_struct point_one, point_struct point_two){
    return sqrt(pow(point_two.x - point_one.x, 2) + pow(point_two.y - point_one.y, 2));
}

double maximumDistance(point_struct *points, int array_size){
    int i,j;
    double distance, maximum_distance;
    
    maximum_distance = calculateDistance(points[0], points[1]);
    
    for (i = 0; i < array_size - 1; i++) {
        for (j = i + 1; j< array_size; j++) {
            
            distance = calculateDistance(points[i], points[j]);
            
            if (distance > maximum_distance) {
                maximum_distance = distance;
                
            }
        }
    }
    return maximum_distance;
}
