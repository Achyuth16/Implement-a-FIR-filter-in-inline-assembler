//TASK2-1
#include <stdio.h>
#include <stdlib.h>
#include<vector.h>

float myFIR(float insample, float * state, const float * coeff, const int length) 
{
	
int m; 
float output[16],sum=0;
for(m=0;m<16;m++)
{
	asm("%0=%1;"
	    :"=f1"(state[m])    
	    :"f2"(state[m+1])
	    );
}

asm("%0=%1;"
    :"=f1"(state[15])
    :"f1"(insample)         
);

for(m=0;m<16;m++)
{
	printf("%d. The updated state vector is %f\n",m,state[m]);
}
printf("------------------------------------\n");

for(m=0;m<16;m++)
{
	
asm("%0 = %1 * %2;"
   :"=f1"(output[m])    
   :"f2"(coeff[m]),"f3"(state[16-1-m])
);
printf("%d The filter output is  is %f\n",m,output[m]);
}
printf("------------------------------------\n");
for(m=0;m<16;m++)
{
asm (
      "%0= %1 + %2;" 
      : "=f0" (sum) 
      : "f1" (sum),"f2" (output[m])
   );



}

printf("The final result is %f\n", sum);

   return sum;
}
main()
{
	const int length=16;
	const float coeff[16]={9.169500,2.414431,-0.989030,-0.989030,1.029552,-0.127435,-0.103945 ,2.601139,2.865498,-0.659966,4.947494,0.520257 ,0.076193 ,0.479921,-0.290526 ,-0.174857 };
	float state[16]={1.4897,1.4090,1.4172,0.6715,-1.2075,0.7172,1.6302,0.4889,1.0347,0.7269,-0.3034,0.2939,-0.7873,0.8884,-1.1471,-1.0689};
	float insample=5;
	myFIR(insample ,state,coeff,length);
}
