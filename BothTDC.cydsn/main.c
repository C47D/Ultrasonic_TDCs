#include <project.h>
#include "cyapicallbacks.h"
#include <stdbool.h>

#include "TDC7200_Regs.h"
#include "TDC7200_Funcs.h"
#include "TDC1000_Regs.h"
#include "TDC1000_Funcs.h"

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

    TDC1000_INIT_t tdc1000;
    TDC7200_INIT_t tdc7200;

    TDC7200_Enable();
    
    for(;;){
        TDC1000_Trigger();
        TDC7200_Trigger();
        TDC1000_getConfig(&tdc1000, false);
        TDC7200_getConfig(&tdc7200, false);
        CyDelay(50);
    }
}

void isr_INTB_Interrupt_InterruptCallback(void){
    isr_INTB_ClearPending();
}

void isr_ERRB_Interrupt_InterruptCallback(void){
    isr_ERRB_ClearPending();
}

/* [] END OF FILE */
