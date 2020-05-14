#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *plib;
    typedef void (*FUN_HELLO)();
    FUN_HELLO funHello = NULL;
    printf("Before loading dynamic library\n");
   
    system("echo -e '======== Before loading dynamic library ========' > ./dynamicload.txt");
    system("cat /proc/$(pidof ./main)/maps >> ./before_loading.txt");
    printf("* Result have been saved to before_loading.txt\n\n");

    // printf("Please enter to continue:");
    // getchar();

    plib = dlopen("./libtest.so", RTLD_NOW | RTLD_GLOBAL);
    if (plib == NULL) {
        fprintf(stderr, "error\n");
        exit(EXIT_FAILURE);
    }
    

    funHello = dlsym(plib, "printHello");
    funHello();
    
    system("echo -e '\n======== After loading dynamic library ========' > ./dynamicload.txt");
    system("cat /proc/$(pidof ./main)/maps >> ./after_load.txt");
    printf("* Result have been saved to after_load.txt\n\n");
    
    dlclose(plib);
    printf("After release dynamic library\n");
    
    system("echo -e '\n======== After relaease dynamic library ========' > ./dynamicload.txt");
    system("cat /proc/$(pidof ./main)/maps >>./after_release.txt");
    printf("* Result have been saved to after_release.txt\n");

    // printf("Please enter to continue:");
    // getchar();
    return 0;
}
