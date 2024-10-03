#ifndef __BK4818_JAMIEXU_H__
#define __BK4818_JAMIEXU_H__


#include "gpio.h"
#include "peripherals/gpio.h"
#include <calibInfo_A36Plus.h>
// Written by Jamiexu
#ifdef __cplusplus
extern "C" {
#endif

#define BK4819_SCK_LOW gpio_clearPin(BK4819_CLK)
#define BK4819_SCK_HIGH gpio_setPin(BK4819_CLK)

#define BK4819_SDA_LOW gpio_clearPin(BK4819_DAT)
#define BK4819_SDA_HIGH gpio_setPin(BK4819_DAT)

#define BK4819_SCN_LOW gpio_clearPin(BK4819_CS)
#define BK4819_SCN_HIGH gpio_setPin(BK4819_CS)

#define BK4819_SDA_READ gpio_readPin(BK4819_DAT)

#define BK4819_SDA_DIR_OUT gpio_setMode(BK4819_DAT, OUTPUT)
#define BK4819_SDA_DIR_IN gpio_setMode(BK4819_DAT, INPUT_PULL_UP)

#define BK4819_REG_READ 0x80
#define BK4819_REG_WRITE 0x00

#define BITV(x, y) ((x) << (y))

#define BK4819_REG30_VCO_CALIBRATION BIT(15)
#define BK4819_REG30_REVERSE1_ENABLE BIT(14)
#define BK4819_REG30_RX_LINK_ENABLE BITV(0x0F, 10)
#define BK4819_REG30_REVERSE2_ENABLE BIT(8)
#define BK4819_REG30_AF_DAC_ENABLE BIT(9)
#define BK4819_REG30_PLL_VCO_ENABLE BITV(0x0F, 4)
#define BK4819_REG30_PA_GAIN_ENABLE BIT(3)
#define BK4819_REG30_MIC_ADC_ENABLE BIT(2)
#define BK4819_REG30_TX_DSP_ENABLE BIT(1)
#define BK4819_REG30_RX_DSP_ENABLE BIT(0)

#define BK4819_REG51_TX_CTCDSS_ENABLE BIT(15)
#define BK4819_REG51_GPIO6_CDCSS BIT(14)
#define BK4819_REG51_TRANSMIT_NEG_CDCSS_CODE BIT(13)
#define BK4819_REG51_CTCSCSS_MODE_SEL BIT(12)
#define BK4819_REG51_CDCSS_BIT_SEL BIT(11)
#define BK4819_REG51_1050HZ_DET_MOD BIT(10)
#define BK4819_REG51_AUTO_CDCSS_BW_MOD BIT(9)
#define BK4819_REG51_AUTO_CTCSS_BW_MOD BIT(8)
#define BK4819_REG51_CTCDCSS_TX_GAIN1T(x) BITV((x), 0)

#define BK4819_SCAN_FRE_TIME_2 0x00
#define BK4819_SCAN_FRE_TIME_4 0x01
#define BK4819_SCAN_FRE_TIME_8 0x02
#define BK4819_SCAN_FRE_TIME_16 0x03

typedef enum
{
    BK4819_REG_00 = 0x00,
    BK4819_REG_02 = 0x02,
    BK4819_REG_07 = 0x07,
    BK4819_REG_08 = 0x08,
    BK4819_REG_09 = 0x09,
    BK4819_REG_0A = 0x0A,
    BK4819_REG_0B = 0x0B,
    BK4819_REG_0C = 0x0C,

    BK4819_REG_0D = 0x0D,
    BK4819_REG_0E = 0x0E,
    BK4819_REG_10 = 0x10,
    BK4819_REG_11 = 0x11,
    BK4819_REG_12 = 0x12,
    BK4819_REG_13 = 0x13,
    BK4819_REG_14 = 0x14,
    BK4819_REG_18 = 0x18,

    BK4819_REG_19 = 0x19,
    BK4819_REG_1A = 0x1A,
    BK4819_REG_1F = 0x1F,
    BK4819_REG_1E = 0x1E,
    BK4819_REG_24 = 0x24,
    BK4819_REG_26 = 0x26,
    BK4819_REG_28 = 0x28,
    BK4819_REG_29 = 0x29,
    BK4819_REG_2A = 0X2A,
    BK4819_REG_2B = 0x2B,
    BK4819_REG_2C = 0x2c,
    BK4819_REG_2E = 0x2E,
    BK4819_REG_30 = 0x30,
    BK4819_REG_31 = 0x31,
    BK4819_REG_32 = 0x32,
    BK4819_REG_33 = 0x33,
    BK4819_REG_36 = 0x36,
    BK4819_REG_37 = 0x37,
    BK4819_REG_38 = 0x38,

    BK4819_REG_39 = 0x39,
    BK4819_REG_3B = 0x3B,
    BK4819_REG_3C = 0x3C,
    BK4819_REG_3D = 0x3D,
    BK4819_REG_3E = 0x3E,
    BK4819_REG_3F = 0x3F,
    BK4819_REG_40 = 0x40,
    BK4819_REG_43 = 0x43,

    BK4819_REG_44 = 0x44,
    BK4819_REG_45 = 0x45,
    BK4819_REG_46 = 0x46,
    BK4819_REG_47 = 0x47,
    BK4819_REG_48 = 0x48,
    BK4819_REG_49 = 0x49,

    BK4819_REG_4B = 0x4B,
    BK4819_REG_4D = 0x4D,
    BK4819_REG_4E = 0x4E,
    BK4819_REG_4F = 0x4F,
    BK4819_REG_50 = 0x50,
    BK4819_REG_51 = 0x51,
    BK4819_REG_52 = 0x52,
    BK4819_REG_54 = 0x54,
    BK4819_REG_53 = 0x53,
    BK4819_REG_55 = 0x55,
    BK4819_REG_58 = 0x58,
    BK4819_REG_59 = 0x59,
    BK4819_REG_5A = 0x5A,
    BK4819_REG_5B = 0x5B,
    BK4819_REG_5C = 0x5C,
    BK4819_REG_5D = 0x5D,
    BK4819_REG_5E = 0x5E,

    BK4819_REG_5F = 0x5F,
    BK4819_REG_63 = 0x63,
    BK4819_REG_64 = 0x64,
    BK4819_REG_65 = 0x65,
    BK4819_REG_67 = 0x67,
    BK4819_REG_68 = 0x68,
    BK4819_REG_69 = 0x69,
    BK4819_REG_6A = 0x6A,

    BK4819_REG_6F = 0x6F,
    BK4819_REG_70 = 0x70,
    BK4819_REG_71 = 0x71,
    BK4819_REG_72 = 0x72,
    BK4819_REG_73 = 0x73,
    BK4819_REG_74 = 0x74,
    BK4819_REG_75 = 0x75,
    BK4819_REG_77 = 0x77,

    BK4819_REG_78 = 0x78,
    BK4819_REG_79 = 0x79,
    BK4819_REG_7A = 0x7A,
    BK4819_REG_7B = 0x7B,
    BK4819_REG_7C = 0x7C,
    BK4819_REG_7D = 0x7D,
    BK4819_REG_7E = 0x7E,
} bk4819_reg_t;

typedef enum
{
    BK4819_INT_FSKTF = BIT(15),   // FSK TX Finished Interrupt
    BK4819_INT_FSKFFAE = BIT(14), // FSK FIFO Almost Empty interrupt
    BK4819_INT_FSKRXF = BIT(13),  // FSK RX Finished interrupt
    BK4819_INT_FSKFFAF = BIT(12), // FSK FIFO Almost Full interrupt
    BK4819_INT_DTMFTF = BIT(11),  // DTMF/5 TONE Found interrupt
    BK4819_INT_CTDSTF = BIT(10),  // CTCSS/CDCSS Tail Found interrupt
    BK4819_INT_CDCSF = BIT(9),    // CDCSS Found interrupt
    BK4819_INT_CDCSL = BIT(8),    // CDCSS Lost interrupt
    BK4819_INT_CTSSF = BIT(7),    // CTCSS Found interrupt
    BK4819_INT_CTCSL = BIT(6),    // CTCSS Lost interrupt
    BK4819_INT_VOXF = BIT(5),     // VOX Found interrupt
    BK4819_INT_VOXL = BIT(4),     // VOX Lost interrupt
    BK4819_INT_SECF = BIT(3),     // Squelch Found interrupt
    BK4819_INT_SECL = BIT(2),     // Squelch Lost interrupt
    BK4819_INT_FSKRS = BIT(1)     // FSK RX Sync interrupt
} bk4819_int_t;

typedef enum
{
    BK4819_FLAG_DTMF_REV = BITV(0x8, 11), // DTMF/5 Tone code received
    BK4819_FLAG_FSK_RX_SNF = BIT(7),      // FSK RX Sync Negative has been found
    BK4819_FLAG_FSK_RX_SPF = BIT(6),      // FSK RX Sync Positive has been found
    BK4819_FLAG_FSK_RX_CRC = BIT(4),      // FSK RX CRC indicator
    BK4819_FLAG_CDCSS_PCR = BIT(14),      // CDCSS positive code received
    BK4819_FLAG_CDCSS_PNR = BIT(15),      //  CDCSS negative code received
} bk4819_flag_t;

typedef enum
{
    BK4819_RDATA_
} bk4819_rdata_t;

// typedef enum
// {
//     bk4819_CTCSS_PHASE_120 = 0X01,
//     bk4819_CTCSS_PHASE_180 = 0X02,
//     bk4819_CTCSS_PHASE_240 = 0X03,
// } bk4819_CTCSS_PHASE;

// typedef enum
// {
//     bk4819_RX_ACG_GAIN_PAG =
// } bk4819_RX_ACG_GAIN;

static void spi_write_byte(uint8_t data);
static void spi_write_half_word(uint16_t data);
static uint16_t spi_read_half_word(void);

uint16_t ReadRegister(unsigned char reg);
static void WriteRegister(bk4819_reg_t reg, uint16_t data);

/**
 * @brief Get interrupt
 *
 * @param interrupt Interrupt type
 * @return uint8_t 0:SET 1:RESET
 */
uint8_t bk4819_int_get(bk4819_int_t interrupt);

/**
 * @brief Enable interrupt
 *
 * @param interrupt
 */
void bk4819_int_enable(bk4819_int_t interrupt);

/**
 * @brief Disable interrupt
 *
 * @param interrupt
 */
void bk4819_int_disable(bk4819_int_t interrupt);

void bk4819_init(void);

/**
 * @brief Set frequency
 *
 * @param freq
 */
void bk4819_set_freq(uint32_t frq);

/**
 * @brief Set TX power
 *
 * @param power TX power in mW
 * @param freq Frequency
 * @param calData Calibration data
 */
void bk4819_setTxPower(uint32_t power, uint32_t freq, PowerCalibrationTables calData);

/**
 * @brief Get band from frequency
 * 
 * @return uint32_t 
 */
uint8_t getBandFromFreq(uint32_t freq);

/**
 * @brief Turn on RX
 *
 */
void bk4819_rx_on(void);

/**
 * @brief Set modulation
 *
 * @param is_FM 0:AM 1:FM
 */
void bk4819_set_modulation(bool is_FM);

/**
 * @brief Turn on TX
 *
 */
void bk4819_tx_on(void);

/**
 * @brief Disable Rx and Tx
 * 
 */
void bk4819_rtx_off(void);

/**
 * @brief Disable all and enable CTCSS1
 *
 * @param frequency
 */
void bk4819_enable_tx_ctcss(uint16_t frequency);

/**
 * @brief Enable Rx CTCSS.
 *
 * @param frequency
 */
void bk4819_enable_rx_ctcss(uint16_t frequency);

/**
 * @brief Disable all and enable CTCSS2
 *
 * @param frequency
 */
void bk4819_enable_ctcss2(uint16_t frequency);

/**
 * @brief Disable all and enable CDCSS
 *
 * @param code_type 0:positive code   1:negative code
 * @param bit_sel 0: 23bit          1:24bit
 * @param cdcss_code cdcss code
 */
void bk4819_enable_tx_cdcss(uint8_t code_type, uint8_t bit_sel, uint32_t cdcss_code);

/**
 * @brief Disable CTCSS/CDCSS
 *
 */
void bk4819_disable_ctdcss(void);

/**
 * @brief Get CTCSS
 *
 * @return uint8_t
 */
uint16_t bk4819_get_ctcss(void);

/**
 * @brief Enable VOX
 *
 * @param delay_time VOX = 0 detection delay, ~ 128 ms
 * @param interval_time VOX detection interval time
 * @param threshold_on  Voice amplitude threshold for VOX on
 * @param threshold_off Voice amplitude threshold for VOX off
 */
void bk4819_enable_vox(uint8_t delay_time, uint8_t interval_time, uint16_t threshold_on, uint16_t threshold_off);

/**
 * @brief Get VOX indicator
 * 
 * @return uint8_t 
 */
uint8_t bk4819_get_vox(void);

/**
 * @brief Set squelch threshold
 *
 * @param RTSO RSSI threshold for Squelch=1, 0.5dB/step
 * @param RTSC RSSI threshold for Squelch =0, 0.5dB/step
 * @param ETSO Ex-noise threshold for Squelch =1
 * @param ETSC Ex-noise threshold for Squelch =0
 * @param GTSO Glitch threshold for Squelch =1
 * @param GTSC Glitch threshold for Squelch =0
 */
void bk4819_set_Squelch(uint8_t RTSO, uint8_t RTSC, uint8_t ETSO, uint8_t ETSC, uint8_t GTSO, uint8_t GTSC);


/**
 * @brief Get RSSI value 0.5dB/step
 *
 * @return uint8_t
 */
int16_t bk4819_get_rssi(void);

/**
 * @brief Scna frequency
 * 
 * @param scna_time BK4819_SCAN_FRE_TIME_2  0.2s
                    BK4819_SCAN_FRE_TIME_4  0.4s
                    BK4819_SCAN_FRE_TIME_8  0.8s
                    BK4819_SCAN_FRE_TIME_16 1.6s 
 */
void bk4819_enable_freq_scan(uint8_t scna_time);

/**
 * @brief Disable scanning frequcny 
 * 
 */
void bk4819_disable_freq_scan(void);

/**
 * @brief Get scanning freqency flag
 * 
 * @return uint8_t 
 */
uint8_t bk4819_get_scan_freq_flag(void);

/**
 * @brief Get frequency
 * 
 * @return uint32_t 
 */
uint32_t bk4819_get_scan_freq(void);

void bk4819_gpio_pin_set(uint8_t Pin, bool bSet);

enum BK4819_GPIO_PIN_t {
	BK4819_GPIO0_PIN28_RX_ENABLE = 0,
	BK4819_GPIO1_PIN29_PA_ENABLE = 1,
	BK4819_GPIO3_PIN31_UHF_LNA = 3,
	BK4819_GPIO4_PIN32_VHF_LNA = 4,
	BK4819_GPIO5_PIN1_RED = 5,
	BK4819_GPIO6_PIN2_GREEN = 6,
};

typedef enum BK4819_GPIO_PIN_t BK4819_GPIO_PIN_t;

// REG 02

#define BK4819_REG_02_SHIFT_FSK_TX_FINISHED		15
#define BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_EMPTY	14
#define BK4819_REG_02_SHIFT_FSK_RX_FINISHED		13
#define BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_FULL	12
#define BK4819_REG_02_SHIFT_DTMF_5TONE_FOUND		11
#define BK4819_REG_02_SHIFT_CxCSS_TAIL			10
#define BK4819_REG_02_SHIFT_CDCSS_FOUND			9
#define BK4819_REG_02_SHIFT_CDCSS_LOST			8
#define BK4819_REG_02_SHIFT_CTCSS_FOUND			7
#define BK4819_REG_02_SHIFT_CTCSS_LOST			6
#define BK4819_REG_02_SHIFT_VOX_FOUND			5
#define BK4819_REG_02_SHIFT_VOX_LOST			4
#define BK4819_REG_02_SHIFT_SQUELCH_FOUND		3
#define BK4819_REG_02_SHIFT_SQUELCH_LOST		2
#define BK4819_REG_02_SHIFT_FSK_RX_SYNC			1

#define BK4819_REG_02_MASK_FSK_TX_FINISHED		(1U << BK4819_REG_02_SHIFT_FSK_TX)
#define BK4819_REG_02_MASK_FSK_FIFO_ALMOST_EMPTY	(1U << BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_EMPTY)
#define BK4819_REG_02_MASK_FSK_RX_FINISHED		(1U << BK4819_REG_02_SHIFT_FSK_RX_FINISHED)
#define BK4819_REG_02_MASK_FSK_FIFO_ALMOST_FULL		(1U << BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_FULL)
#define BK4819_REG_02_MASK_DTMF_5TONE_FOUND		(1U << BK4819_REG_02_SHIFT_DTMF_5TONE_FOUND)
#define BK4819_REG_02_MASK_CxCSS_TAIL			(1U << BK4819_REG_02_SHIFT_CxCSS_TAIL)
#define BK4819_REG_02_MASK_CDCSS_FOUND			(1U << BK4819_REG_02_SHIFT_CDCSS_FOUND)
#define BK4819_REG_02_MASK_CDCSS_LOST			(1U << BK4819_REG_02_SHIFT_CDCSS_LOST)
#define BK4819_REG_02_MASK_CTCSS_FOUND			(1U << BK4819_REG_02_SHIFT_CTCSS_FOUND)
#define BK4819_REG_02_MASK_CTCSS_LOST			(1U << BK4819_REG_02_SHIFT_CTCSS_LOST)
#define BK4819_REG_02_MASK_VOX_FOUND			(1U << BK4819_REG_02_SHIFT_VOX_FOUND)
#define BK4819_REG_02_MASK_VOX_LOST			(1U << BK4819_REG_02_SHIFT_VOX_LOST)
#define BK4819_REG_02_MASK_SQUELCH_FOUND		(1U << BK4819_REG_02_SHIFT_SQUELCH_FOUND)
#define BK4819_REG_02_MASK_SQUELCH_LOST			(1U << BK4819_REG_02_SHIFT_SQUELCH_LOST)
#define BK4819_REG_02_MASK_FSK_RX_SYNC			(1U << BK4819_REG_02_SHIFT_FSK_RX_SYNC)

#define BK4819_REG_02_FSK_TX_FINISHED			(1U << BK4819_REG_02_SHIFT_FSK_TX_FINISHED)
#define BK4819_REG_02_FSK_FIFO_ALMOST_EMPTY		(1U << BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_EMPTY)
#define BK4819_REG_02_FSK_RX_FINISHED			(1U << BK4819_REG_02_SHIFT_FSK_RX_FINISHED)
#define BK4819_REG_02_FSK_FIFO_ALMOST_FULL		(1U << BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_FULL)
#define BK4819_REG_02_DTMF_5TONE_FOUND			(1U << BK4819_REG_02_SHIFT_DTMF_5TONE_FOUND)
#define BK4819_REG_02_CxCSS_TAIL			(1U << BK4819_REG_02_SHIFT_CxCSS_TAIL)
#define BK4819_REG_02_CDCSS_FOUND			(1U << BK4819_REG_02_SHIFT_CDCSS_FOUND)
#define BK4819_REG_02_CDCSS_LOST			(1U << BK4819_REG_02_SHIFT_CDCSS_LOST)
#define BK4819_REG_02_CTCSS_FOUND			(1U << BK4819_REG_02_SHIFT_CTCSS_FOUND)
#define BK4819_REG_02_CTCSS_LOST			(1U << BK4819_REG_02_SHIFT_CTCSS_LOST)
#define BK4819_REG_02_VOX_FOUND				(1U << BK4819_REG_02_SHIFT_VOX_FOUND)
#define BK4819_REG_02_VOX_LOST				(1U << BK4819_REG_02_SHIFT_VOX_LOST)
#define BK4819_REG_02_SQUELCH_FOUND			(1U << BK4819_REG_02_SHIFT_SQUELCH_FOUND)
#define BK4819_REG_02_SQUELCH_LOST			(1U << BK4819_REG_02_SHIFT_SQUELCH_LOST)
#define BK4819_REG_02_FSK_RX_SYNC			(1U << BK4819_REG_02_SHIFT_FSK_RX_SYNC)

// REG 07

#define BK4819_REG_07_SHIFT_FREQUENCY_MODE	13
#define BK4819_REG_07_SHIFT_FREQUENCY		0

#define BK4819_REG_07_MASK_FREQUENCY_MODE	(0x0007U << BK4819_REG_07_SHIFT_FREQUENCY_MODE)
#define BK4819_REG_07_MASK_FREQUENCY		(0x1FFFU << BK4819_REG_07_SHIFT_FREQUENCY)

#define BK4819_REG_07_MODE_CTC1			(0U << BK4819_REG_07_SHIFT_FREQUENCY_MODE)
#define BK4819_REG_07_MODE_CTC2			(1U << BK4819_REG_07_SHIFT_FREQUENCY_MODE)
#define BK4819_REG_07_MODE_CDCSS		(2U << BK4819_REG_07_SHIFT_FREQUENCY_MODE)

// REG 24

#define BK4819_REG_24_SHIFT_UNKNOWN_15   15
#define BK4819_REG_24_SHIFT_THRESHOLD    7
#define BK4819_REG_24_SHIFT_UNKNOWN_6    6
#define BK4819_REG_24_SHIFT_ENABLE       5
#define BK4819_REG_24_SHIFT_SELECT       4
#define BK4819_REG_24_SHIFT_MAX_SYMBOLS  0

#define BK4819_REG_24_MASK_THRESHOLD     (0x2Fu << BK4819_REG_24_SHIFT_THRESHOLD)
#define BK4819_REG_24_MASK_ENABLE        (0x01u << BK4819_REG_24_SHIFT_ENABLE)
#define BK4819_REG_24_MASK_SELECT        (0x04u << BK4819_REG_24_SHIFT_SELECT)
#define BK4819_REG_24_MASK_MAX_SYMBOLS   (0x0Fu << BK4819_REG_24_SHIFT_MAX_SYMBOLS)

#define BK4819_REG_24_ENABLE             (1u << BK4819_REG_24_SHIFT_ENABLE)
#define BK4819_REG_24_DISABLE            (0u << BK4819_REG_24_SHIFT_ENABLE)
#define BK4819_REG_24_SELECT_DTMF        (1u << BK4819_REG_24_SHIFT_SELECT)
#define BK4819_REG_24_SELECT_SELCALL     (0u << BK4819_REG_24_SHIFT_SELECT)

// REG 30

#define BK4819_REG_30_SHIFT_ENABLE_VCO_CALIB	15
#define BK4819_REG_30_SHIFT_ENABLE_UNKNOWN	14
#define BK4819_REG_30_SHIFT_ENABLE_RX_LINK	10
#define BK4819_REG_30_SHIFT_ENABLE_AF_DAC	9
#define BK4819_REG_30_SHIFT_ENABLE_DISC_MODE	8
#define BK4819_REG_30_SHIFT_ENABLE_PLL_VCO	4
#define BK4819_REG_30_SHIFT_ENABLE_PA_GAIN	3
#define BK4819_REG_30_SHIFT_ENABLE_MIC_ADC	2
#define BK4819_REG_30_SHIFT_ENABLE_TX_DSP	1
#define BK4819_REG_30_SHIFT_ENABLE_RX_DSP	0

#define BK4819_REG_30_MASK_ENABLE_VCO_CALIB	(0x1U << BK4819_REG_30_SHIFT_ENABLE_VCO_CALIB)
#define BK4819_REG_30_MASK_ENABLE_UNKNOWN	(0x1U << BK4819_REG_30_SHIFT_ENABLE_UNKNOWN)
#define BK4819_REG_30_MASK_ENABLE_RX_LINK	(0xFU << BK4819_REG_30_SHIFT_ENABLE_RX_LINK)
#define BK4819_REG_30_MASK_ENABLE_AF_DAC	(0x1U << BK4819_REG_30_SHIFT_ENABLE_AF_DAC)
#define BK4819_REG_30_MASK_ENABLE_DISC_MODE	(0x1U << BK4819_REG_30_SHIFT_ENABLE_DISC_MODE)
#define BK4819_REG_30_MASK_ENABLE_PLL_VCO	(0xFU << BK4819_REG_30_SHIFT_ENABLE_PLL_VCO)
#define BK4819_REG_30_MASK_ENABLE_PA_GAIN	(0x1U << BK4819_REG_30_SHIFT_ENABLE_PA_GAIN)
#define BK4819_REG_30_MASK_ENABLE_MIC_ADC	(0x1U << BK4819_REG_30_SHIFT_ENABLE_MIC_ADC)
#define BK4819_REG_30_MASK_ENABLE_TX_DSP	(0x1U << BK4819_REG_30_SHIFT_ENABLE_TX_DSP)
#define BK4819_REG_30_MASK_ENABLE_RX_DSP	(0x1U << BK4819_REG_30_SHIFT_ENABLE_RX_DSP)

enum {
	BK4819_REG_30_ENABLE_VCO_CALIB		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_VCO_CALIB),
	BK4819_REG_30_DISABLE_VCO_CALIB		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_VCO_CALIB),
	BK4819_REG_30_ENABLE_UNKNOWN		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_UNKNOWN),
	BK4819_REG_30_DISABLE_UNKNOWN		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_UNKNOWN),
	BK4819_REG_30_ENABLE_RX_LINK		= (0xFU << BK4819_REG_30_SHIFT_ENABLE_RX_LINK),
	BK4819_REG_30_DISABLE_RX_LINK		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_RX_LINK),
	BK4819_REG_30_ENABLE_AF_DAC		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_AF_DAC),
	BK4819_REG_30_DISABLE_AF_DAC		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_AF_DAC),
	BK4819_REG_30_ENABLE_DISC_MODE		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_DISC_MODE),
	BK4819_REG_30_DISABLE_DISC_MODE		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_DISC_MODE),
	BK4819_REG_30_ENABLE_PLL_VCO		= (0xFU << BK4819_REG_30_SHIFT_ENABLE_PLL_VCO),
	BK4819_REG_30_DISABLE_PLL_VCO		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_PLL_VCO),
	BK4819_REG_30_ENABLE_PA_GAIN		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_PA_GAIN),
	BK4819_REG_30_DISABLE_PA_GAIN		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_PA_GAIN),
	BK4819_REG_30_ENABLE_MIC_ADC		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_MIC_ADC),
	BK4819_REG_30_DISABLE_MIC_ADC		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_MIC_ADC),
	BK4819_REG_30_ENABLE_TX_DSP		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_TX_DSP),
	BK4819_REG_30_DISABLE_TX_DSP		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_TX_DSP),
	BK4819_REG_30_ENABLE_RX_DSP		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_RX_DSP),
	BK4819_REG_30_DISABLE_RX_DSP		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_RX_DSP),
};

// REG 3F

#define BK4819_REG_3F_SHIFT_FSK_TX_FINISHED		15
#define BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_EMPTY	14
#define BK4819_REG_3F_SHIFT_FSK_RX_FINISHED		13
#define BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_FULL	12
#define BK4819_REG_3F_SHIFT_DTMF_5TONE_FOUND		11
#define BK4819_REG_3F_SHIFT_CxCSS_TAIL			10
#define BK4819_REG_3F_SHIFT_CDCSS_FOUND			9
#define BK4819_REG_3F_SHIFT_CDCSS_LOST			8
#define BK4819_REG_3F_SHIFT_CTCSS_FOUND			7
#define BK4819_REG_3F_SHIFT_CTCSS_LOST			6
#define BK4819_REG_3F_SHIFT_VOX_FOUND			5
#define BK4819_REG_3F_SHIFT_VOX_LOST			4
#define BK4819_REG_3F_SHIFT_SQUELCH_FOUND		3
#define BK4819_REG_3F_SHIFT_SQUELCH_LOST		2
#define BK4819_REG_3F_SHIFT_FSK_RX_SYNC			1

#define BK4819_REG_3F_MASK_FSK_TX_FINISHED		(1U << BK4819_REG_3F_SHIFT_FSK_TX)
#define BK4819_REG_3F_MASK_FSK_FIFO_ALMOST_EMPTY	(1U << BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_EMPTY)
#define BK4819_REG_3F_MASK_FSK_RX_FINISHED		(1U << BK4819_REG_3F_SHIFT_FSK_RX_FINISHED)
#define BK4819_REG_3F_MASK_FSK_FIFO_ALMOST_FULL		(1U << BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_FULL)
#define BK4819_REG_3F_MASK_DTMF_5TONE_FOUND		(1U << BK4819_REG_3F_SHIFT_DTMF_5TONE_FOUND)
#define BK4819_REG_3F_MASK_CxCSS_TAIL			(1U << BK4819_REG_3F_SHIFT_CxCSS_TAIL)
#define BK4819_REG_3F_MASK_CDCSS_FOUND			(1U << BK4819_REG_3F_SHIFT_CDCSS_FOUND)
#define BK4819_REG_3F_MASK_CDCSS_LOST			(1U << BK4819_REG_3F_SHIFT_CDCSS_LOST)
#define BK4819_REG_3F_MASK_CTCSS_FOUND			(1U << BK4819_REG_3F_SHIFT_CTCSS_FOUND)
#define BK4819_REG_3F_MASK_CTCSS_LOST			(1U << BK4819_REG_3F_SHIFT_CTCSS_LOST)
#define BK4819_REG_3F_MASK_VOX_FOUND			(1U << BK4819_REG_3F_SHIFT_VOX_FOUND)
#define BK4819_REG_3F_MASK_VOX_LOST			(1U << BK4819_REG_3F_SHIFT_VOX_LOST)
#define BK4819_REG_3F_MASK_SQUELCH_FOUND		(1U << BK4819_REG_3F_SHIFT_SQUELCH_FOUND)
#define BK4819_REG_3F_MASK_SQUELCH_LOST			(1U << BK4819_REG_3F_SHIFT_SQUELCH_LOST)
#define BK4819_REG_3F_MASK_FSK_RX_SYNC			(1U << BK4819_REG_3F_SHIFT_FSK_RX_SYNC)

#define BK4819_REG_3F_FSK_TX_FINISHED			(1U << BK4819_REG_3F_SHIFT_FSK_TX_FINISHED)
#define BK4819_REG_3F_FSK_FIFO_ALMOST_EMPTY		(1U << BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_EMPTY)
#define BK4819_REG_3F_FSK_RX_FINISHED			(1U << BK4819_REG_3F_SHIFT_FSK_RX_FINISHED)
#define BK4819_REG_3F_FSK_FIFO_ALMOST_FULL		(1U << BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_FULL)
#define BK4819_REG_3F_DTMF_5TONE_FOUND			(1U << BK4819_REG_3F_SHIFT_DTMF_5TONE_FOUND)
#define BK4819_REG_3F_CxCSS_TAIL			(1U << BK4819_REG_3F_SHIFT_CxCSS_TAIL)
#define BK4819_REG_3F_CDCSS_FOUND			(1U << BK4819_REG_3F_SHIFT_CDCSS_FOUND)
#define BK4819_REG_3F_CDCSS_LOST			(1U << BK4819_REG_3F_SHIFT_CDCSS_LOST)
#define BK4819_REG_3F_CTCSS_FOUND			(1U << BK4819_REG_3F_SHIFT_CTCSS_FOUND)
#define BK4819_REG_3F_CTCSS_LOST			(1U << BK4819_REG_3F_SHIFT_CTCSS_LOST)
#define BK4819_REG_3F_VOX_FOUND				(1U << BK4819_REG_3F_SHIFT_VOX_FOUND)
#define BK4819_REG_3F_VOX_LOST				(1U << BK4819_REG_3F_SHIFT_VOX_LOST)
#define BK4819_REG_3F_SQUELCH_FOUND			(1U << BK4819_REG_3F_SHIFT_SQUELCH_FOUND)
#define BK4819_REG_3F_SQUELCH_LOST			(1U << BK4819_REG_3F_SHIFT_SQUELCH_LOST)
#define BK4819_REG_3F_FSK_RX_SYNC			(1U << BK4819_REG_3F_SHIFT_FSK_RX_SYNC)

// REG 51

#define BK4819_REG_51_SHIFT_ENABLE_CxCSS        15
#define BK4819_REG_51_SHIFT_GPIO6_PIN2_INPUT    14
#define BK4819_REG_51_SHIFT_TX_CDCSS_POLARITY   13
#define BK4819_REG_51_SHIFT_CxCSS_MODE          12
#define BK4819_REG_51_SHIFT_CDCSS_BIT_WIDTH     11
#define BK4819_REG_51_SHIFT_1050HZ_DETECTION    10
#define BK4819_REG_51_SHIFT_AUTO_CDCSS_BW       9
#define BK4819_REG_51_SHIFT_AUTO_CTCSS_BW       8
#define BK4819_REG_51_SHIFT_CxCSS_TX_GAIN1      0

#define BK4819_REG_51_MASK_ENABLE_CxCSS        (0x01U << BK4819_REG_51_SHIFT_ENABLE_CxCSS)
#define BK4819_REG_51_MASK_GPIO6_PIN2_INPUT    (0x01U << BK4819_REG_51_SHIFT_GPIO6_PIN2_INPUT)
#define BK4819_REG_51_MASK_TX_CDCSS_POLARITY   (0x01U << BK4819_REG_51_SHIFT_TX_CDCSS_POLARITY)
#define BK4819_REG_51_MASK_CxCSS_MODE          (0x01U << BK4819_REG_51_SHIFT_CxCSS_MODE)
#define BK4819_REG_51_MASK_CDCSS_BIT_WIDTH     (0x01U << BK4819_REG_51_SHIFT_CDCSS_BIT_WIDTH)
#define BK4819_REG_51_MASK_1050HZ_DETECTION    (0x01U << BK4819_REG_51_SHIFT_1050HZ_DETECTION)
#define BK4819_REG_51_MASK_AUTO_CDCSS_BW       (0x01U << BK4819_REG_51_SHIFT_AUTO_CDCSS_BW)
#define BK4819_REG_51_MASK_AUTO_CTCSS_BW       (0x01U << BK4819_REG_51_SHIFT_AUTO_CTCSS_BW)
#define BK4819_REG_51_MASK_CxCSS_TX_GAIN1      (0x7FU << BK4819_REG_51_SHIFT_CxCSS_TX_GAIN1)

enum {
	BK4819_REG_51_ENABLE_CxCSS          = (1U << BK4819_REG_51_SHIFT_ENABLE_CxCSS),
	BK4819_REG_51_DISABLE_CxCSS         = (0U << BK4819_REG_51_SHIFT_ENABLE_CxCSS),

	BK4819_REG_51_GPIO6_PIN2_INPUT      = (1U << BK4819_REG_51_SHIFT_GPIO6_PIN2_INPUT),
	BK4819_REG_51_GPIO6_PIN2_NORMAL     = (0U << BK4819_REG_51_SHIFT_GPIO6_PIN2_INPUT),

	BK4819_REG_51_TX_CDCSS_NEGATIVE     = (1U << BK4819_REG_51_SHIFT_TX_CDCSS_POLARITY),
	BK4819_REG_51_TX_CDCSS_POSITIVE     = (0U << BK4819_REG_51_SHIFT_TX_CDCSS_POLARITY),

	BK4819_REG_51_MODE_CTCSS            = (1U << BK4819_REG_51_SHIFT_CxCSS_MODE),
	BK4819_REG_51_MODE_CDCSS            = (0U << BK4819_REG_51_SHIFT_CxCSS_MODE),

	BK4819_REG_51_CDCSS_24_BIT          = (1U << BK4819_REG_51_SHIFT_CDCSS_BIT_WIDTH),
	BK4819_REG_51_CDCSS_23_BIT          = (0U << BK4819_REG_51_SHIFT_CDCSS_BIT_WIDTH),

	BK4819_REG_51_1050HZ_DETECTION      = (1U << BK4819_REG_51_SHIFT_1050HZ_DETECTION),
	BK4819_REG_51_1050HZ_NO_DETECTION   = (0U << BK4819_REG_51_SHIFT_1050HZ_DETECTION),

	BK4819_REG_51_AUTO_CDCSS_BW_DISABLE = (1U << BK4819_REG_51_SHIFT_AUTO_CDCSS_BW),
	BK4819_REG_51_AUTO_CDCSS_BW_ENABLE  = (0U << BK4819_REG_51_SHIFT_AUTO_CDCSS_BW),

	BK4819_REG_51_AUTO_CTCSS_BW_DISABLE = (1U << BK4819_REG_51_SHIFT_AUTO_CTCSS_BW),
	BK4819_REG_51_AUTO_CTCSS_BW_ENABLE  = (0U << BK4819_REG_51_SHIFT_AUTO_CTCSS_BW),
};

// REG 70

#define BK4819_REG_70_SHIFT_ENABLE_TONE1	15
#define BK4819_REG_70_SHIFT_TONE1_TUNING_GAIN	8
#define BK4819_REG_70_SHIFT_ENABLE_TONE2	7
#define BK4819_REG_70_SHIFT_TONE2_TUNING_GAIN	0

#define BK4819_REG_70_MASK_ENABLE_TONE1		(0x01U << BK4819_REG_70_SHIFT_ENABLE_TONE1)
#define BK4819_REG_70_MASK_TONE1_TUNING_GAIN	(0x7FU << BK4819_REG_70_SHIFT_TONE1_TUNING_GAIN)
#define BK4819_REG_70_MASK_ENABLE_TONE2		(0x01U << BK4819_REG_70_SHIFT_ENABLE_TONE2)
#define BK4819_REG_70_MASK_TONE2_TUNING_GAIN	(0x7FU << BK4819_REG_70_SHIFT_TONE2_TUNING_GAIN)

enum {
	BK4819_REG_70_ENABLE_TONE1		= (1U << BK4819_REG_70_SHIFT_ENABLE_TONE1),
	BK4819_REG_70_ENABLE_TONE2		= (1U << BK4819_REG_70_SHIFT_ENABLE_TONE2),
};

#endif

#ifdef __cplusplus
}
#endif
