Клеточный автомат/Cellular automaton
==================
<h6><i>Ru:</i></h6>
Клеточный автомат с окрестностью Мура, условия - L/A/C:
<ul>
  <li><b>L</b> - набор цифр от 0 до 8, определяет число "живых" соседей, при котором клетка остается "в живых";</li>
  <li><b>A</b> - набор цифр от 0 до 8, определяет число "живых" соседей при котором "мертвая" клетка становится "живой";</li>
  <li><b>C</b> - число, определяет число ходов "умирания" клетки.</li>
</ul>

Например — 23/12/5:
<ul>
  <li>клетка "живет", когда у нее 2 или 3 "живых" соседа;</li>
  <li>клетка становится "живой", когда у нее 1 или 2 "живых" соседа;</li>
  <li>клетка умирает за 5 шагов (таким образом, живая-1-2-3-4-5-мертвая).</li>
</ul>
Два режима:
<ul>
  <li>черно-белый;</li>
  <li>градиентный.</li>
</ul>
<i><b>Примечание:</b></i> 
<ul>
  <li>если у клетки недостаточно соседей (равных L), она начинает "умирать". И клетка уже не может стать "живой", пока не станет "мертвой";</li>
  <li>"умирающая" клетка <b>НЕ</b> "живая" клетка.</li>
</ul>

Лучше всего использовать сетку 60х60.<br> 
Несколько примеров (ссылки на видео): 
<br> <a href="http://www.youtube.com/watch?v=YT14LIYJ3nM"> bugs_23_2_8.txt (L = 23, A = 2, C = 8) </a>, 
<br> <a href="http://www.youtube.com/watch?v=43-kxhowO-k"> fire_2_2_25.txt (L = 23, A = 2, C = 25) </a>, 
<br> <a href="http://www.youtube.com/watch?v=YGZkp0rDffw"> flame_235678_3468_9.txt (L = 235678, A = 3468, C = 9) </a>.

<h6><i>En:</i></h6>
Cellular automaton with Moore neighborhood, conditions - L/A/C:
<ul>
  <li><b>L</b> - numbers from 0 to 8, determine the number of "live" neighbors, when the cell stays "alive";</li>
  <li><b>A</b> - numbers from 0 to 8, determine the number of "live" neighbors, when "dead" cell becomes "live";</li>
  <li><b>C</b> - number determines the number of moves "dying" cells.</li>
</ul>
For example 23/12/5:
<ul>
  <li>cell "lives", when it has 2 or 3 "live" neighbors;</li>
  <li>cell becomes "alive", when it has 1 or 2 "live" neighbors;</li>
  <li>cell "dies" in 5 steps (this way: live-1-2-3-4-5-dead).</li>
</ul>
Two modes:
<ul>
  <li>black-and-white;</li>
  <li>gradient.</li>
</ul>
<i><b>Note:</b></i> 
<ul>
  <li>if cell doesn't have enough neighbors (equal to L), it starts "dying". And cell can't be "alive", until it becomes "dead";</li>
  <li>"dying" cell <b>IS NOT</b> "live" cell.</li>
</ul>

It is better to use grid 60x60.<br> 
Few examples (click to the link to watch video):
<br> <a href="http://www.youtube.com/watch?v=YT14LIYJ3nM"> bugs_23_2_8.txt (L = 23, A = 2, C = 8) </a>, 
<br> <a href="http://www.youtube.com/watch?v=43-kxhowO-k"> fire_2_2_25.txt (L = 23, A = 2, C = 25) </a>, 
<br> <a href="http://www.youtube.com/watch?v=YGZkp0rDffw"> flame_235678_3468_9.txt (L = 235678, A = 3468, C = 9) </a>.
