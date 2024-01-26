#include <stdio.h>
#include <cs50.h>

int main(void)
{
    for(int i = 0;i <= 100; i++){
        if(i%3 == 0 && i%5 == 0){
            printf("%i FizzBuzz\n", i);
        }else if(i%3 == 0){
            printf("%i Fizz\n", i);
        }else if(i%5 == 0){
            printf("%i Buzz\n", i);
        }else{
            printf("%i\n", i);
        }
    }
}