<?php
  
  function makeTable($max, $numPerTable, $numPerRow) {
    $solved_problems = scandir("./problems");
    foreach ($solved_problems as $p) {
      $p = (int)$p;
    }
    
    $numTables = ceil($max / $numPerTable);
    $numRows = $numPerTable / $numPerRow;
    
    for ($t = 0; $t < $numTables; $t++) {
      echo "<table>";
      for ($r = 0; $r < $numRows; $r++) {
        echo "<tr align=\"left\">";
        for ($c = 0; $c < $numPerRow; $c++) {
          $problem = (($t * $numPerTable) + ($r * $numPerRow) + ($c + 1));

          $solved = in_array($problem, $solved_problems);
          if ($solved) echo "<td class=\"solved\">";
          else echo "<td class=\"unsolved\">";
          echo "<a href=?problem=" . $problem . ">" . $problem . "</a></td>";
          
          if ($problem >= $max) return;
        }
        echo "</tr>";
      }
      echo "</table>";
      echo "<br>";
    }
  }
?>
