#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <wiringPi.h>
#include <lcd.h>

static void waitForEnter (void){
  printf ("Press ENTER to continue: ") ;
  (void)fgetc (stdin) ;
}

void main(){
    wiringPiSetupGpio();
    int fd = lcdInit(2, 16, 4, 5,6, 4,17,27,22, 0,0,0,0);

    while (1){
        lcdPosition(fd, 0, 0);
        lcdPuts(fd, "Testing");
        lcdPosition(fd, 0, 1);
        lcdPuts(fd, "Blah");
        sleep(1);
        printf("*** %d ***\n", fd);
        // waitForEnter();
        lcdClear(fd);
    }
}
