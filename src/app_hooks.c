#include <stdio.h> // For printf
#include "pico/stdlib.h" // For stdio_init_all() (if you want to print to console)
#include "FreeRTOS.h" // Required for FreeRTOS types/macros
#include "task.h"     // Required for FreeRTOS task-related functions

// Hook for stack overflow
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName )
{
    // This function will be called if a task overflows its stack.
    // It's crucial to handle this, perhaps by restarting the system
    // or logging the error. For debugging, you can print the task name.
    // A common action is to enter an infinite loop or reset the microcontroller.
    printf("ERROR: Stack overflow detected in task: %s\r\n", pcTaskName);
    for( ;; ); // Halt the system for debugging
}

// Hook for Malloc failed
void vApplicationMallocFailedHook( void )
{
    // This function will be called if a call to pvPortMalloc() fails.
    // This typically means there's not enough FreeRTOS heap memory available.
    printf("ERROR: Malloc failed! Not enough FreeRTOS heap memory.\r\n");
    for( ;; ); // Halt the system for debugging
}

// You might also need to include these if you're using other FreeRTOS features
// and haven't defined them elsewhere, though they are not explicitly
// causing an error in this log.
// void vApplicationDaemonTaskStartupHook( void ) { /* Optional */ }
// void vApplicationIdleHook( void ) { /* Optional */ }
// void vApplicationTickHook( void ) { /* Optional */ }