<?php
 $connection=mysql_connect("localhost","root","general");
 mysql_select_db('bug_tracking_system',$connection);
 $statement  = sprintf("SELECT * FROM bug_info");
      $result     =mysql_query("SELECT * FROM bug_info");
      printf("<html>");
      printf("<body>");
      printf("<table align = centre>");
      printf("<tr>");
      printf("<td>Id</td><td>Name</td><td>Address</td><td>Phone</td><td>DOB</td>");
      while ($get_info = mysql_fetch_row($result))
      {
        print_r($get_info);
        printf("<tr size = 14px align = centre>\n");
        foreach ($get_info as $field)
        {
          printf("\t<td><font face=arial size=1/>$field</font></td>\n");
        }
        printf("</tr></br>");
      }

?>
