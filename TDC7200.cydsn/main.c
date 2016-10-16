#include <project.h>
#include <stdbool.h>

#include "cyapicallbacks.h"

#include "TDC7200_Regs.h"
#include "TDC7200_Funcs.h"

void printTDC(TDC7200_INIT_t* tdc7200);

int main(){

    SPI_Start();
    UART_Start();
    isr_INTB_Start();
    
    CyGlobalIntEnable;

    TDC7200_INIT_t tdc7200;

    TDC7200_Enable();
    
    for(;;){
        TDC7200_Trigger();
        TDC7200_getConfig(&tdc7200, false);
        printTDC(&tdc7200);
        CyDelay(50);
    }
}

void printTDC(TDC7200_INIT_t* tdc7200){
    if(tdc7200 != NULL){
        UART_PutString("Registros TDC7200\r\n");
        UART_PutString("CONFIG1 \t");
        UART_PutHexByte(tdc7200->CONFIG1);
        UART_PutCRLF();
        UART_PutString("CONFIG2 \t");
        UART_PutHexByte(tdc7200->CONFIG2);
        UART_PutCRLF();
        UART_PutString("INT_MASK \t");
        UART_PutHexByte(tdc7200->INT_MASK);
        UART_PutCRLF();
        UART_PutString("INT_STATUS \t");
        UART_PutHexByte(tdc7200->INT_STATUS);
        UART_PutCRLF();
        UART_PutString("CLOCK_CNTR_OVF_H \t");
        UART_PutHexByte(tdc7200->CLOCK_CNTR_OVF_H);
        UART_PutCRLF();
        UART_PutString("CLOCK_CNTR_OVF_L \t");
        UART_PutHexByte(tdc7200->CLOCK_CNTR_OVF_L);
        UART_PutCRLF();
        UART_PutString("CLOCK_CNTR_STOP_MASK_H \t");
        UART_PutHexByte(tdc7200->CLOCK_CNTR_STOP_MASK_H);
        UART_PutCRLF();
        UART_PutString("CLOCK_CNTR_STOP_MASK_L \t");
        UART_PutHexByte(tdc7200->CLOCK_CNTR_STOP_MASK_L);
        UART_PutCRLF();
        UART_PutString("COARSE_CNTR_OVF_H \t");
        UART_PutHexByte(tdc7200->COARSE_CNTR_OVF_H);
        UART_PutCRLF();
        UART_PutString("COARSE_CNTR_OVF_L \t");
        UART_PutHexByte(tdc7200->COARSE_CNTR_OVF_L);
        UART_PutCRLF();
    }
}

void isr_INTB_Interrupt_InterruptCallback(void){
    isr_INTB_ClearPending();
}

/* [] END OF FILE */
