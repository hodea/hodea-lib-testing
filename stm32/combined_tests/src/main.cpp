
#include <hodea/device/stm32/stm32_setup.hpp>

volatile int cnt = 0;

int main()
{
    for (;;)
        cnt++;
    return 0;
}
