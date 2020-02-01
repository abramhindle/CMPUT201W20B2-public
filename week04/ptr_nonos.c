#include <stdio.h>

#define SIZE 10

// This function tries to print out the int which is at address 0 in memory...
// Don't do this!
void dereference_null() {
    printf("\ndereference null\n");
    int *a_pointer = NULL;
    printf(" a_pointer = %p\n", (void *) a_pointer);
    printf("*a_pointer = %d\n", *a_pointer);
}

// This function tries to print out the int which is at some address we don't know in memory...
// Don't do this!
void dereference_uninit() {
    printf("\ndereference unitialized pointer\n");
    int *a_pointer;
    printf(" a_pointer = %p\n", (void *) a_pointer);
    printf("*a_pointer = %d\n", *a_pointer);
}

// This function returns a pointer to an "automatic" local variable...
// Don't do this!
int *return_pointer_to_local() {
    int local_int = 100;
    int *pointer = &local_int;
    // when we return we give up the memory we allocated for "local_int"!
    return pointer;
}

// This function just does some things...
int do_things() {
    int three = 3;
    int five = 5;
    int three_fives = three * five;
    printf("    Three fives is %d\n", three_fives);
    return three_fives;
}

int main() {
//     dereference_null();
    int * pointer = return_pointer_to_local();
    printf("*pointer = %d\n", *pointer);
    do_things();
    printf("*pointer = %d\n", *pointer);
    
    // You can't get a pointer to some things...
    // This won't compile:
    // &(do_things());
    
    // We can't do this for the same reason...
    // &10;
    
    // This one is actually exactly the same as the one above...
    // &SIZE;
    
    // You have to make memory to store the value to get a pointer to it!
    int result = do_things();
    printf("  result  = %d\n",           result);
    printf("  &result = %p\n", (void *) &result);

    
    // This won't compile either. Same reason.
    // &(&result);
    // You have to make memory to store the pointer to get a pointer to it!
    int * result_p = &result;
    printf("&result_p = %p\n", (void *) &result_p);
    int **result_pp = &result_p;
    int ***result_ppp = &result_pp;
    
    return 0;
}
