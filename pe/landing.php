<!DOCTYPE html>
<html>
  <head>
    <title>Project Euler </title>
    <meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="../style/pe_landing.css">
  </head>
  
  <?php include "../head.php"; ?>
  <?php include "../nav.php"; ?>

  <body>

    <div class="main">
      
      <img src="https://www.projecteuler.net/profiles/zachstence.png" alt="ProjectEuler badge" style="width: 15rem">
      <div class="intro">
        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec dolor augue, consectetur fringilla lacus quis, vestibulum congue turpis. Donec justo arcu, pellentesque in arcu sed, facilisis iaculis purus. Cras mattis sem leo, id ultrices metus aliquet ut. In aliquet faucibus libero. Maecenas euismod convallis purus sit amet bibendum. Suspendisse potenti. Pellentesque dui dui, dictum sed felis quis, sollicitudin maximus lectus. Mauris consectetur ex eros, sit amet rutrum tortor consequat ac. Proin semper, diam in suscipit feugiat, leo libero scelerisque lectus, ut scelerisque massa leo vel nisl. Proin egestas sit amet augue at maximus.</p>
      </div>
      
      <div id="tables">
        <table class="key">
          <tbody>
            <tr>
              <td class="solved">#</td>
              <td>Solved</td>
            </tr>
            <tr>
              <td class="pending">#</td>
              <td>Pending</td>
            </tr>
            <tr>
              <td class="unsolved">#</td>
              <td>Unsolved</td>
            </tr>
          </tbody>
        </table>
        <?php include "makeTable.php"; makeTable(627, 100, 20); ?>
      </div>
      
    </div>

  </body>

</html>
