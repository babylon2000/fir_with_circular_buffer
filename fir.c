#include <iostream>
#include <cstdint>

short int filter(short int input);

short int taps = 4;
short int coefficients[4] = {1, 2, 3, 4};
short int samples[3] = {0, 1, 2};
short int buffer[4];
short int offset = 0;


int main()
{
    printf("%d\n", filter(samples[0]));
    printf("%d\n", filter(samples[1]));
    printf("%d\n", filter(samples[2]));
    printf("%d\n", filter(0));
    printf("%d\n", filter(0));
    printf("%d\n", filter(0));
    return 0;
}

short int filter(short int input)
{
	short int *coeff     = coefficients;
	short int *coeff_end = coefficients + taps;

	short int *buf_val = buffer + offset;

	*buf_val = input;
	int output_ = 0;
	
	while(buf_val >= buffer)
		output_ += *buf_val-- * *coeff++;
	
	buf_val = buffer + taps-1;
	
	while(coeff < coeff_end)
		output_ += *buf_val-- * *coeff++;
	
	if(++offset >= taps)
		offset = 0;
	
	return output_;
}