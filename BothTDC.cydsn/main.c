#include <project.h>
#include "cyapicallbacks.h"
#include <stdbool.h>

#include "TDC7200_Regs.h"
#include "TDC7200_Funcs.h"
#include "TDC1000_Regs.h"
#include "TDC1000_Funcs.h"

void printTDC(TDC1000_INIT_t* tdc1000, TDC7200_INIT_t* tdc7200);

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
        printTDC(&tdc1000, &tdc7200);
        CyDelay(50);
    }
}

void printTDC(TDC1000_INIT_t* tdc1000, TDC7200_INIT_t* tdc7200){
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

void isr_ERRB_Interrupt_InterruptCallback(void){
    isr_ERRB_ClearPending();
}

/* [] END OF FILE */
