syms s
ft = tf([1] , [0.00003, 1])
step(ft) 
grid on;

ft = tf([1] , [0.00003, 1])
impulse(ft) 
grid on
