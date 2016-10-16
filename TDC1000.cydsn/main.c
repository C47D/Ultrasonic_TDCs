#include <project.h>
#include <stdbool.h>

#include "cyapicallbacks.h"

#include "TDC1000_Regs.h"
#include "TDC1000_Funcs.h"

void printTDC(TDC1000_INIT_t* tdc1000);

int main(){

    CyGlobalIntEnable;
    
    SPI_Start();
    UART_Start();
    isr_ERRB_Start();
    
    TDC1000_INIT_t tdc1000;
    
    for(;;){
        TDC1000_Trigger();
        TDC1000_getConfig(&tdc1000, false);
        printTDC(&tdc1000);
        CyDelay(50);
    }
}

void printTDC(TDC1000_INIT_t* tdc1000){
    if(tdc1000 != NULL){
        UART_PutString("Registros TDC1000\r\n");
        UART_PutString("CONFIG_0 \t");
        UART_PutHexByte(tdc1000->CONFIG_0);
        UART_PutCRLF();
        UART_PutString("CONFIG_1 \t");
        UART_PutHexByte(tdc1000->CONFIG_1);
        UART_PutCRLF();
        UART_PutString("CONFIG_2 \t");
        UART_PutHexByte(tdc1000->CONFIG_2);
        UART_PutCRLF();
        UART_PutString("CONFIG_3 \t");
        UART_PutHexByte(tdc1000->CONFIG_3);
        UART_PutCRLF();
        UART_PutString("CONFIG_4 \t");
        UART_PutHexByte(tdc1000->CONFIG_4);
        UART_PutCRLF();
        UART_PutString("TOF_1 \t");
        UART_PutHexByte(tdc1000->TOF_1);
        UART_PutCRLF();
        UART_PutString("TOF_0 \t");
        UART_PutHexByte(tdc1000->TOF_0);
        UART_PutCRLF();
        UART_PutString("TIMEOUT \t");
        UART_PutHexByte(tdc1000->TIMEOUT);
        UART_PutCRLF();
        UART_PutString("CLOCK_RATE \t");
        UART_PutHexByte(tdc1000->CLOCK_RATE);
        UART_PutCRLF();
        UART_PutString("ERROR_FLAGS \t");
        UART_PutHexByte(tdc1000->ERROR_FLAGS);
        UART_PutCRLF();
    }
}

void isr_ERRB_Interrupt_InterruptCallback(void){
    isr_ERRB_ClearPending();
}

/* [] END OF FILE */
