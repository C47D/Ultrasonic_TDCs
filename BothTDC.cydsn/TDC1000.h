/*
 * @file TDC1000.h
 * @author Carlos Diaz
 * @version v0_1
 * @date 2016
 * @brief Este archivo contiene todos los prototipos
 * de las funciones para el driver del AFE TDC1000
*/

#ifndef TDC1000_H_
#define TDC1000_H_

#ifdef __cplusplus
 extern "C"
{
#endif

/* External includes  */
#include <cytypes.h>
#include <stdbool.h>
#include <stdlib.h>

/* Contants */

/***** Register addresses *****/

#define TDC1000_CONFIG_0_ADDR   0x00
#define TDC1000_CONFIG_1_ADDR   0x01
#define TDC1000_CONFIG_2_ADDR   0x02
#define TDC1000_CONFIG_3_ADDR   0x03
#define TDC1000_CONFIG_4_ADDR   0X04
#define TDC1000_TOF_1_ADDR      0x05
#define TDC1000_TOF_0_ADDR      0x06
#define TDC1000_ERROR_FLAGS_ADDR 0x07
#define TDC1000_TIMEOUT_ADDR    0x08
#define TDC1000_CLOCK_RATE_ADDR 0x09

/***** CONFIG_0 Register  *****/
#define TDC1000_CONFIG_0_NUM_TX_MASK 0x1F
#define TDC1000_CONFIG_0_TX_FREQ_DIV_MASK 0x07
#define TDC1000_CONFIG_0_TX_FREQ_DIV_Pos 5
#define TDC1000_CONFIG_0_TX_FREQ_DIV_BY2 ((uint32_t)0x00 << TDC1000_CONFIG_0_TX_FREQ_DIV_Pos)
#define TDC1000_CONFIG_0_TX_FREQ_DIV_BY4 ((uint32_t)0x01 << TDC1000_CONFIG_0_TX_FREQ_DIV_Pos)
#define TDC1000_CONFIG_0_TX_FREQ_DIV_BY8 ((uint32_t)0x02 << TDC1000_CONFIG_0_TX_FREQ_DIV_Pos)
#define TDC1000_CONFIG_0_TX_FREQ_DIV_BY16 ((uint32_t)0x03 << TDC1000_CONFIG_0_TX_FREQ_DIV_Pos)
#define TDC1000_CONFIG_0_TX_FREQ_DIV_BY32 ((uint32_t)0x04 << TDC1000_CONFIG_0_TX_FREQ_DIV_Pos)
#define TDC1000_CONFIG_0_TX_FREQ_DIV_BY64 ((uint32_t)0x05 << TDC1000_CONFIG_0_TX_FREQ_DIV_Pos)
#define TDC1000_CONFIG_0_TX_FREQ_DIV_BY128 ((uint32_t)0x06 << TDC1000_CONFIG_0_TX_FREQ_DIV_Pos)
#define TDC1000_CONFIG_0_TX_FREQ_DIV_BY256 ((uint32_t)0x07 << TDC1000_CONFIG_0_TX_FREQ_DIV_Pos)

/***** CONFIG_1 Register  *****/

/* Number of expected receive events */
#define TDC1000_CONFIG_1_NUM_RX_MASK    0x07
#define TDC1000_CONFIG_1_NUM_RX_NOEVENT 0x00
#define TDC1000_CONFIG_1_NUM_RX_1EVENT  0x01
#define TDC1000_CONFIG_1_NUM_RX_2EVENT  0x02
#define TDC1000_CONFIG_1_NUM_RX_3EVENT  0x03
#define TDC1000_CONFIG_1_NUM_RX_4EVENT  0x04
#define TDC1000_CONFIG_1_NUM_RX_5EVENT  0x05
#define TDC1000_CONFIG_1_NUM_RX_6EVENT  0x06
#define TDC1000_CONFIG_1_NUM_RX_7EVENT  0x07
/* Number of measurement cycles to average in stopwatch/MCU */
#define TDC1000_CONFIG_1_NUM_AVG_Pos            0x03
#define TDC1000_CONFIG_1_NUM_AVG_MASK           0x07
#define TDC1000_CONFIG_1_NUM_AVG_1MEAS_CYCLE    ((uint32_t)0x00 << TDC1000_CONFIG_1_NUM_AVG_Pos)
#define TDC1000_CONFIG_1_NUM_AVG_2MEAS_CYCLE    ((uint32_t)0x01 << TDC1000_CONFIG_1_NUM_AVG_Pos)
#define TDC1000_CONFIG_1_NUM_AVG_4MEAS_CYCLE    ((uint32_t)0x02 << TDC1000_CONFIG_1_NUM_AVG_Pos)
#define TDC1000_CONFIG_1_NUM_AVG_8MEAS_CYCLE    ((uint32_t)0x03 << TDC1000_CONFIG_1_NUM_AVG_Pos)
#define TDC1000_CONFIG_1_NUM_AVG_16MEAS_CYCLE   ((uint32_t)0x04 << TDC1000_CONFIG_1_NUM_AVG_Pos)
#define TDC1000_CONFIG_1_NUM_AVG_32MEAS_CYCLE   ((uint32_t)0x05 << TDC1000_CONFIG_1_NUM_AVG_Pos)
#define TDC1000_CONFIG_1_NUM_AVG_64MEAS_CYCLE   ((uint32_t)0x06 << TDC1000_CONFIG_1_NUM_AVG_Pos)
#define TDC1000_CONFIG_1_NUM_AVG_127MEAS_CYCLE  ((uint32_t)0x07 << TDC1000_CONFIG_1_NUM_AVG_Pos)

/***** CONFIG_2 Register *****/

/* Time-of-flight measurement mode */
#define TDC1000_CONFIG_2_TOF_MEAS_MODE_MASK     0x3
#define TDC1000_CONFIG_2_TOF_MEAS_MODE_1        0x1
#define TDC1000_CONFIG_2_TOF_MEAS_MODE_2        0x2
#define TDC1000_CONFIG_2_TOF_MEAS_MODE_RESERVED 0x3
/* Active TX/RX channel pair */
#define TDC1000_CONFIG_2_CH_SEL_Pos 0x01
#define TDC1000_CONFIG_2_CH_SEL_CH1 ((uint32_t)0x00 << TDC1000_CONFIG_2_CH_SEL_Pos)
#define TDC1000_CONFIG_2_CH_SEL_CH2 ((uint32_t)0x01 << TDC1000_CONFIG_2_CH_SEL_Pos)
/* External channel selected by CHSEL pin */
#define TDC1000_CONFIG_2_EXT_CHSEL_Pos      0x02
#define TDC1000_CONFIG_2_EXT_CHSEL_DISABLE  ((uint32_t)0x00 << TDC1000_CONFIG_2_EXT_CHSEL_Pos)
#define TDC1000_CONFIG_2_EXT_CHSEL_ENABLE   ((uint32_t)0x01 << TDC1000_CONFIG_2_EXT_CHSEL_Pos)
/* Automatic channel swap in Mode 2 of operation. The setting is ignored if EXT_CHSEL = 1 */
#define TDC1000_CONFIG_2_CH_SWP_Pos      0x03
#define TDC1000_CONFIG_2_CH_SWP_DISABLE  ((uint32_t)0x00 << TDC1000_CONFIG_2_CH_SWP_Pos)
#define TDC1000_CONFIG_2_CH_SWP_ENABLE   ((uint32_t)0x01 << TDC1000_CONFIG_2_CH_SWP_Pos)
/* TX burst damping */
#define TDC1000_CONFIG_2_DAMPING_Pos      0x04
#define TDC1000_CONFIG_2_DAMPING_DISABLE  ((uint32_t)0x00 << TDC1000_CONFIG_2_DAMPING_Pos)
#define TDC1000_CONFIG_2_DAMPING_ENABLE   ((uint32_t)0x01 << TDC1000_CONFIG_2_DAMPING_Pos)
/* AFE measurement type */
#define TDC1000_CONFIG_2_MEAS_MODE_Pos      0x05
#define TDC1000_CONFIG_2_MEAS_MODE_TOF      ((uint32_t)0x00 << TDC1000_CONFIG_2_MEAS_MODE_Pos)
#define TDC1000_CONFIG_2_MEAS_MODE_TEMP     ((uint32_t)0x01 << TDC1000_CONFIG_2_MEAS_MODE_Pos)
/* Common-mode voltage reference control */
#define TDC1000_CONFIG_2_VCOM_SEL_Pos      0x06
#define TDC1000_CONFIG_2_VCOM_SEL_INTERNAL ((uint32_t)0x00 << TDC1000_CONFIG_2_VCOM_SEL_Pos)
#define TDC1000_CONFIG_2_VCOM_SEL_EXTERNAL ((uint32_t)0x01 << TDC1000_CONFIG_2_VCOM_SEL_Pos)

/***** CONFIG_3 Register *****/

/* Echo qualification DAC threshold levell with respect to VCOM */
#define TDC1000_CONFIG_3_ECHO_QUAL_THLD_35mV    0x00
#define TDC1000_CONFIG_3_ECHO_QUAL_THLD_50mV    0x01
#define TDC1000_CONFIG_3_ECHO_QUAL_THLD_75mV    0x02
#define TDC1000_CONFIG_3_ECHO_QUAL_THLD_125mV   0x03
#define TDC1000_CONFIG_3_ECHO_QUAL_THLD_220mV   0x04
#define TDC1000_CONFIG_3_ECHO_QUAL_THLD_410mV   0x05
#define TDC1000_CONFIG_3_ECHO_QUAL_THLD_775mV   0x06
#define TDC1000_CONFIG_3_ECHO_QUAL_THLD_1500mV  0x08
/* Power blanking in standard TOF measurements. */
#define TDC1000_CONFIG_3_BLANKING_Pos       0x03
#define TDC1000_CONFIG_3_BLANKING_DISABLE   ((uint32_t)0x00 << TDC1000_CONFIG_3_BLANKING_Pos)
#define TDC1000_CONFIG_3_BLANKING_ENABLE    ((uint32_t)0x01 << TDC1000_CONFIG_3_BLANKING_Pos)
/* Clock divider for temperature mode */
#define TDC1000_CONFIG_3_TEMP_CLK_DIV_Pos               0x04
#define TDC1000_CONFIG_3_TEMP_CLK_DIV_DIVIDEBY8         ((uint32_t)0x00 << TDC1000_CONFIG_3_TEMP_CLK_DIV_Pos)
#define TDC1000_CONFIG_3_TEMP_CLK_DIV_USETX_FREQ_DIV    ((uint32_t)0x01 << TDC1000_CONFIG_3_TEMP_CLK_DIV_Pos)
/* RTD type */
#define TDC1000_CONFIG_3_TEMP_RTD_SEL_Pos       0x05
#define TDC1000_CONFIG_3_TEMP_RTD_SEL_PT1000    ((uint32_t)0x00 << TDC1000_CONFIG_3_TEMP_RTD_SEL_Pos)
#define TDC1000_CONFIG_3_TEMP_RTD_SEL_PT500     ((uint32_t)0x01 << TDC1000_CONFIG_3_TEMP_RTD_SEL_Pos)
/* Temperature measurement channels */
#define TDC1000_CONFIG_3_TEMP_MODE_Pos              0x06
#define TDC1000_CONFIG_3_TEMP_MODE_REF_RTD1_RTD2    ((uint32_t)0x00 << TDC1000_CONFIG_3_TEMP_MODE_Pos)
#define TDC1000_CONFIG_3_TEMP_MODE_REF_RTD1         ((uint32_t)0x01 << TDC1000_CONFIG_3_TEMP_MODE_Pos)

/***** CONFIG_4 Register *****/

/* TX 180° pulse shift position, ranging from 0 to 31 */
#define TDC1000_CONFIG_4_TX_PH_SHIFT_POS_MASK   0x1F
/* Trigger edge polarity */
#define TDC1000_CONFIG_4_TRIG_EDGE_POLARITY_Pos             0x05
#define TDC1000_CONFIG_4_TRIG_EDGE_POLARITY_RISING_EDGE     ((uint32_t)0x00 << TDC1000_CONFIG_4_TRIG_EDGE_POLARITY_Pos)
#define TDC1000_CONFIG_4_TRIG_EDGE_POLARITY_FALLING_EDGE    ((uint32_t)0x01 << TDC1000_CONFIG_4_TRIG_EDGE_POLARITY_Pos)
/* Receive echo mode */
#define TDC1000_CONFIG_4_RECEIVE_MODE_Pos       0x06
#define TDC1000_CONFIG_4_RECEIVE_MODE_SINGLE    ((uint32_t)0x00 << TDC1000_CONFIG_4_RECEIVE_MODE_Pos)
#define TDC1000_CONFIG_4_RECEIVE_MODE_MULTI     ((uint32_t)0x01 << TDC1000_CONFIG_4_RECEIVE_MODE_Pos)

/***** TOF_1 Register *****/

/* TIMING_REG fields 2 most-significant bits */
#define TDC1000_TOF_1_TIMING_REG
/* LNA feedback mode */
#define TDC1000_TOF_1_LNA_FB_Pos        0x02
#define TDC1000_TOF_1_LNA_FB_CAPACITIVE ((uint32_t)0x00 << TDC1000_TOF_1_LNA_FB_Pos)
#define TDC1000_TOF_1_LNA_FB_RESISTIVE  ((uint32_t)0x01 << TDC1000_TOF_1_LNA_FB_Pos)
/* LNA control */
#define TDC1000_TOF_1_LNA_CTRL_Pos      0x03
#define TDC1000_TOF_1_LNA_CTRL_ACTIVE   ((uint32_t)0x00 << TDC1000_TOF_1_LNA_CTRL_Pos)
#define TDC1000_TOF_1_LNA_CTRL_BYPASSED ((uint32_t)0x01 << TDC1000_TOF_1_LNA_CTRL_Pos)
/* PGA control */
#define TDC1000_TOF_1_PGA_CTRL_Pos      0x04
#define TDC1000_TOF_1_PGA_CTRL_ACTIVE   ((uint32_t)0x00 << TDC1000_TOF_1_PGA_CTRL_Pos)
#define TDC1000_TOF_1_PGA_CTRL_BYPASSED ((uint32_t)0x01 << TDC1000_TOF_1_PGA_CTRL_Pos)
/* PGA gain */
#define TDC1000_TOF_1_PGA_GAIN_Pos   0x05
#define TDC1000_TOF_1_PGA_GAIN_0dB   ((uint32_t)0x00 << TDC1000_TOF_1_PGA_GAIN_Pos)
#define TDC1000_TOF_1_PGA_GAIN_3dB   ((uint32_t)0x01 << TDC1000_TOF_1_PGA_GAIN_Pos)
#define TDC1000_TOF_1_PGA_GAIN_6dB   ((uint32_t)0x02 << TDC1000_TOF_1_PGA_GAIN_Pos)
#define TDC1000_TOF_1_PGA_GAIN_9dB   ((uint32_t)0x03 << TDC1000_TOF_1_PGA_GAIN_Pos)
#define TDC1000_TOF_1_PGA_GAIN_12dB  ((uint32_t)0x04 << TDC1000_TOF_1_PGA_GAIN_Pos)
#define TDC1000_TOF_1_PGA_GAIN_15dB  ((uint32_t)0x05 << TDC1000_TOF_1_PGA_GAIN_Pos)
#define TDC1000_TOF_1_PGA_GAIN_18dB  ((uint32_t)0x06 << TDC1000_TOF_1_PGA_GAIN_Pos)
#define TDC1000_TOF_1_PGA_GAIN_21dB  ((uint32_t)0x07 << TDC1000_TOF_1_PGA_GAIN_Pos)

/***** TOF_0 Register *****/

/* TIMING_REG fields 8 least significant bits */
#define TDC1000_TOF_0_TIMING_REG

/***** ERROR_FLAGS Register *****/

/* The received echo amplitude exceeds the largest echo qualification threshold at the input comparators */
#define TDC1000_ERROR_FLAGS_ERR_SIG_HIGH
/* No signals were received and timeout occurred */
#define TDC1000_ERROR_FLAGS_ERR_NO_SIG_Pos    0x01
/* The number of received and qualified zero-crossings was less than the excpected number set in NUM_RX and a timeout occurred */
#define TDC1000_ERROR_FLAGS_ERR_SIG_WEAK_Pos  0x02

/***** TIMEOUT Register *****/

/* Echo listening window timeout */
#define TDC1000_TIMEOUT_TOF_TIMEOUT_CTRL_128xT0 0x00
#define TDC1000_TIMEOUT_TOF_TIMEOUT_CTRL_256xT0 0x01
#define TDC1000_TIMEOUT_TOF_TIMEOUT_CTRL_512xT0 0x02
#define TDC1000_TIMEOUT_TOF_TIMEOUT_CTRL_1024xT0 0x03
/* Echo receive timeout control */
#define TDC1000_TIMEOUT_ECHO_TIMEOUT_Pos        0x02
#define TDC1000_TIMEOUT_ECHO_TIMEOUT_ENABLE     ((uint32_t)0x00 << TDC1000_TIMEOUT_ECHO_TIMEOUT_Pos)
#define TDC1000_TIMEOUT_ECHO_TIMEOUT_DISABLE    ((uint32_t)0x01 << TDC1000_TIMEOUT_ECHO_TIMEOUT_Pos)
/* Short TOF blanking period */
#define TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_Pos      0x03
#define TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_8xT0     ((uint32_t)0x00 << TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_Pos)
#define TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_16xT0    ((uint32_t)0x01 << TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_Pos)
#define TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_32xT0    ((uint32_t)0x02 << TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_Pos)
#define TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_64xT0    ((uint32_t)0x03 << TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_Pos)
#define TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_128xT0   ((uint32_t)0x04 << TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_Pos)
#define TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_256xT0   ((uint32_t)0x05 << TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_Pos)
#define TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_512xT0   ((uint32_t)0x06 << TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_Pos)
#define TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_1024xT0  ((uint32_t)0x07 << TDC1000_TIMEOUT_SHORT_TOF_BLANK_PERIOD_Pos)
/* Short TOF control */
#define TDC1000_TIMEOUT_FORCE_SHORT_TOF_Pos         0x06
#define TDC1000_TIMEOUT_FORCE_SHORT_TOF_DISABLED    ((uint32_t)0x00 << TDC1000_TIMEOUT_FORCE_SHORT_TOF_Pos)
#define TDC1000_TIMEOUT_FORCE_SHORT_TOF_FORCE       ((uint32_t)0x01 << TDC1000_TIMEOUT_FORCE_SHORT_TOF_Pos)

/***** CLOCK_RATE Register *****/

/* Receiver auto-zero period */
#define TDC1000_CLOCK_RATE_AUTOZERO_PERIOD_64xT0 0x00
#define TDC1000_CLOCK_RATE_AUTOZERO_PERIOD_128xT0 0x01
#define TDC1000_CLOCK_RATE_AUTOZERO_PERIOD_256xT0 0x02
#define TDC1000_CLOCK_RATE_AUTOZERO_PERIOD_512xT0 0x03
/* CLKIN divider to generate T0 */
#define TDC1000_CLOCK_RATE_CLOCKIN_DIV_Pos  0x02
#define TDC1000_CLOCK_RATE_CLOCKIN_DIV_DIVBY1  ((uint32_t)0x00 << TDC1000_CLOCK_RATE_CLOCKIN_DIV_Pos)
#define TDC1000_CLOCK_RATE_CLOCKIN_DIV_DIVBY2  ((uint32_t)0x01 << TDC1000_CLOCK_RATE_CLOCKIN_DIV_Pos)

/* SPI Commands */
#define TDC1000_READ_CMD    0x00
#define TDC1000_WRITE_CMD   0x40
#define TDC1000_DUMMY_BYTE  0x00

typedef struct{
    uint8_t CONFIG_0;
    uint8_t CONFIG_1;
    uint8_t CONFIG_2;
    uint8_t CONFIG_3;
    uint8_t CONFIG_4;
    uint8_t TOF_1;
    uint8_t TOF_0;
    uint8_t ERROR_FLAGS;
    uint8_t TIMEOUT;
    uint8_t CLOCK_RATE;
}TDC1000_INIT_t;

/* Functions */
void TDC1000_setCONFIG_0(uint8_t data);
void TDC1000_setCONFIG_1(uint8_t data);
void TDC1000_setCONFIG_2(uint8_t data);
void TDC1000_setCONFIG_3(uint8_t data);
void TDC1000_setCONFIG_4(uint8_t data);
void TDC1000_setTOF_1(uint8_t data);
void TDC1000_setTOF_0(uint8_t data);
void TDC1000_setERROR_FLAGS(uint8_t data);
void TDC1000_setTIMEOUT(uint8_t data);
void TDC1000_setCLOCK_RATE(uint8_t data);
uint8_t TDC1000_getCONFIG_0(void);
uint8_t TDC1000_getCONFIG_1(void);
uint8_t TDC1000_getCONFIG_2(void);
uint8_t TDC1000_getCONFIG_3(void);
uint8_t TDC1000_getCONFIG_4(void);
uint8_t TDC1000_getTOF_1(void);
uint8_t TDC1000_getTOF_0(void);
uint8_t TDC1000_getERROR_FLAGS(void);
uint8_t TDC1000_getTIMEOUT(void);
uint8_t TDC1000_getCLOCK_RATE(void);
void TDC1000_Start(TDC1000_INIT_t tdc);

void TDC1000_reset(void);
uint8_t TDC1000_readModeSelect(void);
uint8_t TDC1000_readTXFreqDiv(void);
uint8_t TDC1000_readNumTX(void);
uint8_t TDC1000_readNumAvg(void);
uint8_t TDC1000_readNumRX(void);
uint8_t TDC1000_readEchoQualThld(void);
uint8_t TDC1000_readTXPhShiftPos(void);
uint8_t TDC1000_readPGAGain(void);
uint8_t TDC1000_readTimingReg(void);
uint8_t TDC1000_readShortToFBlankPeriod(void);
uint8_t TDC1000_readToFTimeoutCtrl(void);
uint8_t TDC1000_readAutozeroPeriod(void);
void TDC1000_setEnable(bool enable);
bool TDC1000_getEnable(void);
bool TDC1000_readChannelSelect(void);
uint8_t TDC1000_readClockFreqIn(void);
void TDC1000_setClockFreqIn(uint32_t freq);

void TDC1000_WriteSingleRegister(uint8_t regAddr, uint8_t data);
uint8_t TDC1000_ReadSingleRegister(uint8_t regAddr);

#ifdef __cplusplus
}
#endif

#endif	/* TDC1000_H_  */

/* End of file  */
