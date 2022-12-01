%{
Z
inestable = <0
oscilador = 0
sub = 0 - 1
critam = 1
sobre = >1

%}
%Funcion de transferencia
gp = tf([1] , [1 2 2])

%Polos
pzmap(gp)
grid on 

%Grafica de la salida cuando se alimenta un escalon de amplitud 4
step(4*gp)


gp = tf( [1], [1 8 16] )
step(gp)










