<?php
  if (isset($_GET["assignment"])) {
    include "./cs2308_assignment.php";
  } else {
    include "./cs2308_landing.php";
  }
?>
