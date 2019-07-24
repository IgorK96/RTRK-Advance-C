
#include "imageProcessing.h"
#include "bmp.h"

static const uint_least8_t bwTreshold = 80;
const int_least16_t brightnessMinimum = 20;
const int_least16_t brightnessMaximum = 220;


void adjustImageBrightness(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight,
		bool brighten, uint_least8_t adjustmentValue)
{
	uint_least32_t i;
	int_least16_t newValue;

	for (i=0; i<iWidth*iHeight*3; i++)
	{
		newValue = iData[i];
		if(brighten)
		{
			newValue += adjustmentValue;
		}
		else
		{
			newValue -= adjustmentValue;
		}

		if(newValue < brightnessMinimum)
		{
			newValue = brightnessMinimum;
		}
		else if(newValue > brightnessMaximum)
		{
			newValue = brightnessMaximum;
		}

		iData[i] = newValue;
	}
}

void bwImage(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight)
{
	int_least32_t i;
	int_least32_t j;
	int_least32_t k;

	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			uint_least16_t sum = 0;
			for (k=0; k<3; k++)
			{
				sum += iData[i * iWidth * 3 + j * 3 + k];
			}
			sum = sum / 3;

			sum = (sum > bwTreshold)? 255 : 0;

			for (k=0; k<3; k++)
			{
				iData[i * iWidth * 3 + j * 3 + k] = sum;
			}
		}
	}
}

void effect(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight)
{
	int_least32_t i;
	int_least32_t j;
	uint_least8_t* ptr = iData;

	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			if(*ptr > *(ptr+1) && *ptr > *(ptr+2))
			{
				*ptr = 255;
				ptr++;
				*ptr = 0;
				ptr++;
				*ptr = 0;
				ptr++;
			}
			else
			{
				*ptr = 0;
				ptr++;
				if(*ptr > *(ptr+1))
				{
					*ptr = 255;
					ptr++;
					*ptr = 0;
					ptr++;
				}
				else
				{
					*ptr = 0;
					ptr++;
					*ptr = 255;
					ptr++;
				}
			}
		}
	}
}



void effect_srd(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight)
{	int_least32_t R_sr = 0;
	int_least32_t G_sr = 0;
	int_least32_t B_sr = 0;
	int_least32_t i;
	int_least32_t j;
	uint_least8_t* ptr = iData;

	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			R_sr += *ptr;
			ptr++;

			G_sr += *ptr;
			ptr++;

			B_sr += *ptr;
			ptr++;


		}
	}

	R_sr = R_sr / (j *i);
	G_sr = G_sr / (j *i);
	B_sr = B_sr / (j *i);

	printf("Srednja vrednost Crvene: ");
	printf("%"PRIdLEAST32,R_sr);
	printf(" ");
	printf("Srednja vrednost Zelene: ");
	printf("%" PRIdLEAST32,G_sr);
	printf(" ");
	printf("Srednja vrednost Plave: ");
	printf("%"PRIdLEAST32,B_sr);
	printf(" ");
}

void effect_Mean(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight){

	int_least32_t Pixels[iWidth][iHeight][3];


	int_least32_t R_FIN[iWidth][iHeight];
	int_least32_t G_FIN[iWidth][iHeight];
	int_least32_t B_FIN[iWidth][iHeight];
	int_least32_t R_AVG[iWidth][iHeight];
	int_least32_t G_AVG[iWidth][iHeight];
	int_least32_t B_AVG[iWidth][iHeight];

	int_least32_t i;
	int_least32_t j;
	int_least32_t k;
	uint_least8_t* ptr = iData;

	for (i=0; i<iHeight; i++)
	{

		for (j=0; j<iWidth; j++)
		{
			R_FIN[i][j] = *ptr;
			ptr++;

			G_FIN[i][j] = *ptr;
			ptr++;

			B_FIN[i][j] = *ptr;
			ptr++;

		}
	}

	for (i=1; i<iHeight-1; i++)
	{

		for (j=1; j<iWidth-1; j++)
		{
			{
				R_AVG[i][j] = (R_FIN[i-1][j-1]+R_FIN[i-1][j]+R_FIN[i-1][j+1]+R_FIN[i][j-1]+R_FIN[i][j]+R_FIN[i][j+1]+R_FIN[i+1][j-1]+R_FIN[i+1][j]+R_FIN[i+1][j+1]) / 9;
				G_AVG[i][j] = (G_FIN[i-1][j-1]+G_FIN[i-1][j]+G_FIN[i-1][j+1]+G_FIN[i][j-1]+G_FIN[i][j]+G_FIN[i][j+1]+G_FIN[i+1][j-1]+G_FIN[i+1][j]+G_FIN[i+1][j+1]) / 9;
				B_AVG[i][j] = (B_FIN[i-1][j-1]+B_FIN[i-1][j]+B_FIN[i-1][j+1]+B_FIN[i][j-1]+B_FIN[i][j]+B_FIN[i][j+1]+B_FIN[i+1][j-1]+B_FIN[i+1][j]+B_FIN[i+1][j+1]) / 9;
				for(k = 0; k<3; k++){
					if(k == 0)
					{
						Pixels[i][j][k] = R_AVG[i][j];
					}
					if(k == 1)
					{
						Pixels[i][j][k] = G_AVG[i][j];
					}
					else
						Pixels[i][j][k] = B_AVG[i][j];

				}
			}
		}
	}
	for (i=1; i<iHeight-1; i++)
		{

			for (j=1; j<iWidth-1; j++)
			{
				for (k=0; k<3; k++)
				{
					iData[i * iWidth * 3 + j * 3 + k] = Pixels[i][j][k] ;
				}
			}
		}
}
