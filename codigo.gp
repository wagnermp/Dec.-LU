set title "Gráfico de número de operações"
set xlabel "Dim da matriz"
set ylabel "Núm de operações"
f(x) = a*(x**3) + b
fit f(x) "operacoes.dat" using 1:2 via a,b
plot f(x), "op.dat" 
