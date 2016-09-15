/* Provided as is */

/***** Register addresses *****/
#define TDC7200_CONFIG1_ADDR            0x00
#define TDC7200_CONFIG2_ADDR            0x01
#define TDC7200_INT_STATUS_ADDR         0x02
#define TDC7200_INT_MASK_ADDR           0x03
#define TDC7200_COARSE_CNTR_OVF_H_ADDR       0x04
#define TDC7200_COARSE_CNTR_OVF_L_ADDR       0x05
#define TDC7200_CLOCK_CNTR_OVF_H_ADDR        0x06
#define TDC7200_CLOCK_CNTR_OVF_L_ADDR        0x07
#define TDC7200_CLOCK_CNTR_STOP_MASK_H_ADDR  0x08
#define TDC7200_CLOCK_CNTR_STOP_MASK_L_ADDR  0x09
#define TDC7200_TIME1_ADDR              0x10 /* Read only */
#define TDC7200_CLOCK_COUNT1_ADDR       0x11 /* Read only */
#define TDC7200_TIME2_ADDR              0x12 /* Read only */
#define TDC7200_CLOCK_COUNT2_ADDR       0x13 /* Read only */
#define TDC7200_TIME3_ADDR              0x14 /* Read only */
#define TDC7200_CLOCK_COUNT3_ADDR       0x15 /* Read only */
#define TDC7200_TIME4_ADDR              0x16 /* Read only */
#define TDC7200_CLOCK_COUNT4_ADDR       0x17 /* Read only */
#define TDC7200_TIME5_ADDR              0x18 /* Read only */
#define TDC7200_CLOCK_COUNT5_ADDR       0x19 /* Read only */
#define TDC7200_TIME6_ADDR              0x1A /* Read only */
#define TDC7200_CALIBRATION1_ADDR       0x1B /* Read only */
#define TDC7200_CALIBRATION2_ADDR       0x1C /* Read only */

/***** Register Masks (so we don't write to reserved bits) *****/

#define TDC7200_CONFIG1_MASK            0xFF
#define TDC7200_CONFIG2_MASK            0xFF
#define TDC7200_INT_STATUS_MASK         0x1F
#define TDC7200_INT_MASK_MASK           0x07
#define TDC7200_COARSE_CNTR_OVF_H_MASK       0xFF
#define TDC7200_COARSE_CNTR_OVF_L_MASK       0xFF
#define TDC7200_CLOCK_CNTR_OVF_H_MASK        0xFF
#define TDC7200_CLOCK_CNTR_OVF_L_MASK        0xFF
#define TDC7200_CLOCK_CNTR_STOP_MASK_H_MASK  0xFF
#define TDC7200_CLOCK_CNTR_STOP_MASK_L_MASK  0xFF

/***** CONFIG1 Register *****/

/* Start new measurement */
#define TDC7200_CONFIG1_START_MEAS 0x01 /* Writing 1 will clear all bits in the interrupt status register */
/* Measurement mode */
#define TDC7200_CONFIG1_MEAS_MODE_Pos 1
#define TDC7200_CONFIG1_MEAS_MODE_MODE1 ((uint32_t)0x00 << TDC7200_CONFIG1_MEAS_MODE_Pos)
#define TDC7200_CONFIG1_MEAS_MODE_MODE2 ((uint32_t)0x01 << TDC7200_CONFIG1_MEAS_MODE_Pos)
/* Start a new measurement at given Start signal edge */
#define TDC7200_CONFIG1_START_EDGE_Pos 3
#define TDC7200_CONFIG1_START_EDGE_RISING_EDGE ((uint32_t)0x00 << TDC7200_CONFIG1_START_EDGE_Pos)
#define TDC7200_CONFIG1_START_EDGE_FALLING_EDGE ((uint32_t)0x01 << TDC7200_CONFIG1_START_EDGE_Pos)
/* Stop the measurement at given Stop signal edge */
#define TDC7200_CONFIG1_STOP_EDGE_Pos 4
#define TDC7200_CONFIG1_STOP_EDGE_RISING_EDGE ((uint32_t)0x00 << TDC7200_CONFIG1_STOP_EDGE_Pos)
#define TDC7200_CONFIG1_STOP_EDGE_FALLING_EDGE ((uint32_t)0x01 << TDC7200_CONFIG1_STOP_EDGE_Pos)
/* TRIGG is output as a edge signal */
#define TDC7200_CONFIG1_TRIGG_EDGE_Pos 5
#define TDC7200_CONFIG1_TRIGG_EDGE_RISING_EDGE ((uint32_t)0x00 << TDC7200_CONFIG1_TRIGG_EDGE_Pos)
#define TDC7200_CONFIG1_TRIGG_EDGE_FALLING_EDGE ((uint32_t)0x01 << TDC7200_CONFIG1_TRIGG_EDGE_Pos)
/* Parity bit for Measurement Result Registers */
#define TDC7200_CONFIG1_PARITY_EN_Pos 6
#define TDC7200_CONFIG1_PARITY_EN_DISABLED ((uint32_t)0x00 << TDC7200_CONFIG1_PARITY_EN_Pos)
#define TDC7200_CONFIG1_PARITY_EN_ENABLED ((uint32_t)0x01 << TDC7200_CONFIG1_PARITY_EN_Pos)
/* Calibration at an interrupted measurement */
#define TDC7200_CONFIG1_FORCE_CAL_Pos 7
#define TDC7200_CONFIG1_FORCE_CAL_DISABLED ((uint32_t)0x00 << TDC7200_CONFIG1_FORCE_CAL_Pos)
#define TDC7200_CONFIG1_FORCE_CAL_ENABLED ((uint32_t)0x01 << TDC7200_CONFIG1_FORCE_CAL_Pos)

/* CONFIG2 Register */
#define TDC7200_CONFIG2_NUM_STOP_SINGLE_STOP    0x00
#define TDC7200_CONFIG2_NUM_STOP_TWO_STOPS      0x01
#define TDC7200_CONFIG2_NUM_STOP_THREE_STOPS    0x02
#define TDC7200_CONFIG2_NUM_STOP_FOUR_STOPS     0x03
#define TDC7200_CONFIG2_NUM_STOP_FIVE_STOPS     0x04
#define TDC7200_CONFIG2_AVG_CYCLES_Pos 3
#define TDC7200_CONFIG2_AVG_CYCLES_1_CYCLES     ((uint32_t)0x00 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_2_CYCLES     ((uint32_t)0x01 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_4_CYCLES     ((uint32_t)0x02 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_8_CYCLES     ((uint32_t)0x03 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_16_CYCLES    ((uint32_t)0x04 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_32_CYCLES    ((uint32_t)0x05 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_64_CYCLES    ((uint32_t)0x06 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_AVG_CYCLES_128_CYCLES   ((uint32_t)0x07 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos 6
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_2_CLOCKS   ((uint32_t)0x00 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_10_CLOCKS  ((uint32_t)0x01 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_20_CLOCKS  ((uint32_t)0x02 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)
#define TDC7200_CONFIG2_CALIBRATION2_PERIODS_40_CLOCKS  ((uint32_t)0x03 << TDC7200_CONFIG2_CALIBRATION2_PERIODS_Pos)

/***** INT_STATUS Register *****/
/* Requires writing a 1 to clear interrupt status */
#define TDC7200_INT_STATUS_NEW_MEAS_INT_NOT_DETECTED 0x00
#define TDC7200_INT_STATUS_NEW_MEAS_INT_DETECTED     0x01
/* Requires writing a 1 to clear interrupt status */
#define TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_Pos 1
#define TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_NO_OVERFLOW          ((uint32_t)0x00 << TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_Pos)
#define TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_OVERFLOW_DETECTED    ((uint32_t)0x01 << TDC7200_INT_STATUS_COARSE_CNTR_OVF_INT_Pos)
/* Requires writing a 1 to clear interrupt status */
#define TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_Pos 2
#define TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_NO_OVERFLOW       ((uint32_t)0x00 << TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_Pos)
#define TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_OVERFLOW_DETECTED ((uint32_t)0x01 << TDC7200_INT_STATUS_CLOCK_CNTR_OVF_INT_Pos)
/* Write 1 will clear the status */
#define TDC7200_INT_STATUS_MEAS_STARTED_FLAG_Pos 3
#define TDC7200_INT_STATUS_MEAS_STARTED_FLAG_MEAS_NOT_OCCURED ((uint32_t)0x00 << TDC7200_INT_STATUS_MEAS_STARTED_FLAG_Pos)
#define TDC7200_INT_STATUS_MEAS_STARTED_FLAG_MEAS_COMPLETED   ((uint32_t)0x01 << TDC7200_INT_STATUS_MEAS_STARTED_FLAG_Pos)
/* Write 1 will clear the status */
#define TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_Pos 4
#define TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_NOT_COMPLETED ((uint32_t)0x00 << TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_Pos)
#define TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_COMPLETED     ((uint32_t)0x01 << TDC7200_INT_STATUS_MEAS_COMPLETE_FLAG_Pos)

/***** INT_MASK Register *****/
#define TDC7200_INT_MASK_NEW_MEAS_MASK_DISABLED 0x00
#define TDC7200_INT_MASK_NEW_MEAS_MASK_ENABLED  0x01
#define TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_Pos
#define TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_DISABLED  ((uint32_t)0x00 << TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_Pos)
#define TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_ENABLED   ((uint32_t)0x01 << TDC7200_INT_MASK_COARSE_CNTR_OVF_MASK_Pos)
#define TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_Pos 2
#define TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_DISABLED   ((uint32_t)0x00 << TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_Pos)
#define TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_ENABLED   ((uint32_t)0x01 << TDC7200_INT_MASK_CLOCK_CNTR_OVF_MASK_Pos)

/* [] END OF FILE */
