<?php

  require_once("../inc/base.inc");
  class application extends dbFunctions
  {
    private $operation = '';
    public function __construct($post,$get)
    {
      $this->doconnection(); 
      if (isset($get['operation'])) 
      {
        $this->operation = $get['operation'];
      }
      else if (isset($post['operation']))
      {
        $this->operation = $post['operation'];
      }
    }
  
    function getscript()
    {
      printf("<script src='/js/bugs.js'> </script>");
      printf("<script src='/js/dovalidation.js'> </script>");
      printf("<script src='/js/doCreateUserSql.js'></script>");
    }
    function loginpage()
    {
      printf("<html>");
      printf("<body>");
      printf("<h1 align='center'>BUG TRACKING SYSTEM</h1>");
      printf("<form action='index.php' method='post' >");
      printf("<table align = 'center'>");
      printf("<tr>");
      printf("<td>Login Name</td>");
      printf("<td><input type='text' size=20 name='loginName' /></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Password</td>");
      printf("<td><input type='password' size=20 name='passwd' /></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td><input type='submit' name='operation' value='login' /></td>");
      printf("</tr>");
      printf("</table>");
      printf("</form>");
      printf("</body>");
      printf("</html>");
    }

    function createuser()
    {
      printf("<html>");
      printf("<head>");
      printf("</head>");
      printf("<body>");
      printf("<h3 align='center'>New user creation page</h3>");
      printf("<form name='form' align='center' action='index.php' method='get' />");
      printf("<table align='center'>");
      printf("<tr>Account Type</tr>");
      printf("<tr>");
      printf("<td><input type='radio' name='accountType' value='General'>General</>");
      printf("<td><input type='radio' name='accountType' value='Admin'>Admin</>");
      printf("</tr>");
      printf("<tr>");
      printf("<td></td>");
      printf("<td><input type='password' name='adminPassword'>Password for admin</></td>");
      printf("</td>");
      printf("<tr>");
      printf("<td>Name</td>");
      printf("<td><input type='text' name='name' /></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>User Name</td>");
      printf("<td><input type='text' name='userName' /></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Password</td>");
      printf("<td><input type='password' name='password' /></td>");
      printf("</tr>");
      printf("</table>");
      printf("<input type='submit' name='operation' value='createuser' />");
      printf("<input type='submit' name='cancel' value='cancel' onclick='index.php' /input>");
      printf("</form>");
      printf("</body>");
      printf("</html>");
    }
 
    function createbug()
    {
      printf("<html>");
      printf("<head>");
      printf("</head>");
      printf("<body>");
      printf("<h3 align='center'>NEW BUG CREATION</h3>");
      printf("<form align='center' action='index.php' method='post'>");
      printf("<table align='center'>");
      printf("<tr>");
      printf("<td>Bug ID</td>");
      printf("<td><input type='text' name='bugid' id='bugid' />(Enter a unique number)</td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Bug Name</td>");
      printf("<td><input type='text' name='bugname' id='bugname'/></td>");
      printf("</tr>");
      printf("<td>Project Name</td>");
      printf("<td><input type='text' name='projectname' id='projectname'/></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Bug</br>Description</td>");
      printf("<td><textarea name='bugdescription' id='bugdescription' cols='40' rows='5'></textarea></td>");
      printf("</tr>");
      printf("<td>Comments</td>");
      printf("<td><textarea name='comment' id='comment' cols='40' rows='5'></textarea></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Status</td>");
      printf("<td><select name='status' id='status'>");
      printf("<option value='closed'>closed</option>");
      printf("<option value='open'>Open</option>");
      printf("</td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Priority</td>");
      printf("<td><select name='priority' id='priority'>");
      printf("<option value='low'>Low</option>");
      printf("<option value='meduim'>Medium</option>");
      printf("<option value='high'>High</option>");
      printf("<option value='very_high'>Very High</option>");
      printf("</select>");
      printf("</td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Assigned to</td>");
      printf("<td><input type='text' name='assignedto'  id='assignedto' /></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td></td>");
      printf("<td><input type='submit' name='operation' value='insertbug'/></td>");
      printf("<td><a href='index.php?operation=listbugs' >List Bugs</a>");
      printf("</tr>");
      printf("</table>");
      printf("</form>");
      printf("</table>");
      printf("</body>");
      printf("</html>");
    }
    
    function editbugs()
    {
      $bugid          = $_GET['id'];
      $result         = $this->doquery("select bug_name,priority,project_name,bug_description,comments,status,assigned_to from bug_info where bug_id = $bugid;");
      $row            = mysql_fetch_array($result, MYSQL_ASSOC);
      $bid            = $row['bug_id'];
      $bugname        = $row['bug_name'];
      $projectname    = $row['project_name'];
      $bugdescription = $row['bug_description'];
      $comment        = $row['comments'];
      $assignedto     = $row['assigned_to'];
      printf("<html>");
      printf("<head>");
      printf("</head>");
      printf("<body>");
      printf("<h3 align='center'>NEW BUG CREATION</h3>");
      printf("<a href=index.php?operation=dodelete&id=$bugid >Delete this bug</a>");
      printf("<form align='center' action='index.php' method='post'>");
      printf("<table align='center'>");
      printf("<tr>");
      printf("<td>Bug ID</td>");
      printf("<td><input type='text' name='bugid' id='bugid' value=$bugid /></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Bug Name</td>");
      printf("<td><input type='text' name='bugname' id='bugname' value=$bugname /></td>");
      printf("</tr>");
      printf("<td>Project Name</td>");
      printf("<td><input type='text' name='projectname' id='projectname' value=$projectname /></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Bug</br>Description</td>");
      printf("<td><textarea name='bugdescription' id='bugdescription' cols='40' rows='5' >$bugdescription </textarea></td>");
      printf("</tr>");
      printf("<td>Comments</td>");
      printf("<td><textarea name='comment' id='comment' cols='40' rows='5' >$comment </textarea></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Status</td>");
      printf("<td><select name='status' id='status'>");
      printf("<option value='closed'>closed</option>");
      printf("<option value='open'>Open</option>");
      printf("</td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Priority</td>");
      printf("<td><select name='priority' id='priority'>");
      printf("<option value='low'>Low</option>");
      printf("<option value='meduim'>Medium</option>");
      printf("<option value='high'>High</option>");
      printf("<option value='very_high'>Very High</option>");
      printf("</select>");
      printf("</td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td>Assigned to</td>");
      printf("<td><input type='text' name='assignedto'  id='assignedto' value=$assignedto/></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td></td>");
      printf("<td><input type='submit' name='operation' value='dbeditbug'/></td>");
      printf("<td><a href='index.php?operation=listbugs' >List Bugs</a>");
      printf("</tr>");
      printf("</table>");
      printf("</form>");
      printf("</table>");
      printf("</body>");
      printf("</html>");
    }
   
    function deletebugpage()
    {
      printf("<html>");
      printf("<head>");
      printf("</head>");
      printf("<body>");
      printf("<form action='index.php' method='get'>");
      printf("<table align='center' >");
      printf("<tr>");
      printf("<td>Enter Bug ID</td>");
      printf("<td><input type='text' name='bugid' id='bugid' /></td>");
      printf("</tr>");
      printf("<tr>");
      printf("<td><input type='submit' value='dodelete' /></td>");
      printf("</tr>");
      printf("</table>");
    }
    
    function dologin()
    {
      $userid      = $_POST['loginName'];
      $password    = $_POST['passwd'];
      $statement   = sprintf("SELECT user_name,password FROM user_info where user_name = '%s' and password = '%s'",$userid,$password);
      $result = $this->doquery($statement);
      $row            = mysql_fetch_array($result, MYSQL_ASSOC);
      if( count($row)>0 && $row['user_name'] == $userid && $row['password'] == $password )
      { 
        session_register();
        session_start();
        $_SESSION['cookie1'] = $userid;
        $_SESSION['cookie2'] = md5($password);
        setcookie('cookie1', $_SESSION['cookie1'], false, "/");
        setcookie('cookie2', $_SESSION['cookie2'], false, "/");
        $this->dolistbugs(); 
      }
      else
      {
        printf("Invalid user or password");
      }
    }
  
    function dologout()
    {
      if (ini_get("session.use_cookies"))
      {
        $params = session_get_cookie_params();
        setcookie(session_name(), '', time() - 42000);
        setcookie('cookie1', '', time() - 4200);
        setcookie('cookie2', '', time() - 4200);
        $this->loginpage();
      }
    }

    public 
    function run()
    {
      if ($_POST['operation'] == 'login')
          $this->dologin();       
      else if(isset($_COOKIE['cookie2']))
      { 
        switch ($this->operation)
        {
          case 'createuser':
               $this->createuser(); 
               break;
          case 'newuser':
               $this->donewuser($_POST);
                break;
          case 'createbug':
               $this->createbug();
               break;
          case 'deletebug':
               $this->deletebugpage();
               break;
          case 'insertbug':
               $this->donewbug($_POST);
               break;
          case 'listbugs':
               $this->dolistbugs();
               break;
          case 'editbugs':
               $this->editbugs();
               break;
          case 'dodelete':
               $this->dodeletebug();
               break;
          case 'logout':
               $this->dologout();
               break;
          case 'dbeditbug':
               $this->doeditbug();
               break;
         }
      }
      else
      {
         $this->loginpage();
      }
    }
    
    function doeditbug()
    {
      $bugid          = $_POST['bugid'];
      $bugname        = $_POST['bugname'];
      $priority       = $_POST['priority'];
      $projectname    = $_POST['projectname'];
      $bugdescription = $_POST['bugdescription'];
      $comment        = $_POST['comment'];
      $status         = $_POST['status'];
      $assignedto     = $_POST['assignedto'];
      $statement      = sprintf("UPDATE bug_info SET  bug_name='$bugname' ,priority = '$priority', bug_description='$bugdescription', comments='$comment', status='$status', assigned_to='$assignedto' where bug_id = $bugid");
      $this->doquery($statement);
      $this->dolistbugs();
    }

    function dolistbugs()
    {
      $statement  = sprintf("SELECT * FROM bug_info;");
      $result     = $this->doquery($statement);
      printf("<html>");
      printf("<body>");
      printf("<h3 align='center'>BUG LIST PAGE</h3>");
      printf("</table>");
      printf("<table align='center'>");
      printf("<tr>");
      printf("<td><a href='index.php?operation=createbug' align='center'>Create Bug</a></td>");
      printf("<td></td>");
      printf("<td><a href=index.php?operation=logout >Log out</a></td>");
      printf("</table>");
      printf("<table border='1' align ='center'>");
      printf("<tr>");
      printf("<td>Bug ID</td><td>Bug Name</td><td>Priority</td><td>Project Name</td><td>Description</td><td>Comment</td><td>Status</td><td>Assigned To</td>"); 
      printf("</tr>");
      while ($get_info = mysql_fetch_assoc($result))
      {
        printf("<tr>");
        foreach ($get_info as $field => $value)
        { 
          if($field == 'bug_id')
          {
            printf("<td><a href='index.php?operation=editbugs&id=$value' >$value</a></td>");
          }
          else
          {
            printf("<td>$value</td>");
          }
        }
        printf("</tr>"); 
      }
      printf("</body>");
      printf("</html>");
    }
    
    function dodeletebug()
    {
      $id        =  $_GET['id'];
      $statement = sprintf("DELETE FROM bug_info WHERE bug_id = $id");
      $this->doquery($statement);
      echo $statement;
      $this->dolistbugs();
    }
    
    function donewbug($bugarray)
    {
      $bugid          = $bugarray['bugid'];
      $bugname        = $bugarray['bugname'];
      $priority       = $bugarray['priority'];
      $projectname    = $bugarray['projectname'];
      $bugdescription = $bugarray['bugdescription'];
      $comment        = $bugarray['comment'];
      $status         = $bugarray['status'];
      $assignedto     = $bugarray['assignedto'];
      $statement = sprintf("INSERT INTO bug_info VALUES(%s,'%s','%s','%s','%s','%s','%s','%s');"
                           ,$bugid,$bugname,$priority,$projectname,$bugdescription,$comment,$status,$assignedto);
      $this->doquery($statement);
      $this->dolistbugs();
    }

    function donewuser()
    {
      $date      = new DateTime();
      $userid    = $_POST['userid'];
      $username  = $_POST['username'];
      $password  = $_POST['password'];
      $acc_type  = $_POST['acc_type'];
      $created   = $date->getTimestamp();
      $statement = sprintf("INSERT INTO user_info VALUES(%s,%s,%s,%s,%s);",$userId,$userName,$password,$acc_type,$created);
      $this->doquery($statement);
    }
  }
?>
