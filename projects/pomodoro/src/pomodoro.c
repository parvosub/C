#include <stdio.h>
#include <unistd.h> //sleep function

int main() {
  
    int seconds;

    printf("Enter the number or seconds for the countdown: ");
    scanf("%d", &seconds);
    
    while (seconds > 0) {
      printf("time remaining: %d seconds\n", seconds);
      sleep(1);
      seconds--;

  }

     printf("countdown finished!\n");


     return 0;
}
