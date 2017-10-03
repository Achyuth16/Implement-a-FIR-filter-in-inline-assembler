%Fir implementation reference by values imported from Dsp C program.
%Here new insample is '5' placed in last position in state vector.
coeff=load('coeff.txt');
state=load('Task1_1.txt');
y=filter(coeff,1,state);
fprintf('The filterd output is\t %f\n',y(end));