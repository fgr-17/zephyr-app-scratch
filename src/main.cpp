#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>


#define LED0_NODE DT_ALIAS(led0)
#if !DT_NODE_HAS_STATUS(LED0_NODE, okay)
#error "Unsupported board: led0 device tree alias is not defined"
#endif

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
    printk("Zephyr from scratch example app - iomico zephyr course\n");
    printk("author: rouxfederico@gmail.com\n");

    printk("Board: %s\n", CONFIG_BOARD);

    if (!device_is_ready(led.port)) {
        printk("device is not ready\n");
        return 1;
    }

    gpio_pin_configure_dt(&led, GPIO_OUTPUT);

    while (1) {
        gpio_pin_toggle_dt(&led);
        k_msleep(500);  // Blink every 500ms
    }
    return 0;
}