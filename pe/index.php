<?php
  if (isset($_GET["problem"])) {
    include "./problem.php";
  } else {
    include "./landing.php";
  }
?>
