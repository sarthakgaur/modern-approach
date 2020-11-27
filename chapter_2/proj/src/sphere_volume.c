#include <stdio.h>
#define VOL_FORMULA (4.0f / 3.0f * 3.14159f)

int main(void)
{
    float sr;
    printf("Enter the radius of sphere(meter): ");
    scanf("%f", &sr);

    float vol = VOL_FORMULA * sr * sr *sr;
    printf("Volume of sphere of radius 10: %.2f\n", vol);

    return 0;
}
