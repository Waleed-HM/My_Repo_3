/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define led_red			LD5_Pin
#define led_red_gpio	LD5_GPIO_Port
#define led_green		LD4_Pin
#define led_green_gpio	LD4_GPIO_Port
#define led_blue		LD2_Pin
#define led_blue_gpio	LD2_GPIO_Port
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
#define DWT_CTRL	(*(volatile uint32_t*)0xE0001000)		// DWT_CTRL register
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
static void led_red_handler(void*);
static void led_green_handler(void*);
static void led_blue_handler(void*);

extern void SEGGER_UART_init(uint32_t);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  TaskHandle_t led_blue_task;
  TaskHandle_t led_green_task;
  TaskHandle_t led_red_task;
  BaseType_t status;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  // SEGGER UART recording
  SEGGER_UART_init(500000);

  // Enable the CYCCNT register by setting the 0th bit
  // This is to allow the SEGGER systemview to record time stamps of events
  DWT_CTRL |= (1<<0);


  // Configure and start the SEGGER systemview recording
  SEGGER_SYSVIEW_Conf();
  //SEGGER_SYSVIEW_Start();

  // Create the FreeRTOS leds toggling tasks
  status = xTaskCreate(led_red_handler, "LED_red_task", 200, NULL, 2, &led_red_task);
  configASSERT(status == pdPASS);
  status = xTaskCreate(led_green_handler, "LED_green_task", 200, NULL, 2, &led_green_task);
  configASSERT(status == pdPASS);
  status = xTaskCreate(led_blue_handler, "LED_blue_task", 200, NULL, 2, &led_blue_task);
  configASSERT(status == pdPASS);

  // Start the FreeRTOS scheduler
  vTaskStartScheduler();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV8;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV8;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, BUCKBOOST_LOAD_1_Pin|BUCKBOOST_LOAD_2_Pin|BUCKBOOST_USBPD_EN_Pin|USBPD_1A_PROTECT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD3_Pin|LD5_Pin|LD4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USBPD_550mA_PROTECT_GPIO_Port, USBPD_550mA_PROTECT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : JOYSTICK_SEL_Pin JOYSTICK_LEFT_Pin JOYSTICK_DOWN_Pin */
  GPIO_InitStruct.Pin = JOYSTICK_SEL_Pin|JOYSTICK_LEFT_Pin|JOYSTICK_DOWN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : BUCKBOOST_LOAD_1_Pin BUCKBOOST_LOAD_2_Pin BUCKBOOST_USBPD_EN_Pin USBPD_1A_PROTECT_Pin */
  GPIO_InitStruct.Pin = BUCKBOOST_LOAD_1_Pin|BUCKBOOST_LOAD_2_Pin|BUCKBOOST_USBPD_EN_Pin|USBPD_1A_PROTECT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : USBPD_VIN_Pin */
  GPIO_InitStruct.Pin = USBPD_VIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USBPD_VIN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BUCK_GREEN_SENSE_Pin BUCKBOOST_VIN_Pin BUCKBOOST_I_IN_AVG_Pin BUCKBOOST_VOUT_Pin
                           BUCK_RED_SENSE_Pin */
  GPIO_InitStruct.Pin = BUCK_GREEN_SENSE_Pin|BUCKBOOST_VIN_Pin|BUCKBOOST_I_IN_AVG_Pin|BUCKBOOST_VOUT_Pin
                          |BUCK_RED_SENSE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BUCK_BLUE_SENSE_Pin BUCKBOOST_I_IN_SENSE_Pin PB4 PB6 */
  GPIO_InitStruct.Pin = BUCK_BLUE_SENSE_Pin|BUCKBOOST_I_IN_SENSE_Pin|GPIO_PIN_4|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LD3_Pin LD5_Pin LD4_Pin */
  GPIO_InitStruct.Pin = LD3_Pin|LD5_Pin|LD4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : JOYSTICK_RIGHT_Pin JOYSTICK_UP_Pin */
  GPIO_InitStruct.Pin = JOYSTICK_RIGHT_Pin|JOYSTICK_UP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BUCKBOOST_P1_DRIVE_Pin BUCKBOOST_N1_DRIVE_Pin BUCKBOOST_N2_DRIVE_Pin BUCKBOOST_P2_DRIVE_Pin */
  GPIO_InitStruct.Pin = BUCKBOOST_P1_DRIVE_Pin|BUCKBOOST_N1_DRIVE_Pin|BUCKBOOST_N2_DRIVE_Pin|BUCKBOOST_P2_DRIVE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF13_HRTIM1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BUCK_RED_DRIVE_Pin RC_TP4_Pin */
  GPIO_InitStruct.Pin = BUCK_RED_DRIVE_Pin|RC_TP4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF13_HRTIM1;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : BUCK_GREEN_DRIVE_Pin */
  GPIO_InitStruct.Pin = BUCK_GREEN_DRIVE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF3_HRTIM1;
  HAL_GPIO_Init(BUCK_GREEN_DRIVE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BUCK_BLUE_DRIVE_Pin */
  GPIO_InitStruct.Pin = BUCK_BLUE_DRIVE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF13_HRTIM1;
  HAL_GPIO_Init(BUCK_BLUE_DRIVE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : USART3_TX_Pin USART3_RX_Pin */
  GPIO_InitStruct.Pin = USART3_TX_Pin|USART3_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : USBPD_550mA_PROTECT_Pin */
  GPIO_InitStruct.Pin = USBPD_550mA_PROTECT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USBPD_550mA_PROTECT_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */
static void led_red_handler(void* parameters)
{
	while(1)
	{
		SEGGER_SYSVIEW_PrintfTarget("Toggling red LED");
		HAL_GPIO_TogglePin(led_red_gpio, led_red);
		//vTaskDelay(1000);
		HAL_Delay(1000);
	}
}

static void led_green_handler(void* parameters)
{
	while(1)
	{
		SEGGER_SYSVIEW_PrintfTarget("Toggling green LED");
		HAL_GPIO_TogglePin(led_green_gpio, led_green);
		//vTaskDelay(800);
		HAL_Delay(800);
	}
}

static void led_blue_handler(void* parameters)
{
	while(1)
	{
		SEGGER_SYSVIEW_PrintfTarget("Toggling blue LED");
		HAL_GPIO_TogglePin(led_blue_gpio, led_blue);
		//vTaskDelay(400);
		HAL_Delay(400);
	}
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
