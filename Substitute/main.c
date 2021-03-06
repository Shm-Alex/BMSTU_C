#include <stdio.h>
#define MAX(a,b) ((a)>(b))?(a):(b)
#define ABS(x) ((x)<0 ? (-x) : (x))


//  процедура считывает буквы  в  буфер buff
// Не больше maxStrLength символов, память для буфера должна быть
// выделена заранее размером в  maxStrLength байт
void ReadStr (char *buff,int maxStrLength)
{
	printf("Input string using keybord not long than symbols %d,finish input by enter ",maxStrLength);
	char ch=getchar();
	int index=0;
	while (ch!='\n'&&index<maxStrLength)
		{
			buff[index]=ch;
			index++;
			ch=getchar();
		};
	for(int i= index;i<maxStrLength;i++) buff[i]=0;
}
int strLen(char *inputStr){
int len=0;
while(inputStr[len++]!=0);
return len;
}
void copyChars(char *inputStr,char *outputStr)
    {
        for(int len=0;inputStr[len]!=0;len++ )outputStr[len]=inputStr[len];
    }
int lastCharPosition(char *inputStr,char ch)
{
    int ret=strLen(inputStr);
    while(inputStr[ret]!=ch&&ret>0)ret--;
    return ret;
};
int charPosition(char *inputStr,char ch)
{
    int len=strLen(inputStr);
    int ret=0;
    while(inputStr[ret]!=ch&&ret<len)ret++;
    return ret;
};
int substitute(char *inputStr,char *outputStr)
{ int count = 0;
    if(strLen(inputStr)<=strLen("--"))
        { outputStr =
                    (char *) malloc(sizeof(char)*strLen(inputStr));
         copyChars(inputStr,outputStr);
        }else
        {
         int substitutionPosition=charPosition(&inputStr[1],'-')// '-' в начале строки не заменяем
         +1;// позиция '-' в строке не учитывая первый символ
         printf("substitutionPosition %d \n",substitutionPosition);

         // если абсолютная позиция '-' в строке не учитывая первый символ самый последний  тоже выходим из прцедуры скопировав в  выходную строку  все символы
         if (substitutionPosition>strLen(inputStr)-1)
            {
//                 outputStr =
//                    (char *) malloc(sizeof(char)*strLen(inputStr));
                copyChars(inputStr,outputStr);
                return 0;

            }
            else
                {
                    char leftChar=inputStr[substitutionPosition-1];
                    printf("leftChar %c \n",leftChar);
                    printf("leftChar %d \n",leftChar);
                    printf("leftCharPos %d \n",substitutionPosition-1);
                    char rightChar=inputStr[substitutionPosition+1];
                    printf("rightChar %c \n",rightChar);
                    printf("rightChar %d \n",rightChar);
                    printf("rightCharPos %d \n",substitutionPosition+1);
                    int incrementor=(leftChar<rightChar)?1:-1;
                    printf("incrementor %d \n",incrementor);

                    int substitutionLength=((int)leftChar-(int)rightChar);
                    substitutionLength=(substitutionLength<0)?-substitutionLength:substitutionLength;
                    printf("substitutionLength %d \n",substitutionLength);
                    int outputStrLength=substitutionLength +strLen(inputStr)-strLen("a-f");
                    printf("outputStrLength %d \n",outputStrLength);

//                    //char * str
//                    outputStr = (char *) malloc (//выделяем память
//                                     (outputStrLength) // размером строка подстановки + размер исходной строки
//                                      * sizeof (char));
                    int i=0,j=0,k = (int)leftChar;
                   for(;i<outputStrLength;i++ )
                    {
                        printf("copy string i= %d,j=%d,k=%c  \n",i,j,k);
                        if(i<substitutionPosition-1)
                             {
                                 printf("copy base str to output str outputStr[i=%d]=inputStr[j=%d] %d ; \n ",i,j,inputStr[j]);
                                 outputStr[i]=inputStr[j];
                                 j++;
                             }
                             else
                                if(i>substitutionPosition+substitutionLength+1)
                             {
                                 outputStr[i]=inputStr[j+2];
                                 j++;
                             }
                             else
                             {


                                outputStr[i]=(char)k;
                                printf("copy chars to output str outputStr[i %d]=(char)%c  \n",i,outputStr[i]);
                                k+=incrementor;
                                printf("new value of char %d \n",k);
                             }
                    }
                   outputStr[i] =0;//оставим строку нуль-терминированной
                }

        }
    return count;
    }
#define MaxBufLength 255
int main() {

    char buff[MaxBufLength];
    char buff1[MaxBufLength*16];//заранее в аутпут строку выделим 4К памяти чтоб голова качалась!
    ReadStr(buff,MaxBufLength);
	printf("%s\n",buff);
	//printf("Hello world!");
	printf("length string is %d\n",strLen(buff));





	substitute(buff,buff1);
	printf("fist iteration of substitotion result %s\n",buff1);
	char ch=getchar();
	return 0;
}
