#include <stdio.h>
int main(){
    int number = 44;
    int guess;
    printf("Guess a number between 1 and 100\n");
do {
    printf("Enter your guess: ");
        scanf("%d",&guess);
if (guess > number) {
    printf("Too high\n");
}
if (guess < number) {
    printf("Too low\n");
}
}   while (guess != number);
    printf("You win. The answer is %d",number);
return 0;
}
