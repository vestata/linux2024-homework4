reset
set title "log(x) Perfomence"
set xlabel "x"
set ylabel "time(ns)"
set xtics 100000
set xtics rotate by -45
set xtics font "Times_New Roman,10"
set terminal png font " Times_New_Roman,12 "
set output "log2_1000000_2.png"

plot \
"out_ilog2.txt" using 1:(($2 < 200) ? $2 : 1/0) with linespoints linewidth 2 title "ilog2", \
"out_ilog2_2.txt" using 1:(($2 < 200) ? $2 : 1/0) with linespoints linewidth 2 title "ilog2_2", \
"out_ilog32.txt" using 1:(($2 < 200) ? $2 : 1/0) with linespoints linewidth 2 title "ilog32"