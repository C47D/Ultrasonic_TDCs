#include <project.h>
#include "cyapicallbacks.h"

#include "TDC7200.h"
#include "TDC1000.h"

int main(){

    /* Start UART interface */
    UART_Start();
    /* Start SPI interface */
    SPI_Start();
    /* Start INTB interrupt */
    isr_INTB_Start();
    /* Start ERRB interrupt */
    isr_ERRB_Start();

    CyGlobalIntEnable; /* Enable global interrupts. */

    for(;;){
        TDC1000_getConfig(NULL);
        TDC7200_Enable();
        TDC7200_getConfig(NULL);
    }
}

void isr_INTB_Interrupt_InterruptCallback(void){
    
}

void isr_ERRB_Interrupt_InterruptCallback(void){
    
}

/* [] END OF FILE */
