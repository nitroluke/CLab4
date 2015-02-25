#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
#define LoopLimit 180

typedef enum functions{
    sine,
    cosine,
    tangent,
    quit
}menu_t;

void sineFunc();
void cosineFunc();
void tangentFunc();
int runMenu(int userInput);

int main(void){
    int userInput;
    do{
        //userInput = 99;
        printf("Please choose an option:    (0) Sine   (1) Cosine   (2) Tangent   (3)QUIT\n>>>");
        scanf("%d", &userInput);
        printf("userInput = %d\n", userInput);
    }while(runMenu(userInput));
    return 0;
}

void sineFunc(){
    int degrees = 0;
    double result;
    while(degrees <= LoopLimit){
        double radians = (PI*degrees)/180;
        result = sin(radians);
        printf("\tsin(%d) = %.4f\n",degrees,result);
        degrees += 15;
    }
}

void cosineFunc(){
    int degrees = 0;
    double result;
    while(degrees <= LoopLimit){
        double radians = (PI*degrees)/180;
        result = cos(radians);
        printf("\tcos(%d) = %.4f\n",degrees,result);
        degrees += 15;
    }
}

void tangentFunc(){
    int degrees = 0;
    double result;
    while(degrees <= LoopLimit){
        if(degrees == 90){
            printf("\ttan(%d) is UNDEFINED\n", degrees);
            degrees += 15;
        }else{
            double radians = (PI*degrees)/180;
            result = tan(radians);
            printf("\ttan(%d) = %.4f\n",degrees,result);
            degrees += 15;
        }
    }
}

int runMenu(int input){
    switch(input){
        case sine:
            sineFunc();
            return 1;
        case cosine:
            cosineFunc();
            return 1;
        case tangent:
            tangentFunc();
            return 1;
        case quit:
            printf("Thanks for nothing\n\n");
            return 0;
        default:
            printf("%d is Invalid.  Please try again\n\n", input);
            return 1;

    }
}
