/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin nano (STM32F130VET6) board pin assignments
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#elif HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS Robin nano supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "MKS Robin nano"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_DEBUG

//
// EEPROM
//
#if NO_EEPROM_SELECTED
  //#define FLASH_EEPROM_EMULATION
  #define SDCARD_EEPROM_EMULATION
#endif

// Note: MKS Robin board is using SPI2 interface.
//
//#define SPI_MODULE 2
#define ENABLE_SPI2

//
// Limit Switches
//
#define X_STOP_PIN                          PA15
#define Y_STOP_PIN                          PA12
//#define Z_MIN_PIN                           PA11 // Z MIN
#define Z_MIN_PIN                           PE6   // MT_DET2 for BLTOUCH
#define Z_MAX_PIN                           PC4

#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PA4   // MT_DET
#endif

//
// Steppers
//
#define X_ENABLE_PIN                        PE4
#define X_STEP_PIN                          PE3
#define X_DIR_PIN                           PE2

#define Y_ENABLE_PIN                        PE1
#define Y_STEP_PIN                          PE0
#define Y_DIR_PIN                           PB9

#define Z_ENABLE_PIN                        PA3 // Switched pins with E1 for proper G34 alignment
#define Z_STEP_PIN                          PA6
#define Z_DIR_PIN                           PA1

#define E0_ENABLE_PIN                       PB3
#define E0_STEP_PIN                         PD6
#define E0_DIR_PIN                          PD3

#define E1_ENABLE_PIN                       PB8
#define E1_STEP_PIN                         PB5
#define E1_DIR_PIN                          PB4

#if HAS_TMC220x
  /* *
  * TMC2208/TMC2209 stepper drivers
  *
  * Hardware serial communication ports.
  * If undefined software serial is used according to the pins below
  */
  // #define X_HARDWARE_SERIAL Serial1
  // #define Y_HARDWARE_SERIAL Serial1
  // #define Z_HARDWARE_SERIAL Serial1
  // #define E0_HARDWARE_SERIAL Serial1
  // #define E1_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //

  #ifndef X_SERIAL_TX_PIN
      #define X_SERIAL_TX_PIN PA5 // E1_STEP_PIN
  #endif
  #ifndef X_SERIAL_RX_PIN
      #define X_SERIAL_RX_PIN PA5 // E1_DIR_PIN
  #endif

  #ifndef Y_SERIAL_TX_PIN
      #define Y_SERIAL_TX_PIN PA10 // E1_STEP_PIN
  #endif
  #ifndef Y_SERIAL_RX_PIN
  #define Y_SERIAL_RX_PIN PA10 // E1_DIR_PIN
  #endif

  #ifndef Z_SERIAL_TX_PIN
      #define Z_SERIAL_TX_PIN PA9 // E1_STEP_PIN
  #endif
  #ifndef Z_SERIAL_RX_PIN
      #define Z_SERIAL_RX_PIN PA9 // E1_DIR_PIN
  #endif

  #ifndef E0_SERIAL_TX_PIN
      #define E0_SERIAL_TX_PIN PC7 // E1_STEP_PIN
  #endif
  #ifndef E0_SERIAL_RX_PIN
      #define E0_SERIAL_RX_PIN PC7 // E1_DIR_PIN
  #endif
 #ifndef Z2_SERIAL_TX_PIN
      #define Z2_SERIAL_TX_PIN PC13 // E1_STEP_PIN
  #endif
  #ifndef Z2_SERIAL_RX_PIN
      #define Z2_SERIAL_RX_PIN PC13 // E1_DIR_PIN
  #endif

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE 19200
#endif // TMC2208 || TMC2209

//
// Temperature Sensors
//
#define TEMP_0_PIN                          PC1   // TH1
#define TEMP_1_PIN                          PC2   // TH2
#define TEMP_BED_PIN                        PC0   // TB1

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PC3   // HEATER1
#define HEATER_1_PIN                        PB0   // HEATER2
#define HEATER_BED_PIN                      PA0   // HOT BED

#define FAN_PIN                             PB1   // FAN

//
// Servos
//
#define SERVO0_PIN                          PA8   // For BLTOUCH

//
// Thermocouples
//
//#define MAX6675_SS_PIN                    PE5   // TC1 - CS1
//#define MAX6675_SS_PIN                    PE6   // TC2 - CS2

//
// Misc. Functions
//
#define POWER_LOSS_PIN                      PA2   // PW_DET
#define PS_ON_PIN                           PA3   // PW_OFF
#define SUICIDE_PIN PB2     // Enable MKSPWC support ROBIN NANO v1.2 ONLY
#define KILL_PIN PA2     // Enable MKSPWC support ROBIN NANO v1.2 ONLY
#define KILL_PIN_INVERTING false     // Enable MKSPWC support ROBIN NANO v1.2 ONLY

//#define LED_PIN                             PB2

//
// SD Card
//
#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION              ONBOARD
#endif

#define SDIO_SUPPORT
#define SD_DETECT_PIN                       PD12
#define ONBOARD_SD_CS_PIN                   PC11

//
// LCD / Controller
//
#define BEEPER_PIN                          PC5

/**
 * Note: MKS Robin TFT screens use various TFT controllers.
 * If the screen stays white, disable 'LCD_RESET_PIN'
 * to let the bootloader init the screen.
 */
#if ENABLED(FSMC_GRAPHICAL_TFT)
  //@
  //#define DOGLCD_MOSI -1 // prevent redefine Conditionals_post.h
  //#define DOGLCD_SCK -1

  #define FSMC_CS_PIN        PD7    // NE4
  #define FSMC_RS_PIN        PD11   // A0

  #define LCD_USE_DMA_FSMC //
  #define FSMC_DMA_DEV DMA2
  #define FSMC_DMA_CHANNEL DMA_CH5

  //#define LCD_RESET_PIN      PF6
  //#define NO_LCD_REINIT             // Suppress LCD re-initialization

  #define LCD_BACKLIGHT_PIN                 PD13

  #if ENABLED(TOUCH_BUTTONS)
    #define TOUCH_CS_PIN                    PA7   // SPI2_NSS
    #define TOUCH_SCK_PIN                   PB13  // SPI2_SCK
    #define TOUCH_MISO_PIN                  PB14  // SPI2_MISO
    #define TOUCH_MOSI_PIN                  PB15  // SPI2_MOSI
  #endif
#endif

#define SPI_FLASH
#if ENABLED(SPI_FLASH)
	#define 	W25QXX_CS_PIN		PB12
	#define 	W25QXX_MOSI_PIN		PB15
	#define 	W25QXX_MISO_PIN		PB14
	#define 	W25QXX_SCK_PIN		PB13
#endif