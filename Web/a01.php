<table width="90%" border="3" cellspacing="7" cellpadding="5">
  <tr>
    <td>卡號</td>
    <td>筆數</td>
  </tr>
 <?php
 for($i=1; $i <100; $i++)
 {
  echo "<tr>" ;
    echo "<td>" ;
	echo $i ;
	echo "</td>" ;
    echo "<td>" ;
	echo $i+2000 ;
	echo "</td>" ;
  echo "</tr>" ;
 }
  ?>
</table>
