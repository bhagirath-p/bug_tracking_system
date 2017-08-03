<?php
  class dbFunctions
  {
    protected $connection = null;
 
    function doconnection()
    {
      $username         = "root";
      $password         = "root";
      $this->connection = mysql_connect("localhost",$username,$password);
      mysql_select_db('bug_tracking_system',$this->connection);
    }

    function doquery($statement)
    {
      $res =  mysql_query($statement);
      return $res;
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
