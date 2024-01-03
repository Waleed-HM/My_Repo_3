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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* USER CODE BEGIN PV */
#define DWT_CTRL (*(volatile uint32_t*) 0xE0001000)		// Bit 0 in this register can enable/disable the DWT_CYCCNT register

QueueHandle_t xQueue;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */
void vTaskLedBlue(void *pvParameters);
void vTaskLedGreen(void *pvParameters);
void vTaskSendQueue(void *pvParameters);
void vTaskReceiveQueue(void *pvParameters);
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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  // Create a 10 element 32bit queue
  xQueue = xQueueCreate(10, sizeof(uint32_t));
  if (xQueue == NULL)
  {
	  // Queue created failed ! Transmit a message on the UART
	  char queue_error_msg[] = "Error during Queue creation !";
	  HAL_UART_Transmit(&huart2, (uint8_t*)queue_error_msg, strlen(queue_error_msg), 1000);
  }
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  //defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  // Enable the DWT_CYCCNT register (the cycle counter, to enable SEGGER time stamps)
  DWT_CTRL |= (1 << 0);

  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();

  /* add threads, ... */
  // Blue LED task
  if((xTaskCreate(vTaskLedBlue, "Task LED Blue", configMINIMAL_STACK_SIZE, NULL, 1, NULL)) != pdTRUE)
  {
	  // Task Creation failed
	  char task1_error_msg[] = "Error during Blue LED task creation !";
	  HAL_UART_Transmit(&huart2, (uint8_t*)task1_error_msg, strlen(task1_error_msg), 1000);
  }

  // Green LED task
  if((xTaskCreate(vTaskLedGreen, "Task LED Green", configMINIMAL_STACK_SIZE, NULL, 1, NULL)) != pdTRUE)
  {
	  // Task Creation failed
	  char task2_error_msg[] = "Error during Green LED task creation !";
	  HAL_UART_Transmit(&huart2, (uint8_t*)task2_error_msg, strlen(task2_error_msg), 1000);
  }

  // Create a task to send the queue
  if((xTaskCreate(vTaskSendQueue, "Task Send Queue", configMINIMAL_STACK_SIZE, NULL, 1, NULL)) != pdTRUE)
  {
	  // Task Creation failed
	  char queue_send_task_error_msg[] = "Error during queue send task creation !";
	  HAL_UART_Transmit(&huart2, (uint8_t*)queue_send_task_error_msg, strlen(queue_send_task_error_msg), 1000);
  }

  // Create a task to receive the queue
  if((xTaskCreate(vTaskReceiveQueue, "Task Receive Queue", configMINIMAL_STACK_SIZE, NULL, 1, NULL)) != pdTRUE)
  {
	  // Task Creation failed
	  char queue_receive_task_error_msg[] = "Error during queue receive task creation !";
	  HAL_UART_Transmit(&huart2, (uint8_t*)queue_receive_task_error_msg, strlen(queue_receive_task_error_msg), 1000);
  }
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 75;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart2, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart2, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_Blue_GPIO_Port, LED_Blue_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_Green_GPIO_Port, LED_Green_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Blue_Pin */
  GPIO_InitStruct.Pin = LED_Blue_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_Blue_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_Green_Pin */
  GPIO_InitStruct.Pin = LED_Green_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_Green_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void vTaskLedBlue(void *pvParameters)
{
	//Variable Declarations

	//Infinite Loop
	for(;;)
	{
		HAL_GPIO_TogglePin(LED_Blue_GPIO_Port, LED_Blue_Pin);
		vTaskDelay(100 / portTICK_PERIOD_MS);
	}

	//Delete the task if the loop is broken
	vTaskDelete(NULL);
}

void vTaskLedGreen(void *pvParameters)
{
	//Variable Declarations

	//Infinite Loop
	for(;;)
	{
		HAL_GPIO_TogglePin(LED_Green_GPIO_Port, LED_Green_Pin);
		vTaskDelay(50 / portTICK_PERIOD_MS);
	}

	//Delete the task if the loop is broken
	vTaskDelete(NULL);
}

void vTaskSendQueue(void *pvParameters)
{
	//Variable Declarations
	uint32_t counterSend = 0;
	char txText[50];

	//Infinite Loop
	for(;;)
	{
		// If the queue is full, wait until the queue becomes free
		// Careful that if the queue never free up, the task will wait forever
		// NOTE : using portMAX_DELAY will make it sit there and wait for space to empty up in the queue
		// If we don't want that, we need to use another value
		//if((xQueueSend(xQueue, &counterSend, portMAX_DELAY)) == pdPASS)
		if((xQueueSend(xQueue, &counterSend, 10 / portTICK_PERIOD_MS)) == pdPASS)
		{
			sprintf(txText, "Queue Send, value: %ld \n", counterSend);
			//taskENTER_CRITICAL();
			vTaskSuspendAll();			// Temporary measure, suspends all other tasks to prevent them from using the resource (USART)
			HAL_UART_Transmit(&huart2, (uint8_t*)txText, strlen(txText), 1000);
			//taskEXIT_CRITICAL();
			xTaskResumeAll();
			counterSend++;
		}
		else
		{
			vTaskSuspendAll();
			sprintf(txText, "Queue is full !\n");
			HAL_UART_Transmit(&huart2, (uint8_t*)txText, strlen(txText), 1000);
			xTaskResumeAll();
		}

		vTaskDelay(100 / portTICK_PERIOD_MS);
	}

	//Delete the task if the loop is broken
	vTaskDelete(NULL);
}

void vTaskReceiveQueue(void *pvParameters)
{
	//Variable Declarations
	uint32_t counterReceive = 0;
	char txText[50];

	//Infinite Loop
	for(;;)
	{
		// Wait until the queue receives some value
		if((xQueueReceive(xQueue, &counterReceive, portMAX_DELAY)) == pdPASS)
		{
			sprintf(txText, "Queue Receive, value: %ld \n", counterReceive);
			//taskENTER_CRITICAL();
			vTaskSuspendAll();			// Temporary measure, suspends all other tasks to prevent them from using the resource (USART)
			HAL_UART_Transmit(&huart2, (uint8_t*)txText, strlen(txText), 1000);
			//taskEXIT_CRITICAL();
			xTaskResumeAll();
		}

		vTaskDelay(20 / portTICK_PERIOD_MS);
	}

	//Delete the task if the loop is broken
	vTaskDelete(NULL);
}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

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
