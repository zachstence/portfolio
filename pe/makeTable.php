<?php
  
  function makeTable($max, $numPerTable, $numPerRow) {
    $dir = scandir("./problems");
    $solved_problems = array();
    $pending_problems = array();
    foreach ($dir as $d) {
      if ($d[0] == '_') $pending_problems[] = (int)substr($d, 1);
      else $solved_problems[] = (int)$d; 
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
          $pending = in_array($problem, $pending_problems);
          
          if ($solved) echo "<td class=\"solved\"><a href=?problem=" . $problem . ">" . $problem . "</a></td>";
          else if ($pending) echo "<td class=\"pending\"><a href=\"https://projecteuler.net/problem=" . $problem . "\" target=\"_blank\">" . $problem . "</td>";
          else echo "<td class=\"unsolved\"><a href=\"https://projecteuler.net/problem=" . $problem . "\" target=\"_blank\">" . $problem . "</td>";
          
          if ($problem >= $max) return;
        }
        echo "</tr>";
      }
      echo "</table>";
      echo "<br>";
    }
  }
?>
