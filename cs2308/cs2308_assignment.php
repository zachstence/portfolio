<!DOCTYPE html>
<html>
  <head>
    <?php echo "<title>CS2308 - Assignment " . $_GET["assignment"] . "</title>\n"; ?>
    <meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="../style/cs2308.css">
    <script src="../style/highlight/highlight.pack.js"></script>
    <script>hljs.initHighlightingOnLoad();</script>
  </head>
  
  <?php include "../head.php"; ?>
  <?php include "../nav.php"; ?>

  <body>
    <div class="main">
    <?php
      $json = file_get_contents("./PA_info.json");
      $pa_info = json_decode($json);

      $param = $_GET["assignment"];
      $assignmentNum = (int)$param;

      $dir = "./PAs/PA" . $assignmentNum . "/";
      $pdf = $dir . "assign" . $assignmentNum . ".pdf";
      $desc = $pa_info->$assignmentNum->desc;
      $code = $dir . "assign" . $assignmentNum . "_zms22.cpp";
      $out = $dir . "assign" . $assignmentNum . "_out.txt";

      echo "<div class=\"boxed\">"; 

      echo "<h2>Programming Assignment " . $assignmentNum . ": " . $pa_info->$assignmentNum->name . "</h2>";
      echo "<p>" . $desc . "</p>";

      echo "<div class=\"left_half\" style=\"overflow: scroll; height: 40rem\">";
      echo "<h4>Code</h4><a href=\"" . $code . "\">" . "assign" . $assignmentNum . "_zms22.cpp" . "</a>";
      echo "<pre><code class=\"c++\" style=\"overflow-x: unset; width: 800px;\">" . htmlspecialchars(file_get_contents($code)) . 
        "</code></pre>";
      echo "</div>";

      echo "<div class=\"right_half\" style=\"overflow: scroll; height: 40rem\">";
      echo "<h4>Output</h4><a href=\"" . $out . "\">" . "assign" . $assignmentNum . "_out.cpp" . "</a>";
      echo "<pre>" . file_get_contents($out) . "</pre>";
      echo "</div>";
    ?>
    </div>
  </body>

</html>
