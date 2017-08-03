<?php

  class myclass
  {
    public $operation = '';
    function __construct($post)
    {
      if (isset($post)) $this->operation = $_POST['operation'];
    }

    private
    function login()
    {
      echo 'login';
    }

    public
    function run()
    {
      if (count($_POST) == 0) $this->login();
      else
      {
        switch($_POST['operation'])
        {
          case 'signup' : $this->signup(); break;
        }
      }
    }
  }

?>
