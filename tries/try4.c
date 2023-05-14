#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h> /* For O_* constants */ 
#include <unistd.h>

int main(){
       int SIZE = 255;
       char buffer[255] = {0};
       freopen("/dev/null", "a", stdout);
       setbuf(stdout, buffer);
       printf("This will be stored in the buffer");
       freopen ("/dev/tty", "a", stdout);
       FILE* f = fopen("test.txt", "w");
       fputs(buffer, f);
       fclose(f);
}
