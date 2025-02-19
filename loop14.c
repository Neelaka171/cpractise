#include<stdio.h>
int main(){
    int x;
    float y;

    printf("enter x:");
    scanf("%d",&x);
    printf("enter y:");
    scanf("%f",&y);
    float ans =1.0;

for(int i =1; i<=x; i++){
    ans*=y;
}
    printf("answer is : %f",ans);







return 0;
}
