#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
void LED_Blink(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, float frequency)
{
    uint32_t delay_ms;
    delay_ms = (uint32_t)(1000.0f / (2.0f * frequency));
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
    vTaskDelay(pdMS_TO_TICKS(delay_ms));
}

void LED1_Task(void *argument)
{
    for (;;)
    {
        LED_Blink(GPIOA, GPIO_PIN_0, 0.1f);
    }
}

void LED2_Task(void *argument)
{
    for (;;)
    {
        LED_Blink(GPIOA, GPIO_PIN_1, 1.0f);
    }
}

void LED3_Task(void *argument)
{
    for (;;)
    {
        LED_Blink(GPIOA, GPIO_PIN_2, 10.0f);
    }
}




