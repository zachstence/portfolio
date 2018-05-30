<style>
  table {
    border-collapse: collapse;
  }

  td {
    width: 30px;
    height: 30px;
    border: 1px solid black;
    text-align: center;
  }

  td a {
    display: block;
    text-decoration: none;
    color: black;
  }
</style>  

<?php
  function makeTable($max, $numPerTable, $numPerRow) {
    $numTables = ceil($max / $numPerTable);
    $numRows = $numPerTable / $numPerRow;
    
    for ($t = 0; $t < $numTables; $t++) {
      echo "<table>";
      for ($r = 0; $r < $numRows; $r++) {
        echo "<tr>";
        for ($c = 0; $c < $numPerRow; $c++) {
          if ($val >= $max) return;
          $val = (($t * $numPerTable) + ($r * $numPerRow) + ($c + 1));
          echo "<td><a href=?problem=" . $val . ">" . $val . "</a></td>";
        }
        echo "</tr>";
      }
      echo "</table>";
      echo "<br>";
    }
  }


  makeTable(616, 100, 20);




?>
