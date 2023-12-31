set terminal wxt size 1000,1000 enhanced font 'Verdana,10' persist
set view equal xyz
set xlabel 'x'
set ylabel 'y'
set zlabel 'z'
set autoscale x
set autoscale y
set autoscale z
set xyplane 0

set style line 1 linewidth 1.0 linecolor rgb "#000080"
set style line 2 pointtype 7 pointsize 1.5 linecolor rgb "#000000"
set style line 3 linewidth 3.5 linecolor rgb "#FF4500"

splot "rays.dat" with lines ls 1 notitle, \
      "rays.dat" every ::0::0 with points ls 2 notitle, \
      "components.dat" with lines ls 3 notitle
pause -1