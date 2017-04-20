/* this header file contains wave header information as a struct
 * it also contains necesarry constant definitions,and function
 * prototypes used in this project*/

typedef struct{
	char ChunkID[4];
	int ChunkSize;
	char Format[4];
	char Subchunk1ID[4];
	int Subchunk1Size;
	short int AudioFormat;
	short int NumChannels;
	int SampleRate;
	int ByteRate;
	short int BlockAlign;
	short int BitsPerSample;
	char Subchunk2ID[4];
	int Subchunk2Size;
}WAVHDR;
//#define DEBUG 1
#define SAMPLE_RATE 16000
#define PI 3.1415926

void displayWAVHDR(WAVHDR hdr);
void printID(char *);
void fillID(const char *s,char id[] );
void testTone(int freq, double d);
void displayWAVdata(short intd[]);
