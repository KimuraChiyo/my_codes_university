#include <stdio.h>
#include "fcgi_stdio.h"

int main() {

    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\n\n");
        printf("Hello World!\r\n");
    }

    return 0;
}
